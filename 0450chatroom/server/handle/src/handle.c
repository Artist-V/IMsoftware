/*
 * main.c
 *
 *  Created on: 2011-7-27
 *      Author:
 */

#include "../../include/myhead.h"


/*函数作用：处理用户注册
 *描述：打开数据库
        添加用户名、密码、设置用户状态
        回复客户端
        关闭数据库
 *输入：无
 *返回值：无
 */
void handle_register(int fd, struct message *msg)
{
/***************************************************/
	int ret = 0;
	char sql[256] = {0};
	char *errmsg = NULL;
	//用户默认状态
	int online = 0; 	//在线状态为离线
	int cliendfd = -1;	//用户默认登录客户端为-1
	int admin  = 0; 	//非管理员用户
	int ban = 0;		//未被禁言
	int out = 0;		//未被踢出聊天室

	/*1、打开数据库*/
	ret = sqlite3_open("chat.db", &db);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open(register) error:%s\n",sqlite3_errmsg(db));
		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if (ret < 0)
		{
			perror("send(register) error");
		}
		/*4、关闭数据库*/
		sqlite3_close(db);
	}
	else
	{
		printf("\ndatabase open.(Client %d Register)\n",fd);
	}

	/*2、添加用户信息*/
	sprintf(sql, "insert into user values('%s','%s',%d, %d, %d, %d, %d);", msg->UserName, msg->note, online, cliendfd, admin, ban, out);
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec(insert) error: %s\n",errmsg);
		//用户名重复
		if (sqlite3_errcode(db) == 19)
		{
			msg->cmd = REGISTER + REP;
			ret = send(fd, msg, sizeof(struct message), 0);
			if (ret < -1)
			{
				perror("send(REGISTER + REP)");
			}
		}
		/*4、关闭数据库*/
		sqlite3_close(db);
		printf("database close.(username[%s] repetition)\n\n", msg->UserName);
		return;
	}
	/*3、注册成功*/
	else
	{
		msg->cmd = REGISTER + SUC;
		ret = send(fd, msg, sizeof(struct message), 0);
		if (ret < -1)
		{
			perror("send(register) error");
		}
	}
	/*4、关闭数据库*/
	sqlite3_close(db);
	printf("database close.(Client %d User[%s] Register success)\n\n", fd,msg->UserName);
}


 /*函数作用：处理用户登录
 *描述：打开数据库
 		检索用户数据
 		1）用户是否已在线
 		2）用户是否已被踢出聊天室
 		3）用户是否是管理员
 		4）用户为普通用户
 		5）不存在该用户
 		回复客户端处理结果
 *输入：无
 *返回值：无
 */
void handle_login(int fd, struct message *msg)
{
	int ret = 0;

	/*1、打开数据库*/
	ret = sqlite3_open("chat.db", &db);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open(login) error.\n");
		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if ( ret < 0)
		{
			perror("send(sqlite3_open) error");
		}
	}
	else
	{
		printf("\ndatabase open.(Client %d User[%s] Login)\n\n",fd, msg->UserName);
	}


	int i = 0;
	char *sql;
	char sql2[256] = {0};
	char *errmsg = NULL;
	char **result = NULL;
	int rowCount = 0, columnCount = 0;

	/*2、检索用户数据*/
	sql = "select * from user";
	ret = sqlite3_get_table(db, sql, &result, &rowCount, &columnCount, &errmsg);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec(login):%s\n",errmsg);

		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if ( ret < 0)
		{
			perror("send(login) error");
		}
		printf("operate database failure.\n");
		printf("database close.(sqlite3_get_table  error)\n\n");
		/*5、关闭数据库*/
		sqlite3_free(errmsg);
		sqlite3_close(db);
		return;
	}


	/*3、验证*/
	for (i = columnCount; i < (rowCount + 1)*columnCount; i += columnCount)
	{	
		//user( UserName, pwd , Online , Clientfd , Admin ,Ban , Out )
		//匹配用户名和密码(用户名 UserName  , 密码 note)
		if (!strcmp(result[i], msg->UserName) && !strcmp(result[i + 1], msg->note))
		{
			//用户已登录
			if (atoi(result[i + 2]) == 1)	//Online
			{
				msg->cmd = LOGIN + ALR;
				ret = send(fd, msg, sizeof(struct message), 0);
				if (ret < 0)
				{
					perror("send(LOGIN + ALR)  error");
				}
				printf("database close.(User[%s] had Logon))\n\n", msg->UserName);
				/*5、关闭数据库*/
				sqlite3_free(errmsg);
				sqlite3_free_table(result);
				sqlite3_close(db);
				
				return;
			}
			//用户已被踢出聊天室
			else if (atoi(result[i + 6]) == 1)	//Out
			{
				msg->cmd = LOGIN + OUT;
				ret = send(fd, msg, sizeof(struct message), 0);
				if (ret < 0)
				{
					perror("send(LOGIN + OUT) error");
				}
				printf("database close.(User[%s] had been out)\n\n", msg->UserName);
				/*5、关闭数据库*/
				sqlite3_free(errmsg);
				sqlite3_free_table(result);
				sqlite3_close(db);
				
				return;
			}
				
			/*4、成功匹配*/
			//管理员
			else if (atoi(result[i + 4]) == 1)	//Admin
			{
				msg->cmd = LOGIN + ADMIN;
				ret = send(fd, msg, sizeof(struct message), 0);
				if (ret < 0)
				{
					perror("send(LOGIN + ADMIN) error");
					printf("database close.(server is in trouble)\n\n");
					/*5、关闭数据库*/
					sqlite3_free(errmsg);
					sqlite3_free_table(result);
					sqlite3_close(db);
				}
			}
			//普通用户
			else
			{
				msg->cmd = LOGIN + SUC;
				ret = send(fd, msg, sizeof(struct message), 0);
				if (ret < 0)
				{
					perror("send(LOGIN + SUC) error");
					printf("database close.(server is in trouble)\n\n");
					/*5、关闭数据库*/
					sqlite3_free(errmsg);
					sqlite3_free_table(result);
					sqlite3_close(db);
				}
			}

			//设置在线
			sprintf(sql2, "update user set Online = '1', Clientfd = '%d' where UserName = '%s';", fd, msg->UserName);
			ret = sqlite3_exec(db, sql2, NULL, NULL, &errmsg);
			if (ret != SQLITE_OK)
			{
				printf("sqlite3_exec(set online) error:%s\n",errmsg);
			}
			printf("User[%s] Login success.\n", msg->UserName);
			printf("database close.(Client %d User[%s] Login)\n\n", fd, msg->UserName);
			/*5、关闭数据库*/
			sqlite3_free(errmsg);
			sqlite3_free_table(result);
			sqlite3_close(db);
			
			return;
		}

	}

	//无该用户
	msg->cmd = LOGIN + FAIL;
	ret = send(fd, msg, sizeof(struct message), 0);
	if (ret < 0)
	{
		perror("send(LOGIN + FAIL) error");
	}
	/*5、关闭数据库*/
	sqlite3_free_table(result);
	sqlite3_close(db);
	printf("database close.(username or password is wrong)\n\n");
}


 /*函数作用：处理客户端退出
 *描述：在监视集中清除该用户
 *输入：无
 *返回值：无
 */
void handle_exit(int *fd, fd_set *readfds, struct sockaddr_in client)
{
	printf("\nClient %d exit. PORT: %d\n\n", *fd, client.sin_port);
	close(*fd);
	FD_CLR(*fd, readfds);//在集合中清除
	*fd = 0;
}


 /*函数作用：处理用户注销
 *描述：1、打开数据库
 		2、更新用户表信息
 
 *输入：无
 *返回值：无
 */
void handle_logout(int fd, struct message *msg)
{
/**************************************/
	int ret = 0;
	char *errmsg = NULL;
	int Online = 0;//用户状态
	int Clientfd = -1;//登录客户端
	char sql[256] = {0};

/*********************************************/
	/*1、打开数据库*/
	ret = sqlite3_open("chat.db", &db);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open(logout) error.\n");
		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if ( ret < 0)
		{
			perror("send(sqlite3_open) error");
		}
	}
	else
	{
		printf("\ndatabase open.(Client %d User[%s] Logoff)\n", fd, msg->UserName);
	}

	/*2、更新用户表信息*/
	sprintf(sql, "update user set Online = '%d', Clientfd = '%d' where UserName = '%s';", Online, Clientfd, msg->UserName);
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec(logout-update) error:%s\n",errmsg);
	}
	sqlite3_free(errmsg);
	sqlite3_close(db);
	printf("database close.(Client %d User[%s] Logoff success)\n\n", fd, msg->UserName);
}


 /*函数作用：处理用户私聊
 *描述：
 
 *输入：无
 *返回值：无
 */
void handle_PrivateChat(int fd ,struct message *msg)
{
	printf("\n");

/********************************/
	int ret = 0, i = 0;
	int Clientfd = 0;
	char *errmsg = NULL;
	char **result = NULL;
	int rowCount = 0, columnCount = 0;
	char *sql;
	char sql2[256] = {0};

/******************************************/
	/*1、打开数据库*/
	ret = sqlite3_open("chat.db", &db);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open(private) error.\n");
		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if ( ret < 0)
		{
			perror("send(private) ");
		}
		return ;
	}

	//1、用户是否被禁言
	sprintf(sql2, "select Ban from user where UserName = '%s';", msg->UserName);
	ret = sqlite3_exec(db, sql2, confirm_ban, msg, &errmsg);
	if (ret == SQLITE_OK)
	{
		msg->cmd = PRIVATE + BAN;//禁言 
		ret = send(fd, msg, sizeof(struct message), 0);
		if (ret < 0)
		{
			perror("send(private ban) error");
		}

		sqlite3_free(errmsg);
		sqlite3_close(db);
		printf("User[%s] had been banned, can't send Message to User[%s].\n\n", msg->UserName,msg->RecvUserName);
		return;
	}
	else if ( ret != SQLITE_ABORT)//返回0
	{
		printf("sqlite3_exec(ban) error: %s\n", errmsg);
		
		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if (ret < 0 )
		{
			perror("send(private ban) ");
		}
		sqlite3_free(errmsg);
		sqlite3_close(db);
		return;
	}

	//2、在线用户
	sql = "select * from user where Online = '1'";
	ret = sqlite3_get_table(db, sql, &result, &rowCount, &columnCount, &errmsg);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_get_table (private) error:%s\n",errmsg);

		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if ( ret < 0)
		{
			perror("send(private_online) ");
		}
		sqlite3_free(errmsg);
		sqlite3_free_table(result);
		sqlite3_close(db);
		return;
	}

	for (i = columnCount; i < (rowCount + 1) * columnCount; i += columnCount)
	{
		//3、目标用户存在
		if (!strcmp(result[i], msg->RecvUserName))
		{
			msg->cmd = PRIVATE + SUC;//私聊

			Clientfd = atoi(result[i + 3]);	//Clientfd
			ret = send( Clientfd, msg, sizeof(struct message), 0);//To目标用户
			if (ret < 0)
			{
				perror("send(private) SUC");
			}

			msg->cmd = PRIVATE + RE;//回复结果
			ret = send( fd, msg, sizeof(struct message), 0);//To用户
			if (ret < 0)
			{
				perror("send(private) RE");
			}

			keep_chat(msg);//保存聊天记录

			sqlite3_free_table(result);
			sqlite3_free(errmsg);
			sqlite3_close(db);

			printf("User[%s] Send To User[%s].MSG: %s\n\n", msg->UserName, msg->RecvUserName, msg->note);
			return;
		}
	}

	//4、目标用户不存在
	msg->cmd = PRIVATE + FAIL;
	ret = send(fd, msg, sizeof(struct message), 0);
	{
		perror("send(private fail) ");
	}

	sqlite3_free(errmsg);
	sqlite3_free_table(result);
	sqlite3_close(db);

	printf("User[%s] Send Message failure.\n\n", msg->UserName);

}

/*函数作用：处理用户群聊
*描述：

*输入：无
*返回值：无
*/
void handle_GroupChat(int fd, struct message *msg)
{
 printf("\n");

/********************************/
 int ret = 0, i = 0;
 int Clientfd = 0;
 char *errmsg = NULL;
 char **result = NULL;
 int rowCount = 0, columnCount = 0;
 char sql[256] = {0};
 memset(&sql, 0, sizeof(sql));

/******************************************/
 /*1、打开数据库*/
 ret = sqlite3_open("chat.db", &db);
 if (ret != SQLITE_OK)
 {
	 printf("sqlite3_open(group) error.\n");
	 msg->cmd = -1;
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if ( ret < 0)
	 {
		 perror("send(group)");
	 }
	 return ;
 }

 /*2、用户是否被禁言*/
 sprintf(sql, "select Ban from user where UserName = '%s';", msg->UserName);
 ret = sqlite3_exec(db, sql, confirm_ban, msg, &errmsg);
 if ( ret == SQLITE_OK)
 {
	 msg->cmd = GROUP + BAN;//禁言 
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if (ret < 0)
	 {
		 perror("send(GROUP + BAN) error");
	 }

	 sqlite3_free(errmsg);
	 sqlite3_close(db);
	 printf("User[%s] had been banned, can't send Message to ALL.\n\n", msg->UserName);
	 return;
 }
 else if ( ret != SQLITE_ABORT)//返回0
 {
	 printf("sqlite3_exec(ban) error: %s\n", errmsg);
	 
	 msg->cmd = -1;
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if (ret < 0 )
	 {
		 perror("send(group) ");
	 }
	 sqlite3_free(errmsg);
	 sqlite3_close(db);
	 return;
 }

 //2、在线用户
 sprintf(sql, "select * from user where Online = 1;");
 
 ret = sqlite3_get_table(db, sql, &result, &rowCount, &columnCount, &errmsg);
 if (ret != SQLITE_OK)
 {
	 printf("sqlite3_get_table (group) error:%s\n",errmsg);
	 msg->cmd = -1;
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if (ret < 0)
	 {
		 perror("send(group) 2");
	 }
	 sqlite3_free(errmsg);
	 sqlite3_free_table(result);
	 sqlite3_close(db);
	 return;
 }

 msg->cmd = GROUP + SUC;//群发
 for (i = columnCount; i < (rowCount + 1)*columnCount; i += columnCount)
 {
	 Clientfd = atoi(result[i + 3]);	//clientfd
	 ret = send(Clientfd, msg, sizeof(struct message), 0);
	 {
		 perror("send(group) 3");
	 }
 }

 msg->cmd = GROUP + RE;//回复客户端群发成功
 ret = send(fd, msg, sizeof(struct message), 0);
 {
	 perror("send(group) RE");
 }

 //设置接收者为所有用户
 strcpy(msg->RecvUserName, "ALL");
 keep_chat(msg);//保存聊天记录

 sqlite3_free(errmsg);
 sqlite3_free_table(result);
 sqlite3_close(db);

 printf("User[%s] Send To ALL.MSG: %s\n", msg->UserName, msg->note);

}


/*函数作用：处理上线提醒
*描述：

*输入：无
*返回值：无
*/
void handle_notice(int fd, struct message *msg)
{
/**************************/
 printf("\n");
 int ret = 0;
 char sql[256] = {0};
 char *errmsg = NULL;
 int admin = 0;

/****************************************/
 /*1、打开数据库*/
 ret = sqlite3_open("chat.db", &db);
 if (ret != SQLITE_OK)
 {
	 printf("sqlite3_open(notice) error.\n");

	 msg->cmd = -1;//表示数据库打开失败
	 if (send(fd, msg, sizeof(struct message), 0) == -1)
	 {
		 perror("send(notice)");
	 }
	 return ;
 }

 /*2用户是否为管理员*/
 sprintf(sql, "select Admin from user where UserName = '%s';", msg->UserName);
 ret = sqlite3_exec(db, sql, confirm_admin, NULL, &errmsg);
 if (ret == SQLITE_OK)
 {
	 admin = 1;
 }
 else if (ret == SQLITE_ABORT)
 {
	 admin = 0;
 }
 else
 {
	 printf("sqlite3_exec(confirm_admin) error:%s\n", errmsg);

	 msg->cmd = -1;
	 if (send(fd, msg, sizeof(struct message), 0) == -1)
	 {
		 perror("send(notice)");
	 }
	 /*4、关闭数据库*/
	 sqlite3_free(errmsg);
	 sqlite3_close(db);
	 return;
 }

 if (admin == 1)
 {
	 msg->cmd = NOTICE + ADMIN;//管理员上线提醒
 }
 else
 {
	 msg->cmd = NOTICE + SUC;//普通用户上线提醒
 }

 /*3、选择所有非当前用户的在线用户*/
 sprintf(sql, "select Clientfd from user where Online = '1' and UserName != '%s';", msg->UserName);
 ret = sqlite3_exec(db, sql, send_message, msg, &errmsg);
 if (ret != SQLITE_OK)
 {
	 printf("sqlite3_exec(notice)error:%s\n", errmsg);
	 /*4、关闭数据库*/
	 sqlite3_free(errmsg);
	 sqlite3_close(db);
	 printf("database closed. Notice error.\n");
	 return;
 }

 if (admin == 1)
 {
	 printf("Admin[%s] is online!\n", msg->UserName);
 }
 else
 {
	 printf("User[%s] is online!\n", msg->UserName);
 }

 /*4、关闭数据库*/
 sqlite3_free(errmsg);
 sqlite3_close(db);
}

/*函数作用：处理用户修改密码
*描述：

*输入：无
*返回值：无
*/
void handle_pwd(int fd, struct message *msg)
{
/**************************************/
	int ret = 0;
	char sql[256] = {0};
	char *errmsg = NULL;

/*************************************/
	/*1、打开数据库*/
	ret = sqlite3_open("chat.db", &db);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open(pwd) error.\n");

		msg->cmd = -1;
		ret = send(socketfd, msg, sizeof(struct message), 0);
		if( ret < 0)
		{
			perror("send(pwd)");
		}
		return;
	}

	/*2、密码验证*/
	sprintf(sql, "select pwd from user where UserName = '%s'", msg->UserName);
	ret = sqlite3_exec(db, sql, confirm_pwd, msg->note, &errmsg);
	if (ret == SQLITE_OK)
	{
		//原密码输入正确
		memset(sql, 0, sizeof(sql));
		sprintf(sql, "update user set pwd = '%s' where UserName = '%s'", msg->Time, msg->UserName);
		ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
		if (ret != SQLITE_OK)
		{
			printf("sqlite3_exec update password error: %d:%s\n", sqlite3_errcode(db), errmsg);
			msg->cmd = -1;
			if (send(socketfd, msg, sizeof(struct message), 0) == -1)
			{
			 perror("send(pwd)");
			}
			sqlite3_free(errmsg);
			sqlite3_close(db);
			return;
	 }
	 msg->cmd = PWD + SUC;
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if (ret < 0)
	 {
		 perror("send(pwd success).");
	 }
	 sqlite3_free(errmsg);
	 sqlite3_close(db);
	 printf("\nUser[%s] modify password success.\n", msg->UserName);

	 return;
	}

	else if(ret == SQLITE_ABORT)
	{
		 //密码错误
		 msg->cmd = PWD + FAIL;
		 ret = send(fd, msg, sizeof(struct message), 0);
		 if (ret < 0)
		 {
			 perror("send(pwd fail)");
		 }
		 sqlite3_free(errmsg);
		 sqlite3_close(db);
		 printf("\nUser[%s] modify password failure.\n", msg->UserName);
	}
	else
	{
		printf("sqlite3_exec(pwd).\n");
		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if( ret < 0)
		{
			perror("send(pwd)");
		}
		sqlite3_free(errmsg);
		sqlite3_close(db);
		return;
	}	 
}

/*函数作用：处理管理员禁言
*描述：

*输入：无
*返回值：无
*/
void handle_ban(int fd, struct message *msg)
{
/********************************/
 int ret = 0;
 char *errmsg = NULL;
 char sql[256] = {0};
 int admin = 0;
 
/****************************************/
	/*1、打开数据库*/
	ret = sqlite3_open("chat.db", &db);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open(BAN) error.\n");
	 return;
	}
	else
	{
		printf("\nopen database . User[%s] BAN.\n", msg->UserName);
	}

 /*2、是否为管理员*/
	sprintf(sql, "select Admin from user where UserName = '%s';", msg->RecvUserName);
	ret = sqlite3_exec(db, sql, confirm_admin, NULL, &errmsg);
	if (ret == SQLITE_OK)
	{
		admin = 1;
	}
	else if (ret == SQLITE_ABORT)
	{
		admin = 0;
	}
	else
	{
		printf("sqlite3_exec(BAN) error:%s\n",errmsg);
		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0) ;
		if (ret < 0)
		{
			perror("send(BAN)");
		}
		/*3、关闭数据库*/
		sqlite3_free(errmsg);
		sqlite3_close(db);
		printf("database close.(BAN sqlite3_exec error).\n\n");
		return;
	}

	//不是管理员
	if ( admin == 0 )
	{
		msg->cmd = BAN + SUC; //禁言
		memset(sql, 0, sizeof(sql));
		sprintf(sql, "select Clientfd from user where UserName = '%s';", msg->RecvUserName);
		ret = sqlite3_exec(db, sql, send_message, msg, &errmsg);
		if (ret != SQLITE_OK)
		{
			printf("sqlite3(ban) error:%s\n",errmsg);
			msg->cmd = -1;
			ret = send(fd, msg, sizeof(struct message), 0);
			if ( ret < 0)
			{
				perror("send(BAN)");
			}
			/*3、关闭数据库*/
			sqlite3_free(errmsg);
			sqlite3_close(db);
			printf("database close.(BAN + SUC sqlite3_exec error).\n\n");
			return;
		}

		sprintf(sql, "update user set Ban = '1' where UserName = '%s';", msg->RecvUserName);
		ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
		if (ret != SQLITE_OK)
		{
			printf("sqlte3_exec(BAN)error:%s\n",errmsg);
			msg->cmd = -1;
			if (-1 == send(fd, msg, sizeof(struct message), 0))
			{
				perror("send(BAN)");
			}
			/*3、关闭数据库*/
			sqlite3_free(errmsg);
			sqlite3_close(db);
			printf("database close.(BAN + SUC update error).\n\n");
			return;
	 	}
	 	/*3、操作成功       关闭数据库*/
		sqlite3_free(errmsg);
		sqlite3_close(db);
		printf("\nAdmin[%s] banned User[%s] success.\n", msg->UserName, msg->RecvUserName);
	}
 
 //是管理员
	else
	{
	msg->cmd = BAN + FAIL;
	ret = send(fd, msg, sizeof(struct message), 0);
	if (ret < 0)
	{
		perror("send(BAN)");
	}
	 /*3、关闭数据库*/
	sqlite3_free(errmsg);
	sqlite3_close(db);
	printf("\nUser[%s] is Admin,cant been banned.\n",msg->RecvUserName);
	return;
	}
}

/*函数作用：处理管理员踢人
*描述：

*输入：无
*返回值：无
*/
void handle_out(int fd, struct message *msg)
{
/******************************************/
 int ret = 0;
 char sql[256] = {0};
 char *errmsg = NULL;
 int admin = 0;

/******************************************/
 /*1、打开数据库*/
 ret = sqlite3_open("chat.db", &db);
 if (ret != SQLITE_OK)
 {
	 printf("sqlite3_open(OUT) error\n");
	 return;
 }

 /*2、是否为管理员*/
 sprintf(sql, "select Admin from user where UserName = '%s';", msg->RecvUserName);
 ret = sqlite3_exec(db, sql, confirm_admin, NULL, &errmsg);
 if (ret == SQLITE_OK)
 {
	 admin = 1;
 }
 else if (ret == SQLITE_ABORT)
 {
	 admin = 0;
 }
 else
 {
	 printf("sqlite3_exec(OUT) error:%s\n",errmsg);
	 msg->cmd = -1;//表示数据库操作失败
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if ( ret < 0)
	 {
		 perror("send(OUT)");
	 }
	 /*3、关闭数据库*/
	 sqlite3_free(errmsg);
	 sqlite3_close(db);
	 return;
 }

 //不是管理员
 if ( admin == 0)
 {
	 msg->cmd = OUT + SUC; //表示被踢出

	 memset(sql, 0, sizeof(sql));
	 sprintf(sql, "select Clientfd from user where UserName = '%s';", msg->RecvUserName);
	 ret = sqlite3_exec(db, sql, send_message, msg, &errmsg);
	 if (ret != SQLITE_OK)
	 {
		 printf("sqlite3_exec(OUT + SUC):%s\n",errmsg);

		 msg->cmd = -1;//表示数据库操作失败
		 ret = send(fd, msg, sizeof(struct message), 0) ;
		 if (ret < 0)
		 {
			 perror("send(OUT + SUC)");
		 }
		 /*3、关闭数据库*/
		 sqlite3_free(errmsg);
		 sqlite3_close(db);
		 return;
	 }

	 sprintf(sql, "update user set Out = '1',Clientfd='-1',Online='0' where UserName = '%s';", msg->RecvUserName);
	 ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	 if (ret != SQLITE_OK)
	 {
		 printf("sqlte3_exec(OUT + SUC):%s\n",errmsg);
		 msg->cmd = -1;
		 ret = send(fd, msg, sizeof(struct message), 0);
		 if (ret < 0)
		 {
			 perror("send(OUT)");
		 }
		 sqlite3_free(errmsg);
		 sqlite3_close(db);
		 return;
	 }
	 /*3、关闭数据库*/
	 sqlite3_free(errmsg);
	 sqlite3_close(db);
	 printf("\nAdmin[%s] kicked User[%s] success.\n\n", msg->UserName, msg->RecvUserName);
 }

 //是管理员
 else
 {
	 //回复客户端
	 msg->cmd = OUT+ FAIL; //表示踢出失败
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if (ret < 0)
	 {
		 perror("send(OUT+ FAIL)");
	 }
	 /*3、关闭数据库*/
	 sqlite3_free(errmsg);
	 sqlite3_close(db);
	 printf("\nUser[%s] is Admin,cant been kicked.\n\n",msg->RecvUserName);
	 return;
 }
 /*3、关闭数据库*/
 sqlite3_close(db);
}

/*函数作用：处理用户传输文件
*描述：

*输入：无
*返回值：无
*/

void handle_SendFile_user(int fd, struct message *msg)
{
	/***************************************/
	int ret = 0;
	char sql[256] = {0};
	char *errmsg = NULL;
	char **result = NULL;
	int rowCount = 0, columnCount = 0;
	int i;
	/**************************************/
	//1、打开数据库
	ret = sqlite3_open("chat.db", &db);
	if (ret != SQLITE_OK)
	{
		 printf("sqlite3_open(SendFile) error.\n");
		 msg->cmd = -1;
		 ret = send(fd, msg, sizeof(struct message), 0);
		 if ( ret < 0)
		 {
			 perror("send(SendFile) ");
		 }
		 return ;
	}
	else
	{
		 printf("\ndatabase open! USER[%s] Sending File 1.\n",msg->UserName);
	}
	//2、用户是否被禁言
	sprintf(sql, "select Ban from user where UserName = '%s';", msg->UserName);
	ret = sqlite3_exec(db, sql, confirm_ban, msg, &errmsg);
	if ( ret == SQLITE_OK )
	{
		 msg->cmd = SENDFILE + BAN;//禁言 
		 ret = send(fd, msg, sizeof(struct message), 0);
		 if (ret < 0)
		 {
			 perror("send(SENDFILE + BAN) error");
		 }

		 sqlite3_free(errmsg);
		 sqlite3_close(db);
		 printf("User[%s] had been banned, can't send File to User[%s].\n\n", msg->UserName,msg->RecvUserName);
		 return;
	}
	else if ( ret != SQLITE_ABORT)//返回0
	{
		 printf("sqlite3_exec(ban) error: %s\n", errmsg);

		 msg->cmd = -1;
		 ret = send(fd, msg, sizeof(struct message), 0);
		 if (ret < 0 )
		 {
			 perror("send(SendFile_ban) ");
		 }
		 sqlite3_free(errmsg);
		 sqlite3_close(db);
		 printf("database closed. sqlite3_exec error.\n\n");
		 return;
	}
	 
	/*3、筛选在线用户*/
	sprintf(sql,  "select * from user where Online = '1' and UserName = '%s';",msg->RecvUserName);
	ret = sqlite3_get_table(db, sql, &result, &rowCount, &columnCount, &errmsg);
	if (ret != SQLITE_OK)
	{
		 printf("sqlite3_get_table(SendFile) error:%s\n",errmsg);
		 msg->cmd = -1;
		 ret = send(fd, msg, sizeof(struct message), 0);
		 if ( ret < 0)
		 {
			 perror("send(SendFile) ");
		 }
		 sqlite3_free(errmsg);
		 sqlite3_free_table(result);
		 sqlite3_close(db);
		 return;
	}

	for (i = columnCount; i < (rowCount + 1) * columnCount; i += columnCount)
	{
	/*4、目标用户存在*/
	  if (!strcmp(result[i], msg->RecvUserName))
	  {
		 //回复客户端，开始进行传输
		 msg->cmd = SENDFILE + SUC;
		 
		 strcpy(msg->RecvUserName,result[i + 3]); 	//直接记录对方的clientfd 
		 sprintf(msg->UserName,"%d",fd); 	//直接记录用户的clientfd
		 
		 ret = send(fd, msg, sizeof(struct message), 0);
		 if(ret < 0)
		 {
			 perror("recv(SENDFILE + ACP)");
		 }
		 /*6、关闭数据库*/
		 sqlite3_free(errmsg);
		 sqlite3_free_table(result);
		 sqlite3_close(db);
		 printf("User[%s] SENDFILE SUC.\n\n", msg->UserName);
		 return;
	 }
	}

	//5、接收方不在线
	 msg->cmd = SENDFILE + FAIL; 
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if(ret < 0)
	 {
		perror("send(SENDFILE + FAIL)");
	 }
	 
	 /*6、关闭数据库*/
	 sqlite3_free(errmsg);
	 sqlite3_free_table(result);
	 sqlite3_close(db);

	 printf("User[%s] Send File failure.\n\n", msg->UserName);

}


/*函数作用：服务器处理SENDFILE + ACP请求
*描述：

*输入：无
*返回值：无
*/
void handle_SendFile_accept(int fd, struct message *msg)
{
/***************************************/
	int ret = 0;
	//msg.cmd = SENDFILE + ACP;
/**************************************/
 //1、打开数据库
 ret = sqlite3_open("chat.db", &db);
 if (ret != SQLITE_OK)
 {
	 printf("sqlite3_open(SendFile) error.\n");
	 msg->cmd = -1;
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if ( ret < 0)
	 {
		 perror("send(SendFile) ");
	 }
	 return ;
 }
 else
 {
	 printf("\ndatabase open! USER[%s] Sending File 2.\n",msg->UserName);
 }

  ret = send(atoi(msg->RecvUserName), msg, sizeof(struct message), 0);
  if ( ret < 0)
  {
	  perror("send(SendFile) ");
  }
  printf("\nAsking Clientfd[%s] Recv File.\n",msg->RecvUserName);
 
}





/*函数作用：在线列表
 *描述：
 
 *输入：无
 *返回值：无
 */
void handle_online(int fd, struct message *msg)
{
/*******************************************/
	int ret = 0;
	char *sql = NULL;
	char *errmsg = NULL;

/*******************************************/
	/*1、打开数据库*/
	ret = sqlite3_open("chat.db", &db);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open(online) error.\n");
		msg->cmd = -1;
		ret = send(fd, msg, sizeof(struct message), 0);
		if ( ret < 0 )
		{
			perror("send(online)");
		}
		return;
	}

	/*2、查询Online = 1的用户*/
	sql = "select UserName from user where Online = '1'";
	ret = sqlite3_exec(db, sql, reply_online, &fd, &errmsg);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec(online) error: %s\n", errmsg);
	}

	/*3、关闭数据库*/
	sqlite3_free(errmsg);
	sqlite3_close(db);
	printf("Send Online User List to User[%s]\n", msg->UserName);
}



/*函数作用：处理用户好友列表
*描述：

*输入：无
*返回值：无
*/
void handle_friend(int fd, struct message *msg)
{
/*******************************************/
 int ret = 0;
 char *sql = NULL;
 char *errmsg = NULL;
 
/*******************************************/
 /*1、打开数据库*/
 ret = sqlite3_open("chat.db", &db);
 if (ret != SQLITE_OK)
 {
	 printf("sqlite3_open(friend) error.\n");
	 msg->cmd = -1;
	 ret = send(fd, msg, sizeof(struct message), 0);
	 if ( ret < 0 )
	 {
		 perror("send(friend)");
	 }
	 return;
 }

 /*2、查询所有用户*/
 sql = "select UserName from user";
 ret = sqlite3_exec(db, sql, reply_online, &fd, &errmsg);
 if (ret != SQLITE_OK)
 {
	 printf("sqlite3_exec(friend) error: %s\n", errmsg);
 }

 /*3、关闭数据库*/
 sqlite3_free(errmsg);
 sqlite3_close(db);
 printf("Send User Friend List to User[%s]\n", msg->UserName);

}



 /*函数作用：（回调函数）用户是否被禁言
 *描述：

 *输入：columnValue（查询出来的数据）
 *输出：若被禁言，回复0
 	    若没有，回复1
 *返回值：无
 */
int confirm_ban(void *para, int columnCount, char **columnValue, char **columnName)
{
	int ban = atoi(columnValue[0]);
	if (ban == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
 /*函数作用：保存聊天记录
 *描述：
 
 *输入：无
 *返回值：无
 */
 void keep_chat(struct message *msg)
{
	/*局部变量*/
	int ret = 0;
	int fd;
	char strTo[100] = "To";
	char strUser[20] = {0};
	char strRecv[20] = {0};

	sprintf(strUser,msg->UserName);		//strUser = UserName
	sprintf(strRecv,msg->RecvUserName);	//strRecv = RecvUserName
	strcat(strUser,strTo);		//UserNameTo
	if(strlen(msg->RecvUserName) == 0)
	{
		strcat(strUser,"ALL");		//UserNameToALL
	}
	else
	{
		strcat(strUser,strRecv);	//UserNameToRecvUserName
	}


	fd = open(strUser,O_WRONLY | O_CREAT | O_APPEND, 666);	//只写，创建，写到末尾
	if (fd == -1)
	{
		perror("open(keep_chat)");
	}

	//时间
	ret = write(fd, msg->Time, strlen(msg->Time));
	 if (ret < 0)
	 {
		 perror("write(keep_chat)");
	 }
	//内容
	ret = write(fd, msg->note, strlen(msg->note));
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


 
 


 /*函数作用：（回调函数）用户是否管理员
 *描述：
 
 *输入：无
 *返回值：无
 */
int confirm_admin(void *para, int columnCount, char **columnValue, char **columnName)
{
	int admin = atoi(columnValue[0]);
	if ( admin == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


 /*函数作用：（回调函数）发送消息指令
 *描述：
 
 *输入：无
 *返回值：无
 */
int send_message(void *para, int columnCount, char **columnValue, char **columnName)
{
/*****************************************************/
	struct message *msg = (struct message *)para;
	int Clientfd = atoi(columnValue[0]);
	int ret = 0;
/*****************************************************/
	ret = send(Clientfd, msg, sizeof(struct message), 0);
	if (ret < 0)
	{
		perror("send_massage");
	}

	return 0;
}

 

 /*函数作用：(回调函数)确认用户密码
 *描述：
 
 *输入：无
 *返回值：无
 */
int confirm_pwd(void *para, int columnCount, char **columnValue, char **columnName)
{
	char *pwd = (char*)para;
	if (!strcmp(columnValue[0], pwd))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

 
 /*函数作用：是否在线
 *描述：
 
 *输入：无
 *返回值：无
 */
int confirm_online(void *para, int columnCount, char **columnValue, char **columnName)
{
	char online = atoi(columnValue[0]);
	if (online == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

 /*函数作用：（回调函数）回复客户端在线用户
 *描述：
 
 *输入：无
 *返回值：无
 */
int reply_online(void *para, int columnCount, char **columnValue, char **columnName)
{
/*********************************/
	int ret = 0;
	int Clientfd = *(int *)para;
	struct message msg;

/*********************************/
	memset(&msg, 0, sizeof(msg));
	strcpy(msg.UserName, columnValue[0]);
	msg.cmd = ONLINE + SUC;

	ret = send(Clientfd, &msg, sizeof(msg), 0);
	if (ret < 0)
	{
		perror("send(online)");
	}

	return 0;
}



 
