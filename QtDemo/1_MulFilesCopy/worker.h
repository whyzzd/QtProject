#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include<QList>
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);


signals:

public slots:

    void copyFile(const QString fromfilename,const QString tofilename);
};

#endif // WORKER_H
