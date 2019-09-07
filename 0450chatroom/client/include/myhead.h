/*
 * myhead.h
 *
 *  Created on: 2019.4.22
 *      Author: 谢昕贝
 */

#ifndef MYHEAD_H_
#define MYHEAD_H_

#include <stdio.h>
#include <sqlite3.h>

#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sqlite3.h>
#include <signal.h>
#include <termios.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>



#define NOTE_MAX 1024
#define Name_Max 20

#define PORT 9090						/*端口号		*/
#define INET_ADDR  "192.168.1.134"		/*服务器地址*/


/* 定义一个结构体：封装消息 */
struct message
{
	char note[NOTE_MAX];	   		/* 聊天内容  		 /密码     */
	char UserName[Name_Max];	  	/* 用户名			    	 */		
	char RecvUserName[Name_Max]; 	/* 聊天的目标(用户名/ALL)*/	
	char Time[Name_Max];         	/* 聊天时间         /文件名 	 */	
	int  cmd;	           			/* 操作指令					 */
};

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

/*全局变量*/
struct sockaddr_in server;
int socketfd;				/*	套接字：服务器文件描述符*/
sqlite3 *db;				/*	数据库描述符			  		*/
char User[20];				/*	客户端当前用户				    */
int flag_pthread; 			/*	线程退出标记			 		*/
pthread_mutex_t mutex; 		/*	互斥锁 					*/
pthread_t tid_listen;		/*	监听线程				    */
/*	共享内存		*/
int shmid;
char *ptr;





/*函数声明*/
//1、configure
void ConfigureClient();//配置客户端 √
void welcome();//聊天室欢迎界面 √
void login_welcome();//登陆界面 √
void user_welcome();//普通用户登陆界面√
void admin_welcome();//管理员登陆界面√
void chat_help();//聊天手册

//2、listen_server
void * listen_sever(void *arg);//监听服务器发送的消息 TO 后台线程√



//3、user
void user_register(); //注册 √
int user_login();//登录√
void user_exit();//退出√
void user_PrivateChat();//私聊√
void user_GroupChat();//群聊√
void user_online();//上线提醒√
void user_history();//历史记录√
void user_SendFile();//传输文件√
void user_pwd();//修改密码 √
void user_logout();//注销√
void user_ban();//禁言√
void user_out();//踢人√
void user_friend();//好友列表


void chatroom(int ret);//普通用户 | 管理员√
void user_chatroom();//普通用户处理登录√
void admin_chatroom();//管理员处理登录√
void countdown();//倒计时3秒√
int keep_file(int *, struct message *, int);//接收文件√
void getTime(char *);//时间√
void keep_chat(struct message );//聊天记录√
void handle_chat(struct message *,char *);//处理聊天内容
void pwd_hide(char *key_in, int size);//密码隐式显示
void handle_sendfile();//传输文件



#endif /* MYHEAD_H_ */
