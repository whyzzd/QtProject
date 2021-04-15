#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImg,QString pressImg="");

    //设置我自己的图片尺寸
    void setMysize(int wid,int hgt);

    //向下跳跃
    void zoom1();
    //向下跳跃
    void zoom2();
    //设置鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //设置鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);



    QString m_NormalImgPath;
    QString m_PressImgPath;
signals:





};

#endif // MYPUSHBUTTON_H
