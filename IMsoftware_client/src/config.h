#ifndef CONFIG_H
#define CONFIG_H

#include "singleton.h"
#pragma execution_character_set("utf-8")

#include <QString>
#include <QVector>
#include <QDebug>


class Config:public Singleton<Config>
{
public:
    ~Config();

    QVector<QString> skinColors;//系统定义的皮肤背景颜色


protected:
      friend class Singleton<Config>;
      Config();

private:
      void initColors();
};

//宏定义来获取配置
#define SYSTEM_CONFIG  Config::getInstance()

#endif // CONFIG_H
