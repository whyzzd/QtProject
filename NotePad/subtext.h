#ifndef SUBTEXT_H
#define SUBTEXT_H

#include <QWidget>
#include<QPlainTextEdit>
#include<QFile>
#include<QMenu>
#include<QMdiSubWindow>
#include<QVector>

//-----------------------------
QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE
class LineNumberArea;
//--------------------------------


class SubText : public QPlainTextEdit
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
    bool fileIsTrOper;
    //是否存在还在编辑的文件
    static bool hasEdit;
    //记录正在编辑的文件个数
    static int nEdit;
    //记录累加的值是0还是1
    int n;

    void closeEvent(QCloseEvent *e);
    void contextMenuEvent(QContextMenuEvent *e) ;
    //重写鼠标事件，当鼠标点击时触发光标位置改变
    void mousePressEvent(QMouseEvent *e);


public slots:
    void dealpaste(QMdiSubWindow *);


signals:
private slots:
    void doProcessContentsChanged();
    //处理粘贴事件

private:
    QString fileName;
    QFile *myfile;
    QString codeName;
    bool isEdit;

    int nonameN;

    //实现按顺序新增未命名编号
    static QVector<bool>v;
    static int number;


//----------------------^------------------------------
public:
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

private:
    //指向行号区间的指针
    QWidget *lineNumberArea;
//----------------------v--------------------------------
};

//-----------------------^---------------------------------
class LineNumberArea : public QWidget
{
public:
    LineNumberArea(SubText *editor) : QWidget(editor) {
        codeEditor = editor;
    }

    QSize sizeHint() const override {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    SubText *codeEditor;
};

#endif // SUBTEXT_H
