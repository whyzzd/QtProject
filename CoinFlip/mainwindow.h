#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mypushbutton.h"
#include"chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //维护一个选择关卡的对象指针
    ChooseLevelScene *chooseScene=NULL;


    void paintEvent(QPaintEvent*);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
