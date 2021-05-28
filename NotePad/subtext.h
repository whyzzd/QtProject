#ifndef SUBTEXT_H
#define SUBTEXT_H

#include <QWidget>
#include<QTextEdit>
#include<QFile>
class SubText : public QTextEdit
{
    Q_OBJECT
public:
    explicit SubText(QWidget *parent = nullptr);

    void NewFile();
    void OpenFile();
    void setMyCode(const QString code);

    void SaveFile();
    void SaveFileAs();

    //文件是否打开成功
    bool fileIsOpen;
    //是否存在还在编辑的文件
    static bool hasEdit;
    //记录正在编辑的文件个数
    static int nEdit;
    //记录累加的值是0还是1
    int n;

    void closeEvent(QCloseEvent *e);

signals:
private slots:
    void doProcessContentsChanged();

private:
    QString fileName;
    QFile *myfile;
    QString codeName;
    bool isEdit;


};

#endif // SUBTEXT_H
