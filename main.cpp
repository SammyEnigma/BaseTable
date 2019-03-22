/*
 *@file:   main.cpp
 *@author: 缪庆瑞
 *@date:   2016.8.1
 *@brief:  主程序入口文件
 */
#include "widget.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //为QT4版本设置编码格式
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    Widget w;
    w.show();

    return a.exec();
}
