#ifndef MYSERVER_H
#define MYSERVER_H
#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MyServer; }
QT_END_NAMESPACE

class MyServer : public QWidget
{
    Q_OBJECT
public:
    MyServer(QWidget *parent = nullptr);
    ~MyServer();

    //转发消息
    void moveInfo(int num);

private slots:
    void on_buttonClose_clicked();

private:
    Ui::MyServer *ui;
    QTcpServer *tcpServer=NULL;
    QTcpSocket *tcpSocketArr[2]={NULL};
    QByteArray temparr;


    int m_N=0;

};
#endif // MYSERVER_H
