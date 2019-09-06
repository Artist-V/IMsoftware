#ifndef HEAD_H
#define HEAD_H

#include <QStringList>

typedef struct message
{
    char name[20];		//注册：用户名
    char toname[20];	//私聊：发给谁 / 密保答案
    char msg[1024];		//消息：发送信息 / 密码
    char usign[1024];   //个性签名
    int uid;    //用户ID
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

//操作回执
enum CHECK
{
    FAIL = 0x12,
    SUCS,
    ERROR
};



const QStringList icons = {
    ":/icon/photo/p1.png",":/icon/photo/p2.png",
    ":/icon/photo/p3.png",":/icon/photo/p4.png",
    ":/icon/photo/p5.png",":/icon/photo/p6.png"
};

typedef struct myfriend{
    QString name;
    QString sign;
    int icon;
}fri_t;


#endif // HEAD_H
