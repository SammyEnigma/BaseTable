/*
 *@file:   widget.h
 *@author: 缪庆瑞
 *@date:   2016.8.1
 *@brief:  widget的头文件
 */
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "basetablewidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void btnSlot();
    void btnSlot2();

private:
    BaseTableWidget *baseTableWidget;
};

#endif // WIDGET_H
