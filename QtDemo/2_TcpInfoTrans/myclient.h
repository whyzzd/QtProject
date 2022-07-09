#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QWidget>
#include<QTcpSocket>
namespace Ui {
class MyClient;
}

class MyClient : public QWidget
{
    Q_OBJECT

public:
    explicit MyClient(QWidget *parent = nullptr);
    MyClient(const int clinum,const QString ip,const QString port);
    ~MyClient();

private slots:
    void on_buttonConnect_clicked();

    void on_buttonClose_clicked();

    void on_buttonSend_clicked();

private:
    Ui::MyClient *ui;
    QTcpSocket *tcpSocket=NULL;

    QString m_ip;
    QString m_port;
    int m_clinum;
};

#endif // MYCLIENT_H
