/*
 * user.c
 *
 *  Created on: 2019.4.22
 *      Author:谢昕贝
 */

#include "../../include/myhead.h"

/*函数作用：用户注册
 *描述：输入用户名，密码
  	    发送注册请求
  	    等待服务器回应
  	    处理回应结果
 *输入：无
 *返回值: 无
 */
 void user_register()
{

	printf("|----------------------------------注册---------------------------------------|\n");
	int ret = 0,i;
	char buf[25] = {0};
	struct message reg;
	memset(&reg, 0, sizeof(reg));
	reg.cmd = REGISTER;

	/*用户名*/
	while (1)
    {
        printf("|	用户名(<=20字节)：");
        fgets(buf, 1024, stdin);
        for (i = 0; buf[i] != '\n'; i++)
        {
            reg.UserName[i] = buf[i];
        }
        if (strlen(buf) == 1)
        {
            printf(">!!>用户名为空！\n");
            continue;
        }
        if (i >= 20)
        {
            printf(">!!>用户名过长！\n");
            continue;
        }
         reg.UserName[i] = '\0';

        break;
    }

	if (!strcmp(reg.UserName, "ALL"))
	{
		printf(">!!>用户名不可注册为ALL\n");

		printf("\n按ENTER键继续\n");
		while(getchar() != '\n');
		return;
	}

	printf("|	密  码：");
	pwd_hide(reg.note, sizeof(reg.note));
	
	/*发送注册请求*/
	ret = send(socketfd, &reg, sizeof(reg), 0);
	if (ret < 0)
	{
		perror("send(register) error");
	}

	printf("\n>>>>	等待服务器回应...\n");

	memset(&reg, 0, sizeof(reg));

	/*等待服务器回应*/
	ret = recv(socketfd, &reg, sizeof(reg), 0);//接收服务器回复
	if (ret < 0)
	{
		perror("recv(register) error");
	}

	/*处理服务器回应*/
	if (reg.cmd == REGISTER + SUC)//注册成功
	{
		printf(">>>>	注册成功.\n");
		printf(">>>>	按ENTER键继续\n");
		while(getchar() != '\n');
	}
	else if (reg.cmd == REGISTER + REP)//用户名重复
	{
		printf(">!!>	该用户名已被注册.\n");
		printf(">>>>	按ENTER键继续\n");
		while(getchar() != '\n');
	}
	else
	{
		printf(">!!>	服务器正在维护,请稍后再试.\n");
		printf(">>>>	按ENTER键继续\n");
		while(getchar() != '\n');
	}
}
  
 
/*函数作用：用户登录
*描述：输入用户名，密码
	 发送登录请求
	 等待服务器回应
	 登录处理
*输入：无
*输出：操作处理信息
*返回值: 操作码（普通用户、管理员）
*/
int user_login()
{

	printf("|----------------------------------登录---------------------------------------|\n");
	int ret = 0;
	struct message log;
	memset(&log, 0, sizeof(log));
	log.cmd = LOGIN;

	/*用户名*/
	printf("|	 用户名：");
	scanf("%s", log.UserName);
	getchar();

	/*密码*/
	printf("|	 密  码：");
	pwd_hide(log.note, sizeof(log.note));

	printf("|-----------------------------------------------------------------------------|\n");

	/*发送登录请求*/
	ret = send(socketfd, &log, sizeof(log), 0);
	if (ret < 0)
	{
		perror("send(login) error");
	}

	printf("\n>>>>  等待服务器回应...\n");

	memset(&log, 0, sizeof(log));

	/*等待服务器回应*/
	ret = recv(socketfd, &log, sizeof(log), 0);//接收服务器回复
	if (ret < 0)
	{
		perror("recv(login) error");
	}

	/*处理服务器回应*/
	if ((log.cmd == LOGIN + SUC) || (log.cmd == LOGIN + ADMIN))
	{
		strcpy(User, log.UserName);
		printf(">>>>	 登录成功.\n");
		printf(">>>>	 按ENTER键继续\n");
		while(getchar() != '\n');
	}
	else if (log.cmd == LOGIN + ALR)//用户已登录
	{
		printf(">!!>	 登录失败.\n");
		printf(">>>>	 您已登录.\n");
		printf(">>>>	 按ENTER键继续\n");
		while(getchar() != '\n');
	}
	else if(log.cmd == LOGIN + FAIL)//用户名或密码错误
	{
		printf(">!!>	 登录失败.\n");
		printf(">>>>	 用户名或密码错误，请重新输入.\n");
		printf(">>>>	 按ENTER键继续\n");
		while(getchar() != '\n');
	}
	else if(log.cmd == LOGIN + OUT)//已被踢出聊天室
	{
		printf(">!!>	 登录失败.\n");
		printf(">>>>	 您已被管理员踢出聊天室.\n");
		printf(">>>>	 按ENTER键继续\n");
		while(getchar() != '\n');
	}
	else
	{
		printf(">!!>	 服务器正在维护,请稍后再试.\n");
		printf(">>>>	 按ENTER键继续\n");
		while(getchar() != '\n');
	}
	return log.cmd;
}

/*函数作用：用户退出

*输入：无
*返回值: 无
*/
void user_exit()
{
	int ret = 0;
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	msg.cmd = EXIT;

	/*向服务器发送退出请求*/
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
	 perror("send(exit)");
	}

	printf("客户端关闭.\n");
	close(socketfd);
	exit(0);
}

/*函数作用：用户注销登录

*输入：无
*返回值: 无
*/
void user_logout()
{
	int ret = 0;
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, User);
	msg.cmd = LOGOUT;

	/*取消监听线程*/
	pthread_cancel(tid_listen);

	/*发送注销请求*/
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
		perror("send(logout) ");
	}

	memset(User, 0, sizeof(User));//清空User
}

/*函数作用：用户私聊

*输入：无
*返回值: 无
*/
void user_PrivateChat()
{
	/*局部变量*/
	int ret = 0;
	char str[1024] = {0};
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, User);
	msg.cmd = PRIVATE;

	/*发送方*/
	printf(">>>>在线用户(按ENTER键继续)\n");
	user_online();
	
	printf(">>>>请输入想私聊的用户: ");
	scanf("%s", msg.RecvUserName);
	getchar();

	/*  聊天手册		 */
	chat_help();

	printf(">>>>接收方:用户[%s]<<<<\n",msg.RecvUserName);
	printf(">>>>开始私聊，输入\\exit结束私聊\n");

	while(1)
	{
		pthread_mutex_lock(&mutex);
	
		memset(msg.note, 0, sizeof(msg.note));

		/*输入发送的信息*/
		printf(">>>>[%s]: ",User);
		gets(str);

		/*退出：\exit*/
		if (!strcmp(str, "\\exit"))
		{
			pthread_mutex_unlock(&mutex);//解[私聊]锁
			break;
		}

		/*  处理 	 */
		handle_chat(&msg,str);

		/*获取当前时间*/
		getTime(msg.Time);

		/*向服务器发送私聊请求*/
		ret = send(socketfd, &msg, sizeof(msg), 0);
		if (ret < 0)
		{
		 perror("send(private)");
		}
	}
}

/*函数作用：用户群聊

 *输入：无
 *返回值: 无
 */
 void user_GroupChat()
{
	/*局部变量*/
	int ret = 0;
	char str[1024] = {0};
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, User);
	msg.cmd = GROUP;
	
	/*	聊天手册		*/
	chat_help();
	
	printf(">>>>开始群聊，输入\\exit结束群聊\n");
	while(1)
	{
		pthread_mutex_lock(&mutex);//加锁
		
		memset(msg.note, 0, sizeof(msg.note));

		/*输入发送的信息*/
		printf(">>>>[%s]: ",User);
		gets(str);

		/*退出：\exit*/
		if (!strcmp(str, "\\exit"))
		{
			pthread_mutex_unlock(&mutex);//解[群聊]锁
			break;
		}

		/*	处理		*/
		handle_chat(&msg,str);

		/*获取当前时间*/
		getTime(msg.Time);

		/*向服务器发送群聊请求*/
		ret	= send(socketfd, &msg, sizeof(msg), 0);
		if (ret < 0)
		{
			perror("send(GROUP)");
		}
	}
}
/*函数作用：用户传输文件

*输入：无
*返回值: 无
*/
void user_SendFile()
{
/*  局部变量	  */
	int ret = 0;
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, User);

//1、文件
	printf("\n>>>>当前目录已有文件：\n");
	system("ls");
	fflush(stdout);

	printf(">>>>请输入要传输的文件名: ");
	scanf("%s", msg.Time);
	getchar(); 

	//检查文件是否存在
	FILE *fd = fopen(msg.Time,"rb");
	if (fd == NULL)
	{
	 printf("文件不存在!\n");
	 sleep(1);
	 return;
	}

//2、用户是否在线，客户端是否被禁言等 
	//请求服务器 ：SENDFILE
	printf(">>>>在线用户:\n");
	user_online();
	printf(">>>>请输入传输对象用户名: ");
	scanf("%s", msg.RecvUserName);
	getchar();

	msg.cmd = SENDFILE;
	//发送请求 
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
	 perror("send(online)");
	 return;
	}
 
}



	 

/*函数作用：用户修改密码

*输入：无
*返回值: 无
*/
void user_pwd()
{
	/*局部变量*/
	int ret = 0;
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, User);

	printf(">>>>请输入原密码: ");
	pwd_hide(msg.note, sizeof(msg.note));
	printf(">>>>请输入新密码: ");
	pwd_hide(msg.Time, sizeof(msg.Time));

	/*向服务器发送修改密码请求*/
	msg.cmd = PWD;
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if(ret < 0)
	{
	 perror("send(pwd)");
	}
}
/*函数作用：管理员禁言

*输入：无
*返回值: 无
*/
void user_ban()
{
	/*局部变量*/
	int ret = 0;
	struct message msg;
	memset(&msg, 0, sizeof(struct message));
	strcpy(msg.UserName, User);

	printf(">>>>用户列表：\n");
	user_friend();
	printf(">>>>输入要禁言的用户名: ");
	scanf("%s", msg.RecvUserName);
	getchar();

	/*向服务器发送禁言请求*/
	msg.cmd = BAN;
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
		perror("send(BAN)");
	}

	printf("按ENTER键继续\n");
	while(getchar() != '\n');

}

/*函数作用：管理员踢人

*输入：无
*返回值: 无
*/
void user_out()
{
 /*局部变量*/
 int ret = 0;
 struct message msg;
 memset(&msg, 0, sizeof(msg));
 strcpy(msg.UserName, User);

 printf(">>>>用户列表：\n");
 user_friend();
 printf("请输入要踢出的用户名:");
 scanf("%s", msg.RecvUserName);
 getchar();

 /*向服务器发送踢人请求*/
 msg.cmd = OUT;
 ret = send(socketfd, &msg, sizeof(msg), 0);
 if (ret < 0)
 {
	 perror("send(OUT)");
 }

 printf(">>>>按ENTER键继续\n");
 while(getchar() != '\n');
}

/*函数作用：查看在线用户

 *输入：无
 *返回值: 无
 */
void user_online()
{
	/*局部变量*/
	int ret = 0;
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, User);

	/*向服务器发送查看请求*/
	msg.cmd = ONLINE;
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
		perror("send(online)");
		return;
	}
	printf("按ENTER键继续\n");
	while(getchar() != '\n');
}

/*函数作用：查看好友列表

 *输入：无
 *返回值: 无
*/
void user_friend()
{
	/*局部变量*/
	int ret = 0;
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, User);

	/*向服务器发送查看请求*/
	msg.cmd = FRIEND;
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
		perror("send(online)");
		return;
	}
	printf("按ENTER键继续\n");
	while(getchar() != '\n');
}

/*函数作用：查看历史记录

 *输入：无
 *返回值: 无
 */
void user_history()
{
	/*局部变量*/
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	char str1[100] = "cat ";
	char str2[5] = "To";

	strcat(str1,User);	//cat User
	strcat(str1,str2);	//cat UserTo

	printf(">>>>查看群聊记录请输入  ALL\n");
	printf(">>>>好友列表：\n");
	user_friend();
	printf(">>>>请输入要查看和谁的聊天记录: ");
	scanf("%s", msg.RecvUserName);
	getchar(); 

	strcat(str1,msg.RecvUserName);	//cat UserToRecv

	system(str1);
	sleep(1);
}


/*函数作用：密码不可见处理
*
*输入：字符数组，字符数组的长度
*返回值: 无
*/
void pwd_hide(char *key_in, int size)
{
	int i = 0;
	char ch;
	struct termios oldt, newt;
	while (i < size)
	{
		tcgetattr(STDIN_FILENO,&oldt);
		newt = oldt;				 
		newt.c_lflag &= ~(ECHO | ICANON);							 
		tcsetattr(STDIN_FILENO,TCSANOW,&newt);									 
		ch = getchar();												 
		if(ch == '\n')
		{
			key_in[i] = '\0';
			tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
			break;
		}									 
		key_in[i] = ch;
		i++;																	 
		tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
		printf("*");
	}
	printf("\n");
}



/*函数作用：登录处理
 *描述：若为普通用户，则进入普通用户登录处理
    	若为管理员，则进入管理员登录处理
 *输入：操作码ret
 *返回值: 无
 */
void chatroom(int ret)
{
	if(ret == LOGIN + SUC)
	{
		user_chatroom();
	}
	if(ret == LOGIN + ADMIN)
	{
		admin_chatroom();
	}
}

/*函数作用：普通用户登录处理
 *描述：给在线好友发送上线提醒
		创建线程监听服务器信息
 *输入：无
 *返回值: 无
 */
void user_chatroom()
{
/*******************************/
	char ch[2] = {0};
	int ret = 0;
	
	struct message msg;

	/*给在线好友发送上线提醒*/
	msg.cmd = NOTICE;
	strcpy(msg.UserName, User);
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
		perror("send");
	}

	/* 互斥锁 */
    pthread_mutex_init(&mutex, NULL); /* 初始化互斥锁 */
	
	/*创建线程*/
	ret = pthread_create(&tid_listen,NULL,listen_sever,NULL);
	if (ret == -1)
	{
		perror("pthread_create");
	}
	
	while(1)
	{
		/*普通用户菜单界面*/
		user_welcome();

		/*用户输入*/
		printf(">>>>输入您的选择：");
		ch[0] = getchar();
		while (ch[1] != EOF && (ch[1] = getchar()) != '\n');

		switch(ch[0])
		{
			case '1'://1.私聊
			{
				user_PrivateChat();
				break;
			}

			case '2'://2.群聊
			{
				user_GroupChat();
				break;
			}
			case '3'://3.查看好友列表
			{
				user_friend();
				break;
			}
			case '4'://4.查看在线用户
			{
				user_online();
				break;
			}
			case '5'://5.查看聊天记录
			{
				user_history();
				break;
			}
			case '6'://6.发文件
			{
				user_SendFile();
				break;
			}
			case '7'://7.修改密码
			{
				user_pwd();
				break;
			}
			case '0'://0.注销回到登录界面
			{
				flag_pthread = 1;	//结束监听线程
				user_logout();
				break;
			}
		}
		if (flag_pthread == 1)	//注销
		{
			break;
		}
	}
}

/*函数作用：管理员登录处理
 *描述：给在线好友发送上线提醒
		创建线程监听服务器信息
 *输入：无
 *返回值: 无
 */
void admin_chatroom()
{
/******************************/
	char ch[2] = {0};
	int ret = 0;
	struct message msg;
	
	/*给在线好友发送上线提醒*/
	msg.cmd = NOTICE;
	strcpy(msg.UserName, User);
	ret = send(socketfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
		perror("send");
	}

	/* 互斥锁 */
    pthread_mutex_init(&mutex, NULL); /* 初始化互斥锁 */
	
	/*创建线程*/
	ret = pthread_create(&tid_listen, NULL, listen_sever, NULL);
	if (ret < 0)
	{
		perror("pthread_create");
	}
	
	while(1)
	{
		/*管理员菜单界面*/
		admin_welcome();
		/*用户输入*/
		printf(">>>>输入您的选择：");
		ch[0] = getchar();
		while (ch[1] != EOF && (ch[1] = getchar()) != '\n');

		switch(ch[0])
		{
			case '1'://1.私聊
			{
				user_PrivateChat();
				break;
			}
			case '2'://2.群发
			{
				user_GroupChat();
				break;
			} 
			case '3'://3查看好友列表
			{
				user_friend();
				break;
			}
			case '4'://4.查看在线用户
			{
				user_online();
				break;
			}
			case '5'://5.查看聊天记录
			{
				user_history();
				break;
			}
			case '6'://6.传文件
			{
				user_SendFile();
				break;
			}
			case '7'://7.修改密码
			{
				user_pwd();
				break;
			}
			case '8'://8.禁言
			{
				user_ban();
				break;
			}
			case '9'://9.踢人
			{
				user_out();
				break;
			}
			case '0'://0.注销回到登录界面
			{
				flag_pthread = 1;	//准备结束监听线程
				user_logout();
				break;
			}
		}
		if (flag_pthread == 1)	//确认选择了注销
		{
			break;
		}
	}
	
}

/*函数作用：倒数3秒

 *输入：无
 *返回值: 无
 */
 void countdown()
{
	int i;
	for (i = 15; i > 0; i--)
	{
		if (i % 5 == 0)
		{
			printf("%d", i / 5);
		}
		else
		{
			printf(".");
		}
		fflush(stdout);//清理标准输入流
		usleep(200000);
	}
	printf("0\n");
}

/*函数作用：用户接收文件

 *输入：无
 *返回值: 无
 */
 int keep_file(int *filefd, struct message *msg, int flag_file)
{
	int ret = 0;
	
	if (flag_file == 1)
	{
		*filefd = open(msg->Time, O_WRONLY | O_CREAT | O_EXCL, 666);
		if (*filefd == -1)
		{
			perror("open(keep_file)");
		}
	}

	ret = write(*filefd, msg->note, strlen(msg->note));
	if (ret < 0)
	{
		perror("write(keep_file)");
	}

	return ret;
}



/*函数作用：获取时间

 *输入：无
 *返回值: 无
 */
void getTime(char * gtime)
{
	time_t t;

	struct tm *lt;

	/*获取从1970年1月1日00:00:00到当前时刻的秒数*/
	time(&t);

	/*把获取的秒数转换成本地时间*/
    lt = localtime(&t);

	/*把localtime得到的结果输出到tt*/
	sprintf(gtime, "%d-%d-%d %d:%d:%d", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
}

/*函数作用：本地聊天记录

 *输入：无
 *返回值: 无
 */
 void keep_chat(struct message msg)
{
	/*局部变量*/
	int ret = 0;
	int fd;
	char strTo[100] = "To";
	char strUser[20] = {0};
	char strRecv[20] = {0};

	sprintf(strUser,msg.UserName);		//strUser = UserName
	sprintf(strRecv,msg.RecvUserName);	//strRecv = RecvUserName
	strcat(strUser,strTo);		//UserNameTo

	if(strlen(msg.RecvUserName) == 0)
	{
		strcat(strUser,"ALL");		//UserNameToALL
	}
	else
	{
		strcat(strUser,strRecv);	//UserNameToRecvUserName
	}
	

	fd = open(strUser,O_WRONLY | O_CREAT | O_APPEND, 666);  //只写，创建，写到末尾
	if (fd == -1)
	{
		perror("open(keep_chat)");
	}

	//时间
	ret = write(fd, msg.Time, strlen(msg.Time));
	 if (ret < 0)
	 {
		 perror("write(keep_chat)");
	 }
	//发送内容
	ret = write(fd, msg.note, strlen(msg.note));
	 if (ret < 0)
	 {
		 perror("write(keep_chat)");
	 }
	 //换行符
	 ret = write(fd, "\n", strlen("\n"));
	 if (ret < 0)
	 {
		 perror("write(keep_chat)");
	 }
}






 /*函数作用：处理用户输入
  
   *输入：无
   *返回值: 无
   */
void handle_chat(struct message *msg,char *str)
{
	if (strcmp(str, "\\dbq") == 0)
	{
		sprintf(msg->note,"对不起");
	}
	else if (strcmp(str, "\\xswl") == 0)
	{
		sprintf(msg->note,"笑死我了");
	}
	else if (strcmp(str, "\\2333") == 0)
	{
		sprintf(msg->note,"哈哈哈hhhhh");
	}
	else if (strcmp(str, "\\nbcs") == 0)
	{
		sprintf(msg->note,"Nobody cares.");
	}
	else if (strcmp(str, "\\skr") == 0)
	{
		sprintf(msg->note,"热skr人了");
	}
	else if (strcmp(str, "\\wtf") == 0)
	{
		sprintf(msg->note,"What the fuck\?\?!!");
	}
	else if (strcmp(str, "\\xo") == 0)
	{
		sprintf(msg->note,"I Love U!!"); 
	}
	else if (strcmp(str, "\\hh") == 0)
	{
		sprintf(msg->note,"{表情}大笑");
	}
	else if (strcmp(str, "\\wx") == 0)
	{
		sprintf(msg->note,"{表情}微笑");
	}
	else if (strcmp(str, "\\ng") == 0)
	{
		sprintf(msg->note,"{表情}难过");
	}
	else if (strcmp(str, "\\dk") == 0)
	{
		sprintf(msg->note,"{表情}哭");
	}
	else if (strcmp(str, "\\dy") == 0)
	{
		sprintf(msg->note,"{表情}得意");
	}
	else if (strcmp(str, "\\cr") == 0)
	{
		sprintf(msg->note,"{表情}锤人");
	}
	else if (strcmp(str, "\\tx") == 0)
	{
		sprintf(msg->note,"{表情}吐血");
	}
	else
	{
		sprintf(msg->note,str);
	}
}


void handle_sendfile()
{
	/*  局部变量	 */
	int fd = 0;
	int ret = 0;
	int ret_read = 0;
	struct message msg;
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, User);

//1、打开文件
	fd = open(msg.Time, O_RDONLY);
	if (fd == -1)
	{
		printf("文件不存在!\n");
		sleep(1);
		return;
	}
	
	printf("\n开始传输文件...\n");		

//2、转发
	//msg.cmd = SENDFILE + ACP + SUC;
	msg.cmd = SENDFILE + ACP;
	while( (ret_read = read(fd, msg.note, sizeof(msg.note) - 1)) )
	{
		if (ret_read == -1)
		{
			perror("read_file");
			break;
		}

		ret = send(socketfd, &msg, sizeof(struct message), 0); 
		if (ret == -1)
		{
			perror("send_file");
			break;
		}

		memset(msg.note, 0, sizeof(msg.note));
		usleep(1);
	}

	printf("\n文件传输结束。\n");  
}
 





