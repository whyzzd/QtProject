#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget控件
    //设置列数
    ui->tableWidget->setColumnCount(5);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄"<<"身高"<<"体重");
    //设置行数
    ui->tableWidget->setRowCount(7);

    //设置正文内容
    QStringList nameList;
    nameList<<"刘备"<<"关羽"<<"张飞"<<"赵云"<<"安琪拉"<<"张三"<<"李四";
    QList<QString> sexList;
    sexList<<"男"<<"男"<<"男"<<"男"<<"女"<<"男"<<"男";
    QList<QString> heiList;
    heiList<<"180cm"<<"181cm"<<"183cm"<<"182cm"<<"164cm"<<"185cm"<<"186cm";
    QList<QString>weiList;
    weiList<<"70kg"<<"71kg"<<"72kg"<<"73kg"<<"50kg"<<"74kg"<<"75kg";

    for(int i=0;i<7;i++)
    {
      int count=0;
      ui->tableWidget->setItem(i,count++,new QTableWidgetItem(nameList[i])) ;
      ui->tableWidget->setItem(i,count++,new QTableWidgetItem(sexList.at(i))) ;
      ui->tableWidget->setItem(i,count++,new QTableWidgetItem(QString::number(18+i))) ;
      ui->tableWidget->setItem(i,count++,new QTableWidgetItem(heiList.at(i)));
      ui->tableWidget->setItem(i,count++,new QTableWidgetItem(weiList.at(i)));

    }

}

Widget::~Widget()
{
    delete ui;
}

