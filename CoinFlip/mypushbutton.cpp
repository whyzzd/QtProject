#include "mypushbutton.h"
#include<QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}
MyPushButton::MyPushButton(QString normalImg,QString pressImg)//默认参数只能有一处有
{
    this->m_NormalImgPath=normalImg;
    this->m_PressImgPath=pressImg;

    //常见pixmap对象，来接受路径
    QPixmap pix;
    pix.load(this->m_NormalImgPath);

    //设置图片固定尺寸
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);

    //设置图标尺寸
    this->setIconSize(QSize(pix.width(),pix.height()));
}
void MyPushButton::setMysize(int wid,int hgt)
{
    this->setFixedSize(wid,hgt);
    this->setIconSize(QSize(wid,hgt));
}
//向下跳跃
void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation *animation1=new QPropertyAnimation(this,"geometry");
    //设置事件间隔 ，单位毫秒
    animation1->setDuration(200);

    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //设置缓和曲线，QEasingCurve::OutBounce为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}

//向上跳跃
void MyPushButton::zoom2()
{
    //创建动画对象
    QPropertyAnimation *animation1=new QPropertyAnimation(this,"geometry");
    //设置事件间隔 ，单位毫秒
    animation1->setDuration(200);

    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));

    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置缓和曲线，QEasingCurve::OutBounce为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}
//设置鼠标按下事件
void MyPushButton::mousePressEvent(QMouseEvent *event)
{
    if(this->m_PressImgPath!="")
    {
        QPixmap pix(this->m_PressImgPath);
        setIcon(pix);

    }
    //剩下的交给父类去处理
    return QPushButton::mousePressEvent(event);
}
//设置鼠标释放事件
void MyPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->m_PressImgPath!="")
    {
        QPixmap pix(this->m_NormalImgPath);
        setIcon(pix);

    }
    return QPushButton::mouseReleaseEvent(event);
}
