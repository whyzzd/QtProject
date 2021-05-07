#include "mycoin.h"
#include<QPixmap>
#include<QDebug>
//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}
MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    int res=pix.load(btnImg);
    if(!res)
    {
        QString str=QString("金币%1加载失败").arg(btnImg);
        qDebug()<<str;
        return;
    }

    //设置固定宽高
    this->setFixedSize(45,45);
    //设置按钮样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(45,45));

    //初始化两个定时器
    this->timer1=new QTimer(this);
    this->timer2=new QTimer(this);

    //监听计时器，以改变硬币
    connect(timer1,&QTimer::timeout,[=](){
        QString str1=QString(":/Image/Coin000%1.png").arg(this->m_Min++);
        QPixmap pix(str1);
        this->setIcon(pix);
        if(this->m_Min>8)
        {
            this->m_Min=1;
            timer1->stop();
            //设置结束动画状态
            this->isAnimation=false;
        }
    });

    connect(timer2,&QTimer::timeout,[=](){
        QString str1=QString(":/Image/Coin000%1.png").arg(this->m_Max--);
        QPixmap pix(str1);
        this->setIcon(pix);
        if(this->m_Max<1)
        {
            this->m_Max=8;
            timer2->stop();
            //设置结束动画状态
            this->isAnimation=false;
        }
    });
}
void MyCoin::changFlag()
{
    if(this->flag)
    {
        //如果为真，那么就将flag变为假并启动第一个定时器
        this->flag=false;
        this->timer1->start(50);
        //设置开始动画状态
        this->isAnimation=true;
    }
    else
    {
        this->flag=true;
        this->timer2->start(30);
        this->isAnimation=true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *event)
{
    //动画开始的时候或者已经胜利的时候，不能使动画生效
    //以下方式中，前者仅禁用当前按钮，其他位置依旧可以点击，
    //因此可在硬币开始点击后就立刻将点击禁用，然后在硬币翻完之后再将点击放开
    if(this->isAnimation||this->isWin)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(event);
    }
}
