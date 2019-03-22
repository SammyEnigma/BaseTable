/*
 *@file:   basetabledelegate.h
 *@author: 缪庆瑞
 *@date:   2018.8.10
 *@brief:  basetablewidget的委托(代理)类，提供输入功能和渲染view(表格)中的每个数据项
 *
 * 该委托类继承自QStyledItemDelegate,也可以继承QItemDelegate ,Qt Assistant建议用户最好继承自
 * QStyledItemDelegate.这两个类在绘制代理和为item提供编辑器上面是独立的,没什么联系,互不影响;
 * 不同的是QStyledItemDelegate使用当前style来绘制item(的代理),即如果程序设置了总体的风格(用QSS或
 * 其他定义方式)QStyledItemDelegate会使用这个风格设置.
 *
 * delegate(委托)建立在model/view上,负责管理用户交互,而view仅仅作为model数据的展示和简单用户
 * 输入处理.可以通过该类实现对view(表格)显示的自定义，表格可以只负责数据，而让委托类完成显示处理。
 *
 * 不过由于BaseTableWidget在设计初并没有考虑委托，针对表项外观采用的是样式表方式，与委托类的paint
 * 函数可能会有冲突。所以目前针对表格的一些简单功能和外观设计就不使用委托类，当样式表实在解决不了
 * 复杂的交互及外观设计时，再使用委托类。
 *
 *
 */
#ifndef BASETABLEDELEGATE_H
#define BASETABLEDELEGATE_H

#include <QObject>
#include <QApplication>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QSpinBox>

//使用自定义代理渲染view item
#define USE_CUSTOM_PAINT
//使用自定义代理编辑器
#define USE_CUSTOM_EDITOR

class BasetableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    BasetableDelegate(QObject *parent=0);
    ~BasetableDelegate();
#ifdef USE_CUSTOM_EDITOR
    /*提供自定义的输入功能,需要表格设置为可编辑状态,且表项非cellWidget*/
    //创建自定义的编辑部件，双击表项就会展示这里创建的部件
    QWidget *createEditor(QWidget * parent, const QStyleOptionViewItem & option,
                             const QModelIndex & index) const;
    //从model中取数据填到代理编辑器中
    void setEditorData(QWidget *editor, const QModelIndex &index) const ;
    //将编辑器设置的数据写入到model中
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const ;
    //设置编辑器的显示位置以及样式
    void updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,
                              const QModelIndex &index) const ;
    //判断表项是否需要自定义代理编辑器
    bool isNeedCustomEdit(const QModelIndex &index) const;
#endif

#ifdef USE_CUSTOM_PAINT
    /*view 表项外观渲染*/
    //绘制渲染view item(表项)外观,可以调用QStyle中的函数绘制，也可以使用QPainter的函数绘制
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                   const QModelIndex &index) const ;
    //判断表项是否需要自定义代理渲染绘制
    bool isNeedCustomPainter(const QModelIndex &index) const;
#endif

signals:

public slots:

private:

};

#endif // BASETABLEDELEGATE_H
