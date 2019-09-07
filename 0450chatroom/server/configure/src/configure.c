/*
 * main.c
 *
 *  Created on: 2011-7-27
 *      Author:
 */

#include "../../include/myhead.h"


/*函数作用：配置服务器
 *描述：初始化服务器信息
  	    创建socket
  	    绑定
		监听（最大同时监听数5）
 *输入：无
 *返回值：无
 */
void ConfigureServer()
{
	int  ret;

	//服务器  server
	struct sockaddr_in server;
	//设置服务器信息
	bzero(&server,sizeof(server));
	server.sin_family = PF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr(INET_ADDR);

	//创建socket
	socketfd = socket(PF_INET, SOCK_STREAM, 0);
	if (socketfd < 0)
	{
		perror("socketfd");
		exit(1);
	}


	//绑定
	ret = bind(socketfd, (struct sockaddr *)&server, sizeof(server));
	if (ret < 0)
	{
		perror("bind");
		exit(1);
	}

	//监听
	ret = listen(socketfd, 5);//设置最大同时监听数为5
	if (ret < 0)
	{
		perror("listen");
		exit(1);
	}

	printf("configure server success!\n");

}


/*函数作用：连接数据库user表
 *描述：
 
 *输入：无
 *返回值：无
 */
void ConnectDatabase_user()
{
	int ret = 0;
	char *sql = NULL;
	char *errmsg = NULL;
	char **result = NULL;
	int row = 0, column = 0;

	//打开数据库
	ret = sqlite3_open("chat.db", &db);
	if(ret != SQLITE_OK)
    {
        printf("sqlite3_open error:%s\n",sqlite3_errmsg(db));
		sqlite3_free(errmsg);
		sqlite3_close(db);
        exit(1);
    }

	//表USER
	sql = "create table if not exists user(UserName TEXT, pwd TEXT, Online INTEGER, Clientfd INTEGER, Admin INTEGER,Ban INTEGER, Out INTEGER, primary key(UserName))";
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec(table) error:%s\n",errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(db);
        exit(1);
    }


	//查询表内记录
	//sql = "select count(UserName) from user";
	sql = "select * from user";
	ret = sqlite3_get_table(db, sql, &result, &row, &column, &errmsg);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_get_table error:%s\n", errmsg);
		sqlite3_free(errmsg);
		sqlite3_free_table(result);
		sqlite3_close(db);
		exit(1);
	}

	//表内无记录
	if (row == 0)
	{
		//添加管理员
		sql = "insert into user values('admin', 'admin', 0, -1, 1, 0, 0)";
		ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
		if (ret != SQLITE_OK)
		{
			printf("sqlite3_exec(admin) error:%s\n",errmsg);
			sqlite3_free(errmsg);
			sqlite3_free_table(result);
			sqlite3_close(db);
			exit(1);
		}
	}

	sqlite3_free(errmsg);
	sqlite3_free_table(result);
	sqlite3_close(db);
	printf("configure database user success!\n");

}

