/*
 * listen_server.c
 *
 *  Created on: 2019.04.22
 *      Author:谢昕贝
 *
 */

#include "../../include/myhead.h"

/*函数作用：监听服务器发送的消息
 *输入：无
 *返回值: 无
 */
 void * listen_sever(void *arg)
{
	/*局部变量*/
	int oldtype;
	struct message msg;
	int ret = 0;
	
	/*设置线程立即退出，oldtype存入运来的取消动作类型值*/
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &oldtype);

	while(1)
	{
		memset(&msg, 0, sizeof(msg));

		if (flag_pthread == 1)//线程结束
		{
			flag_pthread = 0;//复位
			break;
		}

		/*服务器消息*/
		ret = recv(socketfd, &msg, sizeof(msg), 0);
		if (ret < 0)
		{
			perror("recv(lisent_server)");
		}

		switch(msg.cmd)
		{
			case (ONLINE + SUC)://接收在线用户列表
			{
				printf("|\t%-20s|\n",msg.UserName);
				break;
			}
			case (FRIEND + SUC)://接收好友列表
			{
				printf("|\t%-20s|\n",msg.UserName);
				break;
			}
			case (PRIVATE + BAN): //用户被禁言
			{
				printf("\n>!!>您已被管理员禁言\n");
				
				pthread_mutex_unlock(&mutex);//解[私聊]锁
				break;
			}
			case (PRIVATE + SUC): //私聊提醒
			{
				printf("\n[%s(private)]:%s\n", msg.UserName, msg.note);
				keep_chat(msg);
				sleep(1);
				break;
			}
			case(PRIVATE + RE)://发送私聊回复
			{
				printf(">>>>私聊发送成功\n");
				/*保存聊天记录*/
				keep_chat(msg);

				pthread_mutex_unlock(&mutex);//解[私聊]锁
				break;
			}
			case (PRIVATE + FAIL): //私聊失败提醒
			{
				printf("\n>!!>对方不存在或不在线\n");

				pthread_mutex_unlock(&mutex);//解[私聊]锁
				break;
			}
			case (GROUP + BAN):	//用户被禁言
			{
				printf("\n>!!>您已被管理员禁言\n");
				pthread_mutex_unlock(&mutex);//解[群聊]锁
				break;
			}
			case (GROUP + SUC):	//群聊提醒
			{
				printf("\n[%s(public)]:%s\n", msg.UserName, msg.note);
				keep_chat(msg);
				break;
			}
			case(GROUP + RE)://发送群聊回复
			{
				printf(">>>>群聊发送成功\n");
				/*保存聊天记录*/
				keep_chat(msg);

				pthread_mutex_unlock(&mutex);//解[群聊]锁
				break;
			}
			case (NOTICE + ADMIN): //管理员上线提醒
			{
				printf("\n>**>管理员[%s]上线\n", msg.UserName);
				break;
			}
			case (NOTICE + SUC): //上线提醒
			{
				printf("\n>**>用户[%s]上线\n", msg.UserName);
				break;
			}
			case (PWD + SUC)://密码修改成功
			{
				printf("\n>!!>密码修改成功\n");
				printf("按ENTER键继续\n");
				break;
			}
			case (PWD + FAIL)://密码输入错误
			{
				printf("\n>!!>密码输入错误\n");
				printf("按ENTER键继续\n");
				break;
			}
			case (BAN + SUC)://禁言提示
			{
				printf("\n>!!>您已被管理员[%s]禁言\n>!!>在解除禁言前不能进行私聊、群聊、发文件等操作\n",msg.UserName);
				printf("按ENTER键继续\n");
				break;
			}
			case (BAN + FAIL)://禁言失败
			{
				printf("\n>!!>禁言操作失败，[%s]是管理员\n", msg.RecvUserName);
				printf("按ENTER键继续\n");
				break;
			}
			case (OUT + SUC)://踢出提示
			{
				printf("\n>!!>您已被管理员[%s]踢出聊天室\n>!!>	3秒后将自动注销...\n", msg.UserName);
				countdown();
				user_exit();
				break;
			}
			case (OUT + FAIL)://踢人失败
			{
				printf("\n>!!>踢人操作失败，[%s]是管理员\n", msg.RecvUserName);
				printf("按ENTER键继续\n");
				break;
			}
			case(SENDFILE + SUC):
			{
				msg.cmd = SENDFILE + ACP;
				ret = send(socketfd, &msg, sizeof(struct message), 0);
				if(ret < 0)
				{
					perror("send(SENDFILE + ACP)");
				}
				break;
			}
			case(SENDFILE + FAIL):
			{
				printf("\n>!!>	对方不在线\n");
				printf("按ENTER键继续\n");
				break;
			}
			case (SENDFILE + BAN)://被禁言，不能发文件
			{
				printf("\n>!!>操作失败，您已被管理员禁言\n");
				//memcpy(ptr,"ban",sizeof("ban"));
				printf("按ENTER键继续\n");
				break;
			}
			case (SENDFILE + ACP)://传输文件提醒
			{
				char yn;
				/* 判断是否接收文件 */
				printf("\n>>>>用户[%s]要求发送[%s],是否接收？（y/n)\n", msg.UserName,msg.Time);
				printf(">!!>请确认当前目录下没有同名文件（文件有被覆盖的风险）\n");
				system("ls");
				printf("按ENTER键继续\n");
				do
				{
					printf("您的选择(y/n)：");
					scanf("%c",&yn);
					if((yn != 'y') &&(yn != 'n'))
					{
						printf("输入错误！\n");
					}
				}while ((yn != 'y') &&(yn != 'n'));
					
				//同意接收
				if(yn == 'y')
				{
					msg.cmd = SENDFILE + ACP + SUC;
					//接收
					ret = send(socketfd, &msg, sizeof(msg), 0);
					if (ret < 0)
					{
						perror("send(SENDFILE + ACP + SUC)");
					}
					printf(">>>>您已接收对方发送的文件\n");
				}
				//拒收
				else
				{
					//拒收
					msg.cmd = SENDFILE + ACP + FAIL;
					ret = send(socketfd, &msg, sizeof(msg), 0);
					if (ret < 0)
					{
						perror("send(SENDFILE + ACP + FAIL)");
					}
					printf(">>>>您已拒收\n");
				}
				break;
			}
			
			case(SENDFILE + ACP + SUC)://发送方
			{
				/*
				int ret;
				
				strncpy(msg.note,msg.Time,strlen(msg.Time));
				if(send(socketfd,&msg,sizeof(msg),0) < 0)
				{
					perror("send(SENDFILE + ACP + SUC)");
					break;
				}
				*/
		//1、打开文件
				FILE *fd = fopen(msg.Time,"rb");
				if (fd == NULL)
				{
					printf("文件不存在!\n");
					sleep(1);
					break;
				}
				else
				{
					bzero(msg.note,sizeof(msg.note));
					int file_length = 0;

		//2、读取文件，传输
					msg.cmd = SENDFILE + ACP + SUC + ALR;
					while((file_length = fread(msg.note,sizeof(char),sizeof(msg.note),fd)) > 0)
					{
						if(send(socketfd,&msg,sizeof(msg),0) < 0)
						{
							perror("send");
							break;
						}
					}
					fclose(fd);
					printf(">>>>文件传输完毕\n");
				}
				break;
			}
			case(SENDFILE + ACP + FAIL):
			{
				printf(">>>>用户拒收，操作结束\n");		
				printf("按ENTER键继续\n");
				break;
			}
			case(SENDFILE + ACP + ALR)://目的方
			{
				
				FILE *fd = fopen(msg.Time,"wb+");
				if(NULL == fd)
				{
					perror("fopen(SENDFILE + ACP + ALR)");
					break;
				}
				else
				{
					int length = 0,write_length;
					
					write_length = fwrite(msg.note,strlen(msg.note),1,fd);

					pthread_mutex_lock(&mutex);
					while((length = recv(socketfd, &msg, sizeof(msg), 0)))//length = recv接收到的字节数 , 连接中止，返回0
					{
						if(length < 0)
						{
							perror("recv(SENDFILE + ACP + ALR)");
							break;
						}
						write_length = fwrite(msg.note,strlen(msg.note),length,fd);//write_length写入的字节数
						if(write_length < length)
						{
							break;
						}
						bzero(msg.note,sizeof(msg.note));
					}
					pthread_mutex_unlock(&mutex);//解[传输]锁
				}
				
				fclose(fd);
				printf("\n>>>>文件接收完毕.\n");
				break;
			}
			default:
			{
				printf("error!!!! cmd = %d\n", msg.cmd);
				break;
			}
		}
	}

	pthread_exit(NULL);//结束当前线程
	return NULL;
}




