#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(400,150);
}

Widget::~Widget()
{
    delete ui;
    for(int i=0;i<threadgroup.size();i++)
    {
        threadgroup[i]->quit();
        threadgroup[i]->wait();
    }
}


void Widget::on_pushButton_clicked()
{
    //获取待复制文件
    ffilename=QFileDialog::getOpenFileNames(this);

    //获取目标文件夹路径
    QString str=QFileDialog::getExistingDirectory(this);

    //获取每个文件的路径，存放至tfilename中
    for(int i=0;i<ffilename.size();i++)
    {
        QFileInfo info= QFileInfo(ffilename.at(i));
        QString name=info.fileName();
        tfilename<<str+"/"+name;
    }

    for(int i=0;i<ffilename.size();i++)
    {
        Worker *worker=new Worker;
        workergroup.push_back(worker);
        QThread *thread=new QThread(this);
        threadgroup.push_back(thread);
        worker->moveToThread(thread);

        connect(this,&Widget::startCopy,worker,&Worker::copyFile);
        connect(thread,&QThread::finished,worker,&Worker::deleteLater);
        thread->start();
        emit startCopy(ffilename.at(i),tfilename.at(i));

    }
}

void Widget::on_pushButton_2_clicked()
{
    //获取待复制文件
    ffilename=QFileDialog::getOpenFileNames(this);

    //获取目标文件夹路径
    QString str=QFileDialog::getExistingDirectory(this);

    //获取每个文件的路径，存放至tfilename中
    for(int i=0;i<ffilename.size();i++)
    {
        QFileInfo info= QFileInfo(ffilename.at(i));
        QString name=info.fileName();
        tfilename<<str+"/"+name;
    }

    for(int i=0;i<ffilename.size();i++)
    {
        Worker2 *worker2=new Worker2(this);
        worker2->fromfilename=ffilename[i];
        worker2->tofilename=tfilename[i];
        worker2->start();


    }
}
