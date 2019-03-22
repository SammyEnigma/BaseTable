/*
 *@file:   basetableitem.h
 *@author: 缪庆瑞
 *@date:   2016.8.8
 *@brief:  存放item单元格数据
 */
#ifndef BASETABLEITEM_H
#define BASETABLEITEM_H
#include <QString>
#include <QWidget>

class BaseTableItem
{
public:
    enum ItemContentType{
                    TEXT,  //只设置文本
                    CHECKBOX_TEXT,   //带复选框的文本
                    ICON_TEXT,   //带图标的文本
                    WIDGET,     //设置一个控件
                    WIDGET_WIDGET    //设置两个控件
    };
    BaseTableItem(ItemContentType itemContentType);
    BaseTableItem(ItemContentType itemContentType,QString text,QString iconAddr="",QWidget *widget1=NULL,QWidget *widget2=NULL);

    void setItemType(ItemContentType itemContentType){this->itemContentType = itemContentType;}
    void setItemText(QString text){this->text = text;}
    void setItemIcon(QString iconAddr){this->iconAddr = iconAddr;}
    void setItemWidget1(QWidget *widget1){this->widget1 = widget1;}
    void setItemWidget2(QWidget *widget2){this->widget2 = widget2;}

    QString text;//存放单元格显示文本
    QString iconAddr;//存放图标路径
    QWidget *widget1;//存放部件
    QWidget *widget2;
    ItemContentType itemContentType;//存放item类型

};

#endif // BASETABLEITEM_H
