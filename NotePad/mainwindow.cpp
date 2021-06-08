#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMdiSubWindow>
#include<QDebug>
#include<QMessageBox>
#include<QCloseEvent>
#include<QGridLayout>//创建栅格布局
#include<QTextBlock>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("MyNotePad");
    this->codeName="UTF-8";

    init();

    //状态栏显示
    m_CodeName=new QLabel("字符编码:"+codeName,ui->statusbar);
    m_CodeName->setMinimumWidth(200);
    ui->statusbar->addWidget(m_CodeName);

    m_CursorPositionCol =new QLabel("列:");
    m_CursorPositionCol->setMinimumWidth(100);
    ui->statusbar->addWidget(m_CursorPositionCol);

    m_CursorPositionLines =new QLabel("行:");
    m_CursorPositionLines->setMinimumWidth(100);
    ui->statusbar->addWidget(m_CursorPositionLines );


    ui->statusbar->setLayoutDirection(Qt::RightToLeft);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{

    this->setContentsMargins(0,0,0,0);
    ui->centralwidget->setContentsMargins(0,0,0,0);
    //将视图变为tab显示
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    //ui->mdiArea->ta

    //是否右上角是否有关闭按钮
    ui->mdiArea->setTabsClosable(true);

    //设置tab的形状
    //ui->mdiArea->setTabShape(QTabWidget::Triangular);


    connect(ui->action_New,&QAction::triggered,this,&MainWindow::doProcessTriggeredByNew);
    connect(ui->action_Open,&QAction::triggered,this,&MainWindow::doProcessTriggeredByOpen);
    connect(ui->action_UTF_8,&QAction::triggered,this,&MainWindow::doProcessTriggeredByUTF_8);
    connect(ui->action_GB2312,&QAction::triggered,this,&MainWindow::doProcessTriggeredByGB2312);
    connect(ui->action_Exit,&QAction::triggered,this,&MainWindow::doProcessTriggerByExit);
    connect(ui->action_Save,&QAction::triggered,this,&MainWindow::doProcessTriggerBySave);
    connect(ui->action_SaveAs,&QAction::triggered,this,&MainWindow::doProcessTriggerBySaveAs);
    connect(ui->action_Close,&QAction::triggered,this,&MainWindow::doProcessTriggerByClose);
    connect(ui->action_CloseAll,&QAction::triggered,this,&MainWindow::doProcessTriggerByCloseAll);
    connect(ui->action_Tile,&QAction::triggered,this,&MainWindow::doProcessTriggerByTile);
    connect(ui->action_Cascade,&QAction::triggered,this,&MainWindow::doProcessTriggerByCascade);
    connect(ui->action_Next,&QAction::triggered,this,&MainWindow::doProcessTriggerByNext);
    connect(ui->action_Previous,&QAction::triggered,this,&MainWindow::doProcessTriggerByPrevious);
    connect(ui->action_About,&QAction::triggered,this,&MainWindow::doProcessTriggerByAbout);
    connect(ui->action_AboutQT,&QAction::triggered,this,&MainWindow::doProcessTriggerByAboutQt);

    connect(ui->action_Redo,&QAction::triggered,this,&MainWindow::doProcessTriggerByRedo);
    connect(ui->action_Undo,&QAction::triggered,this,&MainWindow::doProcessTriggerByUndo);
    connect(ui->action_Cut,&QAction::triggered,this,&MainWindow::doProcessTriggerByCut);
    connect(ui->action_Copy,&QAction::triggered,this,&MainWindow::doProcessTriggerByCopy);
    connect(ui->action_Parse,&QAction::triggered,this,&MainWindow::doProcessTriggerByParse);

    //初始化编辑栏(置灰色)
    ui->action_Cut->setEnabled(false);
    ui->action_Copy->setEnabled(false);
    ui->action_Redo->setEnabled(false);
    ui->action_Undo->setEnabled(false);
    ui->action_Parse->setEnabled(false);

    //若无活跃窗口，则置灰所有编辑
    connect(ui->mdiArea,&QMdiArea::subWindowActivated,this,[=](QMdiSubWindow *sub){
        if(sub==nullptr)
        {
            ui->action_Cut->setEnabled(false);
            ui->action_Copy->setEnabled(false);
            ui->action_Redo->setEnabled(false);
            ui->action_Undo->setEnabled(false);
            ui->action_Parse->setEnabled(false);
        }
    });
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!SubText::hasEdit)
    {
        event->accept();
    }
    else
    {
        ui->mdiArea->closeAllSubWindows();
        //此句话的作用是：如果存在未保存的文件，直接点击窗体进行关闭时，当文本被关闭时窗体是否会被关闭
        //event->ignore();
    }
}
void MainWindow::initNewAndOpen(SubText* sub)
{

//    if(ui->mdiArea->activeSubWindow()!=nullptr)
//    {
//        return;
//    }
    connect(sub,&SubText::copyAvailable,ui->action_Cut,&QAction::setEnabled);
    connect(sub,&SubText::redoAvailable,ui->action_Redo,&QAction::setEnabled);
    //撤销这一步多了一次发信号
    connect(sub,&SubText::undoAvailable,ui->action_Undo,[=](bool ret){
        ui->action_Undo->setEnabled(ret);
    });
    connect(sub,&SubText::copyAvailable,ui->action_Copy,&QAction::setEnabled);
    connect(ui->mdiArea,&QMdiArea::subWindowActivated,sub,[=](QMdiSubWindow *sub){
        ui->action_Parse->setEnabled(QApplication::clipboard()!=nullptr&&sub!=nullptr);
    });



    //在状态栏显示光标的位置
    connect(sub,&SubText::cursorPositionChanged,this,[=](){
        QTextCursor tc=sub->textCursor();
        QTextLayout *pLayout=tc.block().layout();
        //列
        int col=tc.position()-tc.block().position();
        //行
        int lines=pLayout->lineForTextPosition(col).lineNumber()+tc.block().firstLineNumber();

        m_CursorPositionCol->setText("列:"+QString::number(col));
        m_CursorPositionLines->setText("行:"+QString::number(lines+1));
    });
}
void MainWindow::doProcessTriggeredByNew(bool)
{
    SubText *newText = new SubText(this);
    newText->setMyCode(this->codeName);
    newText->NewFile();

    ui->mdiArea->addSubWindow(newText);

    //让窗口最大化显示
    newText->showMaximized();

    qDebug()<<ui->mdiArea->activeSubWindow();

    initNewAndOpen(newText);

}

void MainWindow::doProcessTriggeredByOpen(bool)
{
    SubText *openText = new SubText(this);
    openText->setMyCode(this->codeName);
    openText->OpenFile();
    //如果打开文件失败那么就直接关掉
    if(!openText->fileIsTrOper)
    {
        openText->close();
        return;
    }
qDebug()<<"djaskldajdlakjdas"<<openText->document()->isUndoAvailable();
    ui->mdiArea->addSubWindow(openText);
    openText->showMaximized();

    qDebug()<<"open:"<<ui->mdiArea->activeSubWindow();


    initNewAndOpen(openText);


}

void MainWindow::doProcessTriggeredByUTF_8(bool)
{
    this->codeName="UTF-8";
    this->m_CodeName->setText("字符编码:"+this->codeName);
}

void MainWindow::doProcessTriggeredByGB2312(bool)
{
    this->codeName="GB18030";
    this->m_CodeName->setText("字符编码:"+this->codeName);
}
void MainWindow::doProcessTriggerByExit(bool)
{
    //问题：如何使得在关闭子窗口后，主窗口还能不关闭（已解决）
    //ui->mdiArea->closeAllSubWindows();

        this->close();


}
void MainWindow::doProcessTriggerBySave(bool)
{
    QMdiSubWindow *subw=ui->mdiArea->activeSubWindow();
    if(subw==nullptr)return;
    QWidget *wid=subw->widget();
    if(wid==nullptr)return;
    SubText *sub=static_cast<SubText*>(wid);
    if(sub==nullptr)return;
    sub->SaveFile();
}

void MainWindow::doProcessTriggerBySaveAs(bool)
{
    QMdiSubWindow *subw=ui->mdiArea->activeSubWindow();
    if(subw==nullptr)return;
    QWidget *wid=subw->widget();
    if(wid==nullptr)return;
    SubText *sub=static_cast<SubText*>(wid);
    if(sub==nullptr)return;
    sub->SaveFileAs();
}
void MainWindow::doProcessTriggerByClose(bool)
{
    if(ui->mdiArea->activeSubWindow()==NULL)return;
    ui->mdiArea->activeSubWindow()->close();
}
void MainWindow::doProcessTriggerByCloseAll(bool)
{
    if(ui->mdiArea->activeSubWindow()==NULL)return;
    ui->mdiArea->closeAllSubWindows();
}
void MainWindow::doProcessTriggerByTile(bool)
{
    ui->mdiArea->tileSubWindows();
}
void MainWindow::doProcessTriggerByCascade(bool)
{
    ui->mdiArea->cascadeSubWindows();
}
void MainWindow::doProcessTriggerByNext(bool)
{
    ui->mdiArea->activateNextSubWindow();
}
void MainWindow::doProcessTriggerByPrevious(bool)
{
    ui->mdiArea->activatePreviousSubWindow();
}
void MainWindow::doProcessTriggerByAbout(bool)
{
    QMessageBox::about(this,"关于作者","zzzzzz");
}
void MainWindow::doProcessTriggerByAboutQt(bool)
{
    QMessageBox::aboutQt(this);
}
void MainWindow::doProcessTriggerByRedo(bool)
{
    //恢复
    qDebug()<<"执行了redo";
    QMdiSubWindow* sub= ui->mdiArea->activeSubWindow();
    if(sub==nullptr)return;
    QWidget *wid =sub->widget();
    if(wid==nullptr)return;
    SubText *text=static_cast<SubText *>(wid);
    if(text==nullptr)return;
    text->redo();


}
void MainWindow::doProcessTriggerByUndo(bool)
{
    //撤销

    QMdiSubWindow* sub= ui->mdiArea->activeSubWindow();

    if(sub==nullptr)return;
    qDebug()<<"执行了undo";
    QWidget *wid =sub->widget();
    if(wid==nullptr)return;
    SubText *text= (SubText*)wid;
    if(wid==nullptr)return;
    text->undo();

}
void MainWindow::doProcessTriggerByCut(bool)
{
    QWidget *wid = ui->mdiArea->activeSubWindow()->widget();
    SubText *text= (SubText*)wid;
    text->cut();

}
void MainWindow::doProcessTriggerByCopy(bool)
{
    QWidget *wid = ui->mdiArea->activeSubWindow()->widget();
    SubText *text= (SubText*)wid;
    text->copy();
}
void MainWindow::doProcessTriggerByParse(bool)
{
    QWidget *wid = ui->mdiArea->activeSubWindow()->widget();
    SubText *text= (SubText*)wid;
    text->paste();
}

