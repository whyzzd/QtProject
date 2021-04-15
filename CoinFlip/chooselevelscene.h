#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include<playscene.h>
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);



    // QWidget interface
     //重写绘图事件
    void paintEvent(QPaintEvent *);

    //维护一个play场景的指针
    PlayScene *playse = NULL;
signals:

    //写一个自定义的信号，主场景进行接收
    void chooseSceneBack();



};

#endif // CHOOSELEVELSCENE_H
