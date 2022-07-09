#include "myserver.h"
#include "ui_myserver.h"
#include<QDebug>
MyServer::MyServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyServer)
{
    ui->setupUi(this);
    setWindowTitle("服务器:8888");

    tcpServer=new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);

    connect(tcpServer,&QTcpServer::newConnection,[=](){
        if(m_N>1)m_N=0;
        int i=m_N++;
        tcpSocketArr[i]=tcpServer->nextPendingConnection();

        QString ip=tcpSocketArr[i]->peerAddress().toString();
        qint16 port = tcpSocketArr[i]->peerPort();
        QString str=QString("客户端[%1:%2]:连接成功").arg(ip).arg(port);
        ui->textEditRead->append(str);
        connect(tcpSocketArr[i],&QTcpSocket::readyRead,[=](){
            temparr = tcpSocketArr[i]->readAll();
            ui->textEditRead->append(temparr);
            moveInfo(i);
        });

        connect(tcpSocketArr[i],&QTcpSocket::disconnected,[=](){

            tcpSocketArr[i]->disconnectFromHost();
            tcpSocketArr[i]->close();
            tcpSocketArr[i]->deleteLater();
            tcpSocketArr[i]=NULL;
            m_N=i;
        });

    });
}

MyServer::~MyServer()
{
    delete ui;
}


void MyServer::on_buttonClose_clicked()
{

    for(int i=0;i<2;i++)
    {
        if(tcpSocketArr[i]!=NULL&&tcpSocketArr[i]->isOpen())
        {
            tcpSocketArr[i]->disconnectFromHost();

        }
    }

}
void MyServer::moveInfo(int num)
{

    //注意此处的范围，要遍历到每一个客户端
    for(int i=0;i<2;i++)
    {
        if(tcpSocketArr[i]!=NULL&&tcpSocketArr[i]->isOpen()&&(i!=num))
        {

            tcpSocketArr[i]->write(temparr);
        }

    }

}
