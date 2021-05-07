#include "chooselevelscene.h"
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QLabel>
#include"playscene.h"
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置场景

    //设置固定大小
    setFixedSize(320,600);

    //设置图标
    this->setWindowIcon(QPixmap(":/Image/CoinIco.png"));

    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单栏
    QMenuBar *bar=menuBar();
    setMenuBar(bar);
    QMenu *startMenu=bar->addMenu("开始");

    QAction* quit=startMenu->addAction("退出");

    connect(quit,&QAction::triggered,[=](){
        this->close();
    });

    //返回按钮设置
    MyPushButton *mybtn=new MyPushButton(":/Image/BackButton.png",":/Image/BackButtonSelected.png");
    mybtn->setParent(this);
    mybtn->setMysize(50,50);
    mybtn->move(this->width()-65,this->height()-65);
    //设置按钮事件
    connect(mybtn,&QPushButton::clicked,[=](){

        //发送要返回主场景的信号
        emit this->chooseSceneBack();
    });

    //创建关卡按钮
    for(int i=0;i<20;i++)
    {
        MyPushButton *mybtn=new MyPushButton(":/Image/LevelIcon.png");
        mybtn->setParent(this);
        mybtn->setMysize(40,40);
        mybtn->move(35+i%4*70,130+i/4*70);
        //监听按钮的点击事件
        connect(mybtn,&QPushButton::clicked,[=](){
//            QString str=QString("你当前点击的是第%1个按钮").arg(i+1);
//            qDebug()<<str;


            playse=new PlayScene(i+1);

            playse->setGeometry(this->geometry());
            this->hide();
            playse->show();
            //监听选择play场景中发出的返回信号
            connect(this->playse,&PlayScene::playSceneBack,[=](){
                this->setGeometry(playse->geometry());
                delete this->playse;
                this->playse=NULL;
                this->show();
            });

         });


        //在图标上直接写文字效果不如 用label表示
        QLabel *label=new QLabel;
        label->setParent(this);
        label->setFixedSize(mybtn->width(),mybtn->height());
        label->setText(QString::number(i+1));
        label->move(35+i%4*70,130+i/4*70);

        //设置label上的文字居中
        label->setAlignment(Qt::AlignCenter);
        //只做到这一步，发现点击是没有效果的
        //还需要设置让鼠标穿透label
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}
void ChooseLevelScene::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    //画背景图片
    QPixmap pix(":/Image/OtherSceneBg.png");//也可以后面再加载对象
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画标题图片
    pix.load(":/Image/Title.png");
    pix=pix.scaled(pix.width()*0.3,pix.height()*0.3);
    painter.drawPixmap((this->width()-pix.width())*0.5,-70,pix.width(),pix.height(),pix);

}

