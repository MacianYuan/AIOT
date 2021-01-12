/******************************************************************************************
*-----First Created. time: 11-Jan-2021	10:30  A.m.
* @File name    :main.cpp
* @Platform     :Hi3520DV300 - linux-3.0.8 - Qt5.12.7 - arm-hisiv300-linux-gcc
* @Author       :MacianYuan
* @E-mail       :macian@foxmail.com
* @Project      :农机作业远程监控终端
*******************************************************************************************
* @Description  :
* @Attention    :
* @Log          :
*****************11-Jan-2021(MacianYuan):框架
*****************
* @Copyright© @MacianYuan Anhui Xinjie Technology Co.,Ltd.   All rights reserved.
******************************************************************************************/
#include "mainwindow.h"
#include <QApplication>
#include "hisivio.h"
#include "hisiservice.h"


int main(int argc, char *argv[])
{
    HisiService *m_phisiservice = new HisiService;
    m_phisiservice->start();
    sleep(5);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
