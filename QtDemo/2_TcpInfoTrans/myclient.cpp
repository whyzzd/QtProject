#include "myclient.h"
#include "ui_myclient.h"
#include<QHostAddress>
MyClient::MyClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyClient)
{
    ui->setupUi(this);
}

MyClient::MyClient(const int clinum,const QString ip,const QString port):
    ui(new Ui::MyClient),m_ip(ip),m_port(port),m_clinum(clinum)
{
    ui->setupUi(this);
    setWindowTitle(QString("客户端")+QString::number(clinum));
    ui->lineEditIp->setText(m_ip);
    ui->lineEditPort->setText(m_port);

    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
        ui->textEditRead->setText(QString("客户端%1:连接服务器成功！").arg(clinum));
    });

    connect(tcpSocket,&QTcpSocket::readyRead,[=]{
        QByteArray arr = tcpSocket->readAll();
        ui->textEditRead->append(arr);
    });

    connect(tcpSocket,&QTcpSocket::disconnected,[=](){
        on_buttonClose_clicked();
    });
}
MyClient::~MyClient()
{
    delete ui;
}

void MyClient::on_buttonConnect_clicked()
{
    qint16 port=m_port.toInt();

    if(tcpSocket->isOpen())
        return;
    tcpSocket->connectToHost(QHostAddress(m_ip),port);

}

void MyClient::on_buttonClose_clicked()
{


    if(!tcpSocket->isOpen())
    {
        return;
    }

    tcpSocket->disconnectFromHost();
    tcpSocket->close();

}

void MyClient::on_buttonSend_clicked()
{

    if(!tcpSocket->isOpen())
        return;
    QString str=QString("客户端%1：").arg(m_clinum)+ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
    ui->textEditRead->append(str);
    ui->textEditWrite->clear();
}
