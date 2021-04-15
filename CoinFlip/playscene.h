#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mycoin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);

    //重写画图事件
    void paintEvent(QPaintEvent *);


    //维护一个数组用来存放每关的游戏数据
    int gameArr[4][4];

    //维护一个金币的二维数组
    MyCoin *coinBtn[4][4];

    int m_LevelNum;

    //判断游戏是否胜利
    bool isWin;

signals:
    void playSceneBack();

};

#endif // PLAYSCENE_H
