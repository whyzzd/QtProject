#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>
#include<QTimer>
//#include<QSound>
//#include<QMediaPlayer>
//#include<QtMultimedia>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //配置场景

    //设置固定大小
    setFixedSize(320,600);

    //设置图标
    QIcon icon(":/Image/CoinIco.png");
    this->setWindowIcon(icon);

    //设置标题
    setWindowTitle("翻金币主场景");

    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });
    //创建按钮音效
    //QSound *btnsnd=new QSound(":/Sound/ButtonClick.wav",this);

    //创建按钮对象
    MyPushButton *startbtn= new MyPushButton(":/Image/MenuSceneStartButton.png");
    //指定按钮的爸爸
    startbtn->setParent(this);
    startbtn->setMysize(60,60);
    startbtn->move(this->width()*0.5-30,this->height()-100);
    chooseScene =new ChooseLevelScene;
    //设置点击信号
    connect(startbtn,&QPushButton::clicked,[=](){
        //点击声
        //QApplication::beep();
        //btnsnd->play();
        //qDebug()<<"点击了开始按钮";
        //设置点击效果，
        //startbtn->zoom1();
        //只要一个效果就行
        startbtn->zoom2();
        //点击了按钮之后，跳转场景（实际是隐藏主场景，显示选择场景）
        //延时进入场景
        QTimer::singleShot(200,this,[=](){
            chooseScene->setGeometry(this->geometry());
            this->hide();
            chooseScene->show();


        });

    });
    //对选择场景中发出来的信号进行监听
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });


}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/MenuSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //放上标题
    pix.load(":/Image/Title.png");
    pix=pix.scaled(pix.width()*0.1,pix.height()*0.1);
    painter.drawPixmap(10,15,pix);


}
MainWindow::~MainWindow()
{
    delete ui;
}

