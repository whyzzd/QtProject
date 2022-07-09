#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QThread>
#include<worker.h>
#include<worker2.h>
#include<QVector>
#include<QList>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QVector<Worker*>workergroup;
    QVector<QThread*>threadgroup;

    QStringList ffilename;
    QStringList tfilename;

signals:
    void startCopy(const QString fromfilename,const QString tofilename);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
