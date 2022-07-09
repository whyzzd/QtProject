#include "worker2.h"
#include<QFile>
#include<QDataStream>
#include<QDebug>
#include<QThread>
Worker2::Worker2(QObject *parent) : QThread(parent)
{

}
void Worker2::run()
{
    if((fromfilename=="")&&(tofilename==""))return;
    char* byteTemp = new char[4096];//字节数组
    int fileSize = 0;
    int totalCopySize = 0;
    QFile tofile;
    //ui->progressBar_copy->setValue(0);
    tofile.setFileName(tofilename);
    if(!tofile.open(QIODevice::ReadWrite))
    {
        qDebug() << "open tofile failed！！！";
        return ;
    }
    QDataStream out(&tofile);
    //out.setVersion(QDataStream::Qt_4_8);

    QFile fromfile;
    fromfile.setFileName(fromfilename);
    if(!fromfile.open(QIODevice::ReadOnly)){
        qDebug() << "open fromfile failed！！！";
        return ;
    }
    fileSize = fromfile.size();
    QDataStream in(&fromfile);


    while(!in.atEnd())
    {
        int readSize = 0;
        //读入字节数组,返回读取的字节数量，如果小于4096，则到了文件尾
        readSize = in.readRawData(byteTemp, 4096);
        if(readSize==-1)
        {
            qDebug()<<"read error!!!";
            return;
        }
        int writeSize=out.writeRawData(byteTemp, readSize);
        if(writeSize==-1)
        {
            qDebug()<<"write error!!!";
            return;
        }
        totalCopySize += readSize;
        qDebug()<<"此线程是："<<QThread::currentThreadId()<<" 复制进度:"<<totalCopySize*1./fileSize*100<<"%";
    }

    if(totalCopySize != fileSize){
        qDebug()<<"文件传输未成功";
        return ;
    }
}
