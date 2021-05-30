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
    //ui->action_Redo->setEnabled(false);
    //编辑栏是否可用(是否变灰)，问题在于如何使得当前活跃的窗口能狗对应编辑栏的状态
    //ui->action_Redo->setEnabled(ui->mdiArea->activeSubWindow()->);
//    ui->action_Undo->setEnabled(ui->mdiArea->activeSubWindow()->document()->isUndoAvailable());
//    ui->action_Cut->setEnabled(textCursor().hasSelection());
//    ui->action_Copy->setEnabled(textCursor().hasSelection());
//    ui->action_Parse->setEnabled(QApplication::clipboard()!=nullptr);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
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
    //以下功能未实现
    connect(ui->action_Redo,&QAction::triggered,this,&MainWindow::doProcessTriggerByRedo);
    connect(ui->action_Undo,&QAction::triggered,this,&MainWindow::doProcessTriggerByUndo);
    connect(ui->action_Cut,&QAction::triggered,this,&MainWindow::doProcessTriggerByCut);
    connect(ui->action_Copy,&QAction::triggered,this,&MainWindow::doProcessTriggerByCopy);
    connect(ui->action_Parse,&QAction::triggered,this,&MainWindow::doProcessTriggerByParse);


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
void MainWindow::doProcessTriggerByRedo(bool)
{

}
void MainWindow::doProcessTriggerByUndo(bool)
{

}
void MainWindow::doProcessTriggerByCut(bool)
{

}
void MainWindow::doProcessTriggerByCopy(bool)
{

}
void MainWindow::doProcessTriggerByParse(bool)
{

}