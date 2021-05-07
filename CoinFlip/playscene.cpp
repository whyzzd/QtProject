#include "playscene.h"
#include<QDebug>
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include<QFont>
#include<QPixmap>
#include"gameconfig.h"
#include<QPropertyAnimation>
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}
PlayScene::PlayScene(int levelNum)
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

    this->m_LevelNum=levelNum;
    QString str=QString("当前选择的关卡是%1关").arg(levelNum);
    qDebug()<<str;

    //返回按钮设置
    MyPushButton *mybtn=new MyPushButton(":/Image/BackButton.png",":/Image/BackButtonSelected.png");
    mybtn->setParent(this);
    mybtn->setMysize(50,50);
    mybtn->move(this->width()-65,this->height()-65);
    //设置按钮事件
    connect(mybtn,&QPushButton::clicked,[=](){
        qDebug()<<"翻金币场景中点击了返回";

        //发送要返回选择关卡场景的信号,延时发送信号
        QTimer::singleShot(500,this,[=](){
            emit this->playSceneBack();
        });

    });

    //设置关卡文字
    QLabel *label = new QLabel;
    label->setParent(this);
    //设置位置，宽高
    label->setGeometry(80,this->height()-70,120,50);
    //设置字体
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    //设置文字内容
    QString str1=QString("第%1关").arg(this->m_LevelNum);
    label->setText(str1);

    //使用一个数组来接收来自gameconfig中第n关的数据
    GameConfig game;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            gameArr[i][j]=game.mData[this->m_LevelNum][i][j];
        }
    }

    //设置胜利图片
    QLabel *winLabel=new QLabel(this);
    QPixmap tmpPix;
    tmpPix.load(":/Image/LevelCompletedDialogBg.jpg");
    tmpPix=tmpPix.scaled(220,120);
    winLabel->setPixmap(tmpPix);
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->move((this->width()-220)*0.5,-150);

    //设置金币背景
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QPixmap pix=QPixmap(":/Image/BoardNode.jpg");
            pix=pix.scaled(45,45);
            QLabel *label = new QLabel;

            label->setPixmap(pix);
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setParent(this);
            label->move(62+i*50,200+j*50);

            //加载翻币按钮
             QString str0="";
            if(gameArr[i][j]==1)
            {
                str0=":/Image/Coin0001.png";
            }
            else
            {
                str0=":/Image/Coin0008.png";
            }
            MyCoin *myc=new MyCoin(str0);
            myc->setParent(this);
            myc->move(62+i*50,200+j*50);
            //将硬币的正反面初始化
            myc->flag=gameArr[i][j];
            //将每个硬币的坐标初始化
            myc->posX=i;
            myc->posY=j;
            //将金币对象放进金币数组当中
            this->coinBtn[i][j]=myc;

            //监听点击事件
            connect(myc,&QPushButton::clicked,[=](){
                //在点击完之后就禁用点击
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        this->coinBtn[i][j]->isWin=true;
                    }
                }
                //调用改变硬币正反面函数
                myc->changFlag();

                //将维护的数组中的值也改变
                gameArr[i][j]=myc->flag?0:1;

                //延时翻转周围的金币
                QTimer::singleShot(300,this,[=](){
                    //翻转周围的硬币
                    if(myc->posX+1<=3)//右
                    {
                        this->coinBtn[myc->posX+1][myc->posY]->changFlag();
                        gameArr[myc->posX+1][myc->posY]=gameArr[myc->posX+1][myc->posY]?0:1;
                    }
                    if(myc->posX-1>=0)//左
                    {
                        this->coinBtn[myc->posX-1][myc->posY]->changFlag();
                        gameArr[myc->posX-1][myc->posY]=gameArr[myc->posX-1][myc->posY]?0:1;
                    }
                    if(myc->posY+1<=3)//上
                    {
                        this->coinBtn[myc->posX][myc->posY+1]->changFlag();
                        gameArr[myc->posX][myc->posY+1]=gameArr[myc->posX][myc->posY+1]?0:1;
                    }
                    if(myc->posY-1>=0)//下
                    {
                        this->coinBtn[myc->posX][myc->posY-1]->changFlag();
                        gameArr[myc->posX][myc->posY-1]=gameArr[myc->posX][myc->posY-1]?0:1;
                    }

                    //在硬币翻完之后就开始开启点击
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            this->coinBtn[i][j]->isWin=false;
                        }
                    }


                    //判断游戏是否胜利，是否所有的硬币都是正面true
                    //如果所有硬币都是true那么就将this的isWin置为true ，
                    //如果isWin是true，那么就将所有的硬币的isWin赋为true
                    //然后再按钮类的鼠标按下事件中去判断，如果为true那么直接return
                    this->isWin=true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            if(this->coinBtn[i][j]->flag==false)
                            {
                                this->isWin=false;
                            }
                        }
                    }
                    if(this->isWin==true)
                    {
                        //就把每一个硬币上的isWin赋值为true
                        for(int i=0;i<4;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                                this->coinBtn[i][j]->isWin=true;
                            }
                        }

                        //将胜利的图片放下来
                        QPropertyAnimation *animation=new QPropertyAnimation(winLabel,"geometry");
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+200,winLabel->width(),winLabel->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();

                    }
                });




            });


        }
    }
}

void PlayScene::paintEvent(QPaintEvent *)
{
    //加载背景图片
    QPainter painter(this);
    QPixmap pix(":/Image/PlayLevelScene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //放上标题
    pix.load(":/Image/Title.png");
    pix=pix.scaled(pix.width()*0.1,pix.height()*0.1);
    painter.drawPixmap(10,15,pix);
}
