
#include "./myhead.h"
#include "./sql.h"
////////////////////////////////////////////////////////////////////////////////////
//全局变量
extern user_t head;
extern int socketfd;				//TCP
extern struct sockaddr_in server_addr,client_addr;	//TCP
extern socklen_t sockaddr_len;  //sockaddr_in 
//函数声明
void init_TCP();
void init_database();
void handle_request(int action, int fd, msg_t *msg, user_t head,user_t new_node);
void handle_reg(msg_t *msg,int fd);
void handle_log(msg_t *msg,int fd, user_t new_node);
void handle_fri(msg_t *msg, int fd, user_t head);
void handle_send(msg_t *msg, user_t head);
void handle_all(msg_t *msg, user_t head);
////////////////////////////////////////////////////////////////////////////////////

void sys_error(char *errstr)
{
	fprintf(stderr,"%s error:%s\n\a",errstr,strerror(errno));
	exit(1);
}

int rand_id()
{
	//
}

//主函数
int main()
{
/*声明与定义*/
	int i;
	int ret; //事件个数
	struct epoll_event ev, all[EV_MAX];//epoll监听事件
	

	//初始化链表
	init_link(&head);

	//初始化TCP
	init_TCP();

	//初始化数据库
	init_database();

//epoll_create:创建epoll树的根节点:告诉内核要监听的文件描述符个数
	int epfd = epoll_create(EV_MAX);

///epoll_ctl:注册socketfd到epfd
	ev.events = EPOLLIN;	//监听可读事件
	ev.data.fd = socketfd;	//监听的文件描述符
	if((epoll_ctl(epfd,EPOLL_CTL_ADD,socketfd,&ev)) == -1)
	{
		sys_error("epoll_ctl");
	}

	
	while(1)
	{
//阻塞监听
		if((ret = epoll_wait(epfd, all, sizeof(all)/sizeof(all[0]), -1)) == -1)
		{
			sys_error("epoll_wait");
		}

		//ret
		for(i = 0; i < ret; i++)
		{
			int fd = all[i].data.fd;

//是否是新连接
			if(fd == socketfd)
			{
				int cfd;
				if((cfd = accept(socketfd,(struct sockaddr*)(&client_addr),&sockaddr_len)) == -1)
				{
					sys_error("accept");
				}

				//把新的连接挂到树上
				struct epoll_event tmp;
				tmp.events = EPOLLIN;
				tmp.data.fd = cfd;
				if((epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &tmp)) == -1)
				{
					sys_error("(挂新cfd)epoll_ctl");
				}

				//打印新的连接信息
				printf("新的客户端连接 PORT[%d] IP[%s] \n",ntohs(client_addr.sin_port),inet_ntoa(client_addr.sin_addr));
			}

//已连接的客户端有数据请求
			else
			{
				//不是EPOLLIN事件：不做处理
				if(!all[i].events & EPOLLIN)
				{
					continue;
				}

				int len;
				msg_t *msg = (msg_t *)malloc(sizeof(msg_t));
				memset(msg, 0, sizeof(msg_t));
				if((len = recv(fd, msg, sizeof(msg_t), 0)) == -1)
				{
					sys_error("recv");
				}

//客户端断开连接
				else if(len == 0)
				{
					printf("客户端[%d]断开连接\n",fd);
					if((epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL)) == -1)
					{
						sys_error("(客户端断开连接)EPOLL_CTL_DEL");
					}
					close(fd);

				}
//客户端有数据
				else
				{
					//初始化链表新结点
					user_t new_node;
					create_node(&new_node);
					//初始化数组
					char sendName[20] = {0};
					char recvName[20] = {0};
					
					printf("客户端有数据：fd[%d] , action[%d],name[%s],toname[%s],msg[%s]\n\n", fd,msg->action,msg->name,msg->toname,msg->msg);

					handle_request(msg->action,fd,msg,head,new_node);
				}
				
			}
		}
	}

	return 0;
}

void handle_request(int action, int fd, msg_t *msg, user_t head,user_t new_node)
{
	//客户端有数据
	switch (action)
	{
		case REG:
		{
			handle_reg(msg,fd);
			
			printf("client[%s] is REG.\n\n", msg->name);

			break;
		}
		case LOG:
		{
			handle_log(msg,fd,new_node);
			printf("client[%s] is LOG.\n\n", msg->name);
			break;
		}
		case SEND:
		{
			handle_send(msg,head);

			printf("client[%s] SEND to client[%s] message[%s].\n\n",msg->name, msg->toname, msg->msg);

			break;
		}	
		case ALL:
		{
			handle_all(msg,head);

			printf("client[%s] SEND to ALL message[%s].\n\n",msg->name, msg->msg);

			break;
		}						
	}
}

void handle_reg(msg_t *msg,int fd)
{
	printf("client REG:fd[%d],name[%s],pwd[%s]\n", fd, msg->name,msg->msg);

	/*******************************************************************
	msg->action = REG;
	msg->name = 用户名
	msg->toname = 密保答案
	msg->message = 密码
	msg->check = **;
	msg->uid = 用户ID（生成的随机数）
	msg->que = 选择的密保问题（1-2）
	msg->icon = 选择的头像（1-6）
	*******************************************************************/

	/*从数据库中检索用户信息////////////////////////////////////////////*/
	char sql[SQL_MAX] = {0};
	sprintf(sql,"select * from user where uid = '%s' or uname = '%s';",msg->name);
	if((check_index(sql)) == SUCS)
	{
	//已有该用户
		msg->check = FAIL;
		printf("客户端[%d]注册失败\n",fd);
	}
	else
	{
	//将用户信息插入数据库
		/*///////////////////////////////////////////////////////////////*/
		memset(&sql, 0, SQL_MAX);
		/*随机ID/////////////////////////////////////////////////////////*/
		//msg->id = rand_id();
		msg->uid = 121212121;
		printf("客户端[%d]注册生成ID号[%d]\n",msg->uid);
		/*///////////////////////////////////////////////////////////////*/
		sprintf(sql,"insert into user (uid, uname, upwd, nquestion, uanser, uicon) values('%d','%s','%s','%d','%s','%d');",/*id*/msg->uid,/*用户名*/msg->name,/*密码*/msg->msg,/*问题*/msg->qus,/*答案*/msg->toname,/*头像*/msg->icon	);
		insert_index(sql);
		/*///////////////////////////////////////////////////////////////*/
		msg->check = SUCS;
		printf("客户端[%d]注册成功\n",fd);
	}
	printf("send client msg:id[%d],name[%s],pwd[%s],ques[%d],anser[%s],icon[%d]\n", msg->uid, msg->name,msg->msg,msg->qus,msg->toname,msg->icon);
	if(send(fd,msg,sizeof(msg_t),0) == -1)
	{
		sys_error("send(用户注册)");
	}
	usleep(3);
}

void handle_log(msg_t *msg,int fd,user_t new_node)
{
	printf("client LOG:fd[%d],name[%s],pwd[%s]\n", fd, msg->name,msg->msg);

	/*******************************************************************
	msg->action = LOG;
	msg->name = 用户名
	msg->toname = /
	msg->message = 密码
	msg->check = **;
	msg->uid = /
	msg->que = /
	msg->icon = 查询出用户头像
	msg->usign = 查询出个性签名
	*******************************************************************/

	/*从数据库中检查用户信息////////////////////////////////////////////*/
	char sql[SQL_MAX] = {0};
	sprintf(sql,"select * from user where (uid = '%s' or uname = '%s') and upwd = '%s';",msg->name,msg->name,msg->msg);

	if((check_index(sql)) == SUCS)
	{
//成功
		/*查询用户头像和个性签名////////////////////////////////////////////*/
		char icon[10] = {0};
		memset(&sql, 0, SQL_MAX);
		sprintf(sql,"select usign , uicon from user where uname = '%s' or uid = '%s' ;",/*用户名*/msg->name,/*用户ID*/msg->name);
		query_index(sql,msg->usign,icon);
		msg->icon = atoi(icon);
		/*将用户信息插入在线用户链表/////////////////////////////////////////*/
		memset(new_node,0,sizeof(user_t));
		new_node->cfd = fd;
		strcpy(new_node->usign,msg->usign);
		new_node->icon = msg->icon;
		strcpy(new_node->name,msg->name);
		printf("将用户信息插入在线用户链表:fd[%d],name[%s],usign[%s],icon[%d] \n",new_node->cfd,new_node->name,new_node->usign,new_node->icon);
		insert_node(head,new_node);
		/*////////////////////////////////////////////////////////////////*/
		msg->check = SUCS;
		printf("客户端[%d]登录成功\n",fd);
		/*/////////////////////////////////////////////////////////////////*/
		printf("msg:fd[%d],name[%s],pwd[%s],usign[%s],icon[%d],check[%d]\n", fd, msg->name,msg->msg,msg->usign,msg->icon,msg->check);
		/*/////////////////////////////////////////////////////////////////*/
		if(send(fd,msg,sizeof(msg_t),0) == -1)
		{
			sys_error("send(用户登录)");
		}
		usleep(3);
		/*向用户发送好友列表(在线）/////////////////////////////////////////////////*/
		memset(msg, 0, sizeof(msg_t));
		handle_fri(msg, fd, head);
		/*/////////////////////////////////////////////////////////////////*/
	}
//失败
	else
	{
		msg->check = FAIL;
		printf("客户端[%d]登录失败\n",fd);
		
		if(send(fd,msg,sizeof(msg_t),0) == -1)
		{
			sys_error("send(用户登录)");
		}
		usleep(3);
	}
}
void handle_fri(msg_t *msg, int fd, user_t head)
{
	printf("向用户发送在线好友列表...\n");
	user_t p = head->next;
	printf("user_t p = head->next;\n");
	while(p != NULL)
	{
		printf("while(p != NULL)");

		/*******************************************************************
		msg->action = FRI;
		msg->name = 好友用户名
		msg->toname = /
		msg->message = /
		msg->check = /;
		msg->uid = /
		msg->que = /
		msg->icon = 好友头像
		msg->usign = 好友个性签名
		*******************************************************************/
		msg->action = FRI;
		strcpy(msg->name,p->name);
		strcpy(msg->usign,p->usign);
		msg->icon = p->icon;
		printf("friend:fd[%d],name[%s],usign[%s],icon[%d]\n", fd, msg->name,msg->usign,msg->icon);
		if(send(fd,msg,sizeof(msg_t),0) == -1)
		{
			sys_error("send(在线好友列表)");
		}
		usleep(3);
		p = p->next;
	}
}

void handle_send(msg_t *msg, user_t head)
{
	int to_fd = find_node(head,msg->toname);

	/*******************************************************************
	msg->action = SEND;
	msg->name = 发送者
	msg->toname = 接收者
	msg->message = 消息
	*******************************************************************/

	if(send(to_fd,msg,sizeof(msg_t),0) == -1)
	{
		sys_error("send(私聊转发)");
	}
}


void handle_all(msg_t *msg, user_t head)
{
	user_t p = head;

	while(p != NULL)
	{
				/*******************************************************************
				msg->action = ALL;
				msg->name = 发送者
				msg->toname = 0
				msg->message = 消息
				*******************************************************************/
		if(send(p->cfd,msg,sizeof(msg_t),0) == -1)
		{
			sys_error("send(群聊转发)");
		}
		p = p->next;
	}
}

void init_TCP()
{
	//初始化
	bzero(&server_addr, sockaddr_len);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);	//任何IP都可以连我
	server_addr.sin_port = htons(PORT);

	//1、套接字  TCP协议
	if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		sys_error("socket(TCP)");
	}

	int opt = 1;
	setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	//2、bind
	if((bind(socketfd,(struct sockaddr*)(&server_addr),sockaddr_len)) == -1)
	{
		sys_error("bind(TCP)");
	}

	//3、listen
	if((listen(socketfd,15)) == -1)
	{
		sys_error("listen");
	}
	printf("start Accepting ...\n");
}

void init_database()
{
	connect_db();
	create_table("user");
}

