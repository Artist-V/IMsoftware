/*
 * main.c
 *
 *  Created on: 2019.4.22
 *      Author:谢昕贝
 */

#include "../../include/myhead.h"

/* 主函数 */
int main(int argc, char *argv[])
{
	/*局部变量*/
	char ch[2] = {0};
	int ret = 0;
	
	/*启动*/
	system("clear");
	printf("正在启动客户端...\n");
	sleep(1);
	
	/*配置客户端*/
	ConfigureClient();

	/*聊天室欢迎界面*/
	welcome();
	sleep(1);

	while(1)
	{
		/*登陆界面*/
		login_welcome();
		
		/*用户输入*/
		printf(">>>>输入您的选择：");
		ch[0] = getchar();
		while (ch[1] != EOF && (ch[1] = getchar()) != '\n');//清空输入缓冲区

		switch (ch[0])
		{
			case '1' ://注册
			{
				user_register();
				break;
			}
			case '2'://登录
			{
				ret = user_login();
				chatroom(ret);
				break;
			}
			case '0'://退出
			{
				user_exit();
				break;
			}
		}
	}
	/*等待回收线程tid_listen*/
	pthread_join(tid_listen, NULL);
}

