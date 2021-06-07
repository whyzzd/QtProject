#include<QtWidgets>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QDebug>
#include<QCloseEvent>
#include<QApplication>
#include "subtext.h"

//静态变量
bool SubText::hasEdit=false;
int SubText::nEdit=0;
int SubText::number=1;
QVector<bool> SubText::v;

SubText::SubText(QWidget *parent) : QPlainTextEdit(parent)
{
    nonameN=0;
    myfile=new QFile(this);
    fileIsTrOper=true;
    isEdit=false;
    n=1;


    //---------------------^-----------------------
    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
    //---------------------v------------------------
}


void SubText::NewFile()
{

    QString str;
    if(number==1)
    {
        str = QString("未命名的文档[%1][*]").arg(number);
        v.push_back(true);
        nonameN=number;
        number++;


    }
    else if(number>1)
    {
        //QVector::iterator
        auto   ret= std::find(v.begin(),v.end(),false);
        if(ret==v.end())
        {

            str = QString("未命名的文档[%1][*]").arg(number);
            v.push_back(true);
            nonameN=number;
            number++;

        }
        else
        {
            int dist;
            *ret=true;
            dist=std::distance(v.begin(),ret);
            str = QString("未命名的文档[%1][*]").arg(dist+1);
            nonameN=dist+1;
        }

    }


    this->setWindowTitle(str);



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
        fileIsTrOper=false;
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
       this->appendPlainText(str);
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
            this->fileIsTrOper=false;
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
        this->fileIsTrOper=false;
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

    this->fileIsTrOper=true;
    qDebug()<<"三："<<nEdit;

    //实现按顺序新增未命名编号
    if(nonameN>=1&&nonameN<=v.size())
    {
        v[nonameN-1]=false;
        nonameN=0;
    }
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
            //此处的含义为：只有上面的save保存成功，下面的关闭才会被执行
            if(this->fileIsTrOper)
            {
               //注意：accept执行结束之后此事件函数并不会直接退出
               e->accept();
               return;
            }
            e->ignore();
        }
        else if(ret==QMessageBox::No)
        {
            //实现按顺序新增未命名编号
            if(nonameN>=1&&nonameN<=v.size())
            {
                v[nonameN-1]=false;
                nonameN=0;
            }

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
        //实现按顺序新增未命名编号
        if(nonameN>=1&&nonameN<=v.size())
        {
            v[nonameN-1]=false;
            nonameN=0;
        }
        e->accept();
    }
}
void SubText::contextMenuEvent(QContextMenuEvent *e)
{
    //撤销，恢复，剪切，复制，粘贴，清除，全选
    QMenu *menu = new QMenu(this);
    QAction *_redo= menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"撤销",this,&SubText::redo,QKeySequence::Redo);
    _redo->setEnabled(this->document()->isRedoAvailable());
    QAction *_undo= menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"恢复",this,&SubText::undo,QKeySequence::Undo);
    _undo->setEnabled(this->document()->isUndoAvailable());
    menu->addSeparator();
    QAction *_cut=menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"剪切",this,&SubText::cut,QKeySequence::Cut);
    _cut->setEnabled(textCursor().hasSelection());
    QAction *_copy= menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"复制",this,&SubText::copy,QKeySequence::Copy);
    _copy->setEnabled(textCursor().hasSelection());
    QAction *_paste=menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"粘贴",this,&SubText::paste,QKeySequence::Paste);
    _paste->setEnabled(QApplication::clipboard()!=nullptr);
    QAction *_clear = menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"清除",this,&SubText::clear,tr(""));
    _clear->setEnabled(!this->document()->isEmpty());
    menu->addSeparator();
    QAction *_selectAll = menu->addAction(QIcon(":/new/prefix1/Images1/MenuSceneStartButton.png"),"全选",this,&SubText::selectAll,QKeySequence::SelectAll);
    _selectAll->setEnabled(!this->document()->isEmpty());
    menu->exec(e->globalPos());
}

//-------------------^---------------------------------------------------------------
int SubText::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}

//![extraAreaWidth]

//![slotUpdateExtraAreaWidth]

void SubText::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

//![slotUpdateExtraAreaWidth]

//![slotUpdateRequest]

void SubText::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

//![slotUpdateRequest]

//![resizeEvent]

void SubText::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

//![resizeEvent]

//![cursorPositionChanged]

void SubText::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(136,128,204).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

//![cursorPositionChanged]

//![extraAreaPaintEvent_0]

void SubText::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);

//![extraAreaPaintEvent_0]

//![extraAreaPaintEvent_1]
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
//![extraAreaPaintEvent_1]

//![extraAreaPaintEvent_2]
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
//![extraAreaPaintEvent_2]
//--------------------------v---------------------------------------------------------
