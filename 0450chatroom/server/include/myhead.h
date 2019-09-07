/*
 * myhead.h
 *
 *  Created on: 2019.04.22
 *      Author: 谢昕贝
 */

#ifndef MYHEAD_H_
#define MYHEAD_H_

#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sqlite3.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 9090					/*端口号*/
#define INET_ADDR  "192.168.1.134"	/*服务器地址*/

/*全局变量*/
int socketfd;//监视的socket
sqlite3 *db;
pthread_mutex_t mutex; 		/*	互斥锁 					*/



/* 定义一个结构体：封装消息 */
struct message
{
	char note[1024];	   //信息 	   /密码
	char UserName[20];	   //用户名 /发送用户名 /
	char RecvUserName[20]; //接收用户
	char Time[20];         //时间
	int  cmd;	           //操作指令
};


/*操作指令*/

/*操作指令*/
enum command 
{
	EXIT=0x30,	//退出
	REGISTER,	//注册
	LOGIN,		//登录
	PRIVATE,	//私聊
	GROUP,		//群聊
	ONLINE, 	//查看在线用户
	HISTORY,	//查看聊天记录
	NOTICE, 	//上线提醒
	PWD,		//修改密码
	ADMIN,	    //管理员登录
	BAN,		//禁言
	RELEASEBAN, //解除禁言
	OUT,		//踢人
	SENDFILE,	//发文件
	LOGOUT,		//注销
	FRIEND,		//好友列表
	
	SUC = 1000,		//成功
	FAIL = 2000,	//失败
	ACP = 3000,		//接收
	REP = 4000,		//重复
	ALR	= 5000,		//已登录 / 已完成
	RE = 6000,		//回复
	REMOVE = 7000	//解除
	
};



/*函数声明*/
//1、configure
void ConfigureServer();//配置服务器 √
void ConnectDatabase_user();//连接数据库(用户表) √

//2、handle
void handle_register(int , struct message *);//处理注册 √
void handle_login(int , struct message *);//处理登录√
void handle_exit(int *, fd_set *, struct sockaddr_in );//退出√
void handle_logout(int , struct message *);//处理注销登录√
void handle_PrivateChat(int ,struct message *);//私聊√
void handle_GroupChat(int , struct message *);//群聊√
void handle_notice(int , struct message *);//上线提醒√
void handle_online(int , struct message *);//在线人数√
void handle_pwd(int , struct message *);//修改密码√
void handle_logout(int , struct message *);//注销√
void handle_ban(int , struct message *);//禁言（管理员）√
void handle_out(int , struct message *);//踢人（管理员）√
void handle_friend(int , struct message *);//好友列表
void handle_SendFile_user(int fd, struct message *msg);//传文件 √
void handle_SendFile_accept(int fd, struct message *msg);//服务器处理SENDFILE + ACP请求




void keep_chat(struct message *);//保留聊天记录√
int reply_online(void *, int , char **, char **);//回复在线用户√
int confirm_ban(void *, int , char **, char **);//禁言√
int confirm_admin(void *, int , char **, char **);//管理员√
int send_message(void *, int , char **, char **);//发送消息指令√
int confirm_pwd(void *, int , char **, char **);//密码√
int confirm_online(void *, int , char **, char **);//在线√


#endif /* MYHEAD_H_ */
