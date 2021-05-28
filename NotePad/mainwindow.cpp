#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"subtext.h"
#include<QMdiSubWindow>
#include<QDebug>
#include<QMessageBox>
#include<QCloseEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->codeName="UTF-8";
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    connect(ui->action_New,&QAction::triggered,this,&doProcessTriggeredByNew);
    connect(ui->action_Open,&QAction::triggered,this,&doProcessTriggeredByOpen);
    connect(ui->action_UTF_8,&QAction::triggered,this,&doProcessTriggeredByUTF_8);
    connect(ui->action_GB2312,&QAction::triggered,this,&doProcessTriggeredByGB2312);
    connect(ui->action_Exit,&QAction::triggered,this,&doProcessTriggerByExit);
    connect(ui->action_Save,&QAction::triggered,this,&doProcessTriggerBySave);
    connect(ui->action_SaveAs,&QAction::triggered,this,&doProcessTriggerBySaveAs);
    connect(ui->action_Close,&QAction::triggered,this,&doProcessTriggerByClose);
    connect(ui->action_CloseAll,&QAction::triggered,this,&doProcessTriggerByCloseAll);
    connect(ui->action_Tile,&QAction::triggered,this,&doProcessTriggerByTile);
    connect(ui->action_Cascade,&QAction::triggered,this,&doProcessTriggerByCascade);
    connect(ui->action_Next,&QAction::triggered,this,&doProcessTriggerByNext);
    connect(ui->action_Previous,&QAction::triggered,this,&doProcessTriggerByPrevious);
    connect(ui->action_About,&QAction::triggered,this,&doProcessTriggerByAbout);
    connect(ui->action_AboutQT,&QAction::triggered,this,&doProcessTriggerByAboutQt);



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
        event->ignore();

    }


}

void MainWindow::doProcessTriggeredByNew(bool)
{
    SubText *newText = new SubText(this);
    newText->setMyCode(this->codeName);
    newText->NewFile();

    ui->mdiArea->addSubWindow(newText);
    newText->show();
}

void MainWindow::doProcessTriggeredByOpen(bool)
{
    SubText *openText = new SubText(this);
    openText->setMyCode(this->codeName);
    openText->OpenFile();
    //如果打开文件失败那么就直接关掉
    if(!openText->fileIsOpen)
    {
        openText->close();
        return;
    }
    ui->mdiArea->addSubWindow(openText);
    openText->show();
}

void MainWindow::doProcessTriggeredByUTF_8(bool)
{
    this->codeName="UTF-8";
}

void MainWindow::doProcessTriggeredByGB2312(bool)
{
    this->codeName="GB18030";
}
void MainWindow::doProcessTriggerByExit(bool)
{
    //问题：如何使得在关闭子窗口后，主窗口还能不关闭
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
