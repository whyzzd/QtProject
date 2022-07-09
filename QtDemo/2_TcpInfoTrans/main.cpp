#include "myserver.h"

#include <QApplication>
#include"myclient.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyServer w;
    w.show();
    w.setGeometry(w.x()-400,w.y(),w.width(),w.height());

    MyClient c1(1,"127.0.0.1","8888");
    c1.show();
    c1.setGeometry(c1.x()+170,c1.y()-200,c1.width(),c1.height());
    MyClient c2(2,"127.0.0.1","8888");
    c2.show();
    c2.setGeometry(c1.x(),c1.y()+400,c1.width(),c1.height());
    return a.exec();
}
