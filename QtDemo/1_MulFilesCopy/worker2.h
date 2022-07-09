#ifndef WORKER2_H
#define WORKER2_H

#include <QObject>
#include<QThread>
class Worker2 : public QThread
{
    Q_OBJECT
public:
    explicit Worker2(QObject *parent = nullptr);

    void run();

    QString fromfilename="";
    QString tofilename="";

signals:

};

#endif // WORKER2_H
