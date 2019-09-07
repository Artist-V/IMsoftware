/*
 * main.c
 *
 *  Created on: 2018.04.22
 *      Author:谢昕贝
 */

#include "../../include/myhead.h"

/* 主函数 */
int main()
{
	/*局部变量*/
	int ret = 0;
	struct message msg;
	memset(&msg, 0, sizeof(msg));

	/*配置服务器*/
	system("clear");
	ConfigureServer();

	/*配置数据库*/
	ConnectDatabase_user();

	/*监视变量*/
	struct sockaddr_in client; 
	fd_set	readfds,tmpfds;
					//岗哨监视集合
					//readfds：监视集
					//tmpfds:临时监视集
	socklen_t addrlen;
	
	
	/*监视socket*/
	int MaxFd,cliendfd_sum = 0,client_fd = 0;
	MaxFd = socketfd;
	int ClientFd[125] = {0};//记录已连接的客户端描述符号

	//初始化监视集
	FD_ZERO(&readfds);
	FD_SET(socketfd, &readfds);//将需要监视的listenfd放入readfds集中

	/* 互斥锁 */
    pthread_mutex_init(&mutex, NULL); /* 初始化互斥锁 */

	//循环监听
	while (1)
	{
		tmpfds = readfds;
		ret = select(MaxFd + 1, &tmpfds, NULL, NULL, NULL);
		if (ret < -1)
		{
			perror("select");
		}

		//客户端发起连接
		if (FD_ISSET(socketfd, &tmpfds))
		{
			addrlen = sizeof(client);
			for (client_fd = 0; client_fd < cliendfd_sum; client_fd ++)
			{
				if (ClientFd[client_fd] == 0)
				{
					break;
				}
			}
			ClientFd[client_fd] = accept(socketfd, (struct sockaddr*)&client, (socklen_t *)&addrlen);
			if (ClientFd[client_fd] < -1)
			{
				perror("accept");
			}
			printf("Accept Client[ FD: %d  PORT: %d ]\n", ClientFd[client_fd], client.sin_port);

			if (MaxFd < ClientFd[client_fd])
			{
				MaxFd = ClientFd[client_fd];
			}
			
			FD_SET(ClientFd[client_fd], &readfds);

			if ( client_fd == cliendfd_sum)
			{
				cliendfd_sum++;
			}
		}
		
		//客户端发送请求
		else						
		{
			for (client_fd = 0; client_fd < cliendfd_sum; client_fd++)
			{
				if (FD_ISSET(ClientFd[client_fd], &tmpfds))
				{
					ret = recv(ClientFd[client_fd], &msg, sizeof(msg), 0);
					if (ret < -1)
					{
						perror("recv");
						exit(1);
					}
					switch(msg.cmd)
					{
						case(SENDFILE + ACP + SUC + ALR):
						{
							msg.cmd = SENDFILE + ACP + ALR;
							if(send(atoi(msg.RecvUserName),&msg,sizeof(msg),0) < 0)
							{
								perror("send(SENDFILE + ACP + ALR)");
							}
							printf("Sending Flie\n");
							break;
						}
						case REGISTER:	//处理注册指令
						{
							handle_register(ClientFd[client_fd], &msg);
							break;
						}
						case LOGIN:		//处理登录指令
						{
							handle_login(ClientFd[client_fd], &msg);
							break;
						}
						case EXIT:		//处理退出指令
						{
							handle_exit(&ClientFd[client_fd], &readfds, client);
							break;
						}
						case PRIVATE:	//处理私聊指令
						{
							handle_PrivateChat(ClientFd[client_fd], &msg);
							break;
						}
						case GROUP:		//处理群发指令
						{
							handle_GroupChat(ClientFd[client_fd], &msg);
							break;
						}
						case NOTICE:	//上线提醒
						{
							handle_notice(ClientFd[client_fd], &msg);
							break;
						}
						case ONLINE:	//在线用户列表
						{
							handle_online(ClientFd[client_fd], &msg);
							break;
						}
						case PWD:		//修改密码
						{
							handle_pwd(ClientFd[client_fd], &msg);
							break;
						}
						case LOGOUT:	//处理注销命令
						{
							handle_logout(ClientFd[client_fd], &msg);
							break;
						}
						case BAN:		//处理禁言
						{
							handle_ban(ClientFd[client_fd], &msg);
							break;
						}
						case OUT:		//处理踢出
						{
							handle_out(ClientFd[client_fd], &msg);
							break;
						}
						case FRIEND:	//好友列表
						{
							handle_friend(ClientFd[client_fd], &msg);
							break;
						}
						case SENDFILE:	//文件传输
						{
							handle_SendFile_user(ClientFd[client_fd], &msg);
							break;
						}
						case SENDFILE + ACP:
						{
							handle_SendFile_accept(ClientFd[client_fd], &msg);
							break;
						}
						case(SENDFILE + ACP + SUC)://服务器处理SENDFILE + ACP + SUC请求
						{
							if(send(atoi(msg.UserName),&msg,sizeof(msg),0) < 0)
							{
								perror("send(SENDFILE + ACP + SUC)");
							}
							printf("Connect\n");
							break;
							
						}
						case(SENDFILE + ACP + FAIL)://服务器处理SENDFILE + ACP + FAIL请求
						{
							ret = send(atoi(msg.UserName), &msg, sizeof(msg), 0);
							if (ret < 0)
							{
								perror("send(SENDFILE + ACP + FAIL)");
							}
							break;
						}
					}
					memset(&msg, 0, sizeof(msg));
					break;
				}
			}
		}
	}
	close(socketfd);
	return 0;
}












