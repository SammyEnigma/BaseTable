/*
 *@file:   widget.cpp
 *@author: 缪庆瑞
 *@date:   2016.8.1
 *@brief:  构建程序主窗口
 */
#include "widget.h"
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QDebug>
#include <QComboBox>
#include <QHeaderView>
#include <QFont>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    QList<BaseTableItem *> items;
    items.append(new BaseTableItem(BaseTableItem::TEXT,"设置"));//构造表格的单元格项
    items.append(new BaseTableItem(BaseTableItem::CHECKBOX_TEXT,NULL));
    items.append(new BaseTableItem(BaseTableItem::ICON_TEXT,"图标",":/images/setting2.png"));
    items.append(new BaseTableItem(BaseTableItem::WIDGET,"",NULL,new QLineEdit(),NULL));
    items.append(new BaseTableItem(BaseTableItem::WIDGET,"",NULL,new QCheckBox(),NULL));
    items.append(new BaseTableItem(BaseTableItem::WIDGET_WIDGET,"",NULL,new QLineEdit(),new QPushButton("hello")));
    items.append(new BaseTableItem(BaseTableItem::WIDGET_WIDGET,"",NULL,new QLineEdit(),new QCheckBox()));
    items.append(new BaseTableItem(BaseTableItem::WIDGET,"",NULL,new QComboBox()));

    baseTableWidget = new BaseTableWidget(1,2,items,true,this);//构建表格
    baseTableWidget->setColWidthRowHeight(100,40);
    baseTableWidget->setHeaderVisible(true);
    QStringList names;
    names<<"aaa"<<"bbb"<<"cccc"<<"ddd";
    baseTableWidget->setHeaderLabels(names,true);
    baseTableWidget->resize(300,200);
    //baseTableWidget->setItemDelegate(new BasetableDelegate(this));

    baseTableWidget->setNormalStyle("white","black");//设置样式
    baseTableWidget->setPressStyle("white","black");
    baseTableWidget->setReleaseStyle("white","black");

    //test
    QPushButton *btn = new QPushButton("button",this);
    btn->setGeometry(200,200,60,40);
    connect(btn,SIGNAL(clicked()),this,SLOT(btnSlot()));
    QPushButton *btn2 = new QPushButton("button2",this);
    btn2->setGeometry(200,300,60,40);
    connect(btn2,SIGNAL(clicked()),this,SLOT(btnSlot2()));
}

Widget::~Widget()
{
}

void Widget::btnSlot()
{
    QPushButton *btn = new QPushButton("button3",this);
    BaseTableItem *item = new BaseTableItem(BaseTableItem::WIDGET,"",NULL,btn,NULL);
    baseTableWidget->setItemContent(1,0,item);
}

void Widget::btnSlot2()
{
    qDebug()<<baseTableWidget->getItemCheckstate(0,1);
}
