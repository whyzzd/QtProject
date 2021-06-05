#include "subtext.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QDebug>
#include<QCloseEvent>
#include<QApplication>

bool SubText::hasEdit=false;
int SubText::nEdit=0;
SubText::SubText(QWidget *parent) : QTextEdit(parent)
{
    myfile=new QFile(this);
    fileIsOpen=true;
    isEdit=false;
    n=1;
}
void SubText::NewFile()
{
    static int a=1;
    QString str = QString("未命名的文档[%1][*]").arg(a);
    this->setWindowTitle(str);
    a++;

    //connect(this->document(),&QTextDocument::contentsChanged,this,&SubText::doProcessContentsChanged);
    connect(this->document(),&QTextDocument::contentsChanged,this,[=](){
        doProcessContentsChanged();
    });

    qDebug()<<"三："<<nEdit;
}

void SubText::OpenFile()
{
    QString filename=QFileDialog::getOpenFileName(this,"获取文件",".","Text(*.cpp *.h *.txt)");
    if(filename.isEmpty())
    {
        fileIsOpen=false;
        return;
    }
    this->fileName=filename;
    this->setWindowTitle(QFileInfo(filename).fileName()+"[*]");
    //对文件进行操作
    myfile->setFileName(filename);
    bool ret= myfile->open(QIODevice::ReadOnly);
    if(!ret)
    {
        QMessageBox::warning(this,"警告","文件打开失败");
        myfile->close();
        return;
    }
    QTextStream stream(myfile);

    stream.setCodec(this->codeName.toLocal8Bit().data());  //GB18030"UTF-8"

    while(!stream.atEnd())
    {
       QString str = stream.readLine();
       this->append(str);
    }
    myfile->close();
    connect(this->document(),&QTextDocument::contentsChanged,this,[=](){
        doProcessContentsChanged();
    });

}

void SubText::setMyCode(const QString code)
{
    this->codeName=code;
}

void SubText::SaveFile()
{
    if(this->fileName.isEmpty())
    {
        QString filename=QFileDialog::getSaveFileName(this,"保存",".","Text(*.txt *.cpp *.h)");
        if(filename.isEmpty())
        {
            this->fileIsOpen=false;
            return;
        }
        this->fileName=filename;
        this->setWindowTitle(QFileInfo(this->fileName).fileName()+"[*]");
    }
    myfile->setFileName(this->fileName);
    bool ret=myfile->open(QIODevice::WriteOnly);
    if(!ret)
    {
        QMessageBox::warning(this,"警告","文件打开失败");
        this->fileIsOpen=false;
        myfile->close();
        return;
    }
    QTextStream stream(myfile);
    stream.setCodec(this->codeName.toLocal8Bit().data());
    stream<<this->toPlainText();
    stream.flush();
    myfile->close();
    this->isEdit=false;    
    this->setWindowModified(this->isEdit);
    if(nEdit>0)
    {
        nEdit--;
    }

    if(nEdit==0)
    {
        hasEdit=false;
    }
    n=1;

    QMessageBox::information(this,"保存","文件保存成功！");

    this->fileIsOpen=true;
    qDebug()<<"三："<<nEdit;
}

void SubText::SaveFileAs()
{
    QString filename=QFileDialog::getSaveFileName(this,"另存为",".","Text(*.txt *.cpp *.h)");
    myfile->setFileName(filename);
    bool ret= myfile->open(QIODevice::ReadWrite);
    if(!ret)
    {
        QMessageBox::warning(this,"警告","文件打开失败");
        myfile->close();
        return;
    }
    QTextStream stream(myfile);
    stream.setCodec(this->codeName.toLocal8Bit().data());
    stream<<this->toPlainText();
    stream.flush();
    myfile->close();
    QMessageBox::information(this,"另存为","保存成功");
}

void SubText::doProcessContentsChanged()
{
    hasEdit=true;
    this->isEdit=true;    
    //如果是同一文件的内容进行修改(没有保存)，那么nEdit的值只累加1次
    nEdit+=n;
    n=0;
    this->setWindowModified(this->isEdit);
}

void SubText::dealpaste(QMdiSubWindow *sub)
{
    if(sub!=nullptr)
    {
        qDebug()<<"有活跃窗口";
    }
    else
    {
         qDebug()<<"无活跃窗口";
    }
}

void SubText::closeEvent(QCloseEvent *e)
{
    if(this->isEdit)
    {
        QMessageBox::StandardButton ret= QMessageBox::information(this,"关闭","你想将更改保存"+this->fileName+"吗？",
                                                                  QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        qDebug()<<"一："<<nEdit;
        if(ret==QMessageBox::Yes)
        {
            this->SaveFile();
            if(this->fileIsOpen)
            {
               //注意：accept执行结束之后此事件函数并不会直接退出
               e->accept();
               return;
            }
            e->ignore();
        }
        else if(ret==QMessageBox::No)
        {
            //关闭一个带“*”的文件和保存一样，编辑状态都需要改变
            if(nEdit>0)
            {
                nEdit--;
            }
            if(nEdit==0)
            {
                hasEdit=false;
            }
            e->accept();
            qDebug()<<"二："<<nEdit;

        }
        else
        {
            e->ignore();
        }
    }
    else
    {
        e->accept();
    }
}
void SubText::contextMenuEvent(QContextMenuEvent *e)
{
    //撤销，恢复，剪切，复制，粘贴，清除，全选
    QMenu *menu = new QMenu(this);
    QAction *_redo= menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"撤销",this,&redo,QKeySequence::Redo);
    _redo->setEnabled(this->document()->isRedoAvailable());
    QAction *_undo= menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"恢复",this,undo,QKeySequence::Undo);
    _undo->setEnabled(this->document()->isUndoAvailable());
    menu->addSeparator();
    QAction *_cut=menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"剪切",this,&cut,QKeySequence::Cut);
    _cut->setEnabled(textCursor().hasSelection());
    QAction *_copy= menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"复制",this,&copy,QKeySequence::Copy);
    _copy->setEnabled(textCursor().hasSelection());
    QAction *_paste=menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"粘贴",this,&paste,QKeySequence::Paste);
    _paste->setEnabled(QApplication::clipboard()!=nullptr);
    QAction *_clear = menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"清除",this,&clear,tr(""));
    _clear->setEnabled(!this->document()->isEmpty());
    menu->addSeparator();
    QAction *_selectAll = menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"全选",this,&selectAll,QKeySequence::SelectAll);
    _selectAll->setEnabled(!this->document()->isEmpty());
    menu->exec(e->globalPos());
}
