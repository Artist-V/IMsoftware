#ifndef SQL_H
#define SQL_H

#include "/usr/include/mysql/mysql.h"

enum CHECK
{
	FAIL = 0x12,	/*失败*/
	SUCS,			/*成功*/
	ERROR 			/*出错*/
};

//全局变量
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;
unsigned int num_fields = 0;
/*输出错误码，退出*/
void sql_sys_error(char *errstr)
{
	fprintf(stderr,"%s error:%s\n\a",errstr,strerror(errno));
	exit(1);
}
/*输出错误码，返回ERROR*/
int return_error(char *errstr, char* sql)
{
	fprintf(stderr,"%s:sql[%s]\n\a",errstr,sql);
	return ERROR;
}
/*连接数据库*/
void connect_db()
{
	char *server = "localhost";
	char *user = "root";
	char *password = "root";  
	char *database = "IM";
 
	conn = mysql_init(NULL);
	if (!mysql_real_connect(conn,server,user, password, database, 0, NULL, 0)) 
	{
		sql_sys_error("连接数据库");
	}

	printf("connect database success...\n");

}
/*创建表*/
int create_table(char *t_name)
{
	if ((NULL == t_name) || (NULL == conn))
    {
        return return_error("创建表:t_name或conn为null","0");
    }
	if(strcmp(t_name,"user") == 0)
	{
		char *sql = "create table if not exists user(\
		uid int(12) primary key, \
		uname varchar(15) not null,\
		upwd varchar(12) not null,\
		nquestion int(4) not null,\
		uanser varchar(10),\
		ustate int(4) not null default '0',\
		usignature varchar(255) default '编辑个性签名'\
		);";

		if (mysql_query(conn, sql) != 0)
		{
			return return_error("创建user表失败!",sql);
		}
		printf("create table[%s] success...\n",t_name);
	}
	return 1;
}

/*查询数据（1 or 0）*/
int check_index(char *sql)
{
	if (mysql_query(conn, sql) != 0)
	{
		return return_error("查询出错(sql语句出错)",sql);
	}
	
	else
	{
		//return SUCS;
		
		res = mysql_use_result(conn);
		if(res)
		{
			if((row = mysql_fetch_row(res)) == NULL)//查询成功，处理查询返回的数据
			{
				mysql_free_result(res);
				return FAIL;
			}
			else
			{
				mysql_free_result(res);
				return SUCS;
			}
		}
		else
		{
			return return_error("mysql_use_result",sql);
		}	
		
	}
}
/*查询数据（结果）*/
int query_index(char *sql,char *sign,char *icon)
{
	if (mysql_query(conn, sql) != 0)
	{
		return return_error("查询失败!",sql);
	}
	else
	{
		res = mysql_use_result(conn);
		if(res)
		{
			int i = 0;
			num_fields = mysql_field_count(conn);	//字段数
			
			if((row = mysql_fetch_row(res)) != NULL)	//行
			{
				strcpy(sign,row[0]);
				strcpy(icon,row[1]);
			}
			printf("查询结果:%s  %s \n",sign,icon);
			mysql_free_result(res);
			return SUCS;
		}
		else
		{
			return return_error("mysql_use_result",sql);
		}	
	}
}
/*插入、删除*/
int insert_index(char *sql)
{
	if (mysql_query(conn, sql) != 0)
	{
		return return_error("插入字段失败!",sql);
	}
	printf("插入字段成功...\n");

	return SUCS;
}
int delete_index(char *sql)
{
	if (mysql_query(conn, sql) != 0)
	{
		return return_error("删除数据失败!",sql);
	}
	printf("删除数据成功...\n");

	return SUCS;
}

#endif //SQL_H
