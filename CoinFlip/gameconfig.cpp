#include "gameconfig.h"

GameConfig::GameConfig(QObject *parent) : QObject(parent)
{
    int arr[4][4]={{1,1,1,1},
                   {1,1,0,1},
                   {1,0,0,0},
                   {1,1,0,1}};
    QVector<QVector<int>> v;
    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(1,v);
    //---------上为第一关----------------
    //后面关卡随机生成吧

    for(int i=2;i<=20;i++)
    {
        QVector<QVector<int>>v2;
        for(int j=0;j<4;j++)
        {
            QVector<int>v1;
            for(int k=0;k<4;k++)
            {
                int t=rand()%2;
                v1.push_back(t);
            }
            v2.push_back(v1);
        }
        this->mData.insert(i,v2);
    }
}
