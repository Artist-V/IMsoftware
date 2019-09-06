#ifndef MYHEAD_H
#define MYHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <errno.h>

#include "./online_link.h"

#define PORT (9090)	//TCP	
#define PORT_UDP (9091)	//UDP
#define BUF_MAX (1024)
#define EV_MAX (1000)
#define SQL_MAX (256)


typedef struct message
{
    char name[20];		//注册：用户名
    char toname[20];	//私聊：发给谁 / 密保答案
    char msg[1024];		//消息：发送信息 / 密码
    char usign[1024];   //个性签名
    int uid;	//用户ID
    int qus;    //密保问题
    int icon;   //头像（1-6）
    int action;	//动作（1-2）
    int check;  //操作回执
}msg_t;
enum cmd
{
    REG = 0x1111, //注册
    LOG,        //登录
    SEND,       //私聊
    ALL,        //群里
    EXIT,       //退出
    FRI			//好友
};

typedef struct ptread_arg
{
	int fd;
	msg_t *msg;
}arg_t;


//全局变量
user_t head;

int socketfd;				//TCP
struct sockaddr_in server_addr,client_addr;	//TCP
socklen_t sockaddr_len = sizeof(struct sockaddr_in);  //sockaddr_in 

#endif  //MYHEAD_H



