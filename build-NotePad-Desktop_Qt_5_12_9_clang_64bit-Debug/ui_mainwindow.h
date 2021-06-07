/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_SaveAs;
    QAction *action_Exit;
    QAction *action_Redo;
    QAction *action_Undo;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Parse;
    QAction *action_UTF_8;
    QAction *action_GB2312;
    QAction *action_Close;
    QAction *action_CloseAll;
    QAction *action_Tile;
    QAction *action_Cascade;
    QAction *action_Next;
    QAction *action_Previous;
    QAction *action_About;
    QAction *action_AboutQT;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_S;
    QMenu *menu_W;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(637, 434);
        MainWindow->setDocumentMode(false);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ICON/newfile.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ICON/openfile.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ICON/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon2);
        action_SaveAs = new QAction(MainWindow);
        action_SaveAs->setObjectName(QString::fromUtf8("action_SaveAs"));
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action_Redo = new QAction(MainWindow);
        action_Redo->setObjectName(QString::fromUtf8("action_Redo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ICON/redo.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Redo->setIcon(icon3);
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QString::fromUtf8("action_Undo"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ICON/undo.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Undo->setIcon(icon4);
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QString::fromUtf8("action_Cut"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ICON/cut.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cut->setIcon(icon5);
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QString::fromUtf8("action_Copy"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ICON/copy.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Copy->setIcon(icon6);
        action_Parse = new QAction(MainWindow);
        action_Parse->setObjectName(QString::fromUtf8("action_Parse"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ICON/paste.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Parse->setIcon(icon7);
        action_UTF_8 = new QAction(MainWindow);
        action_UTF_8->setObjectName(QString::fromUtf8("action_UTF_8"));
        action_GB2312 = new QAction(MainWindow);
        action_GB2312->setObjectName(QString::fromUtf8("action_GB2312"));
        action_Close = new QAction(MainWindow);
        action_Close->setObjectName(QString::fromUtf8("action_Close"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ICON/close.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Close->setIcon(icon8);
        action_CloseAll = new QAction(MainWindow);
        action_CloseAll->setObjectName(QString::fromUtf8("action_CloseAll"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/ICON/closeAll.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_CloseAll->setIcon(icon9);
        action_Tile = new QAction(MainWindow);
        action_Tile->setObjectName(QString::fromUtf8("action_Tile"));
        action_Cascade = new QAction(MainWindow);
        action_Cascade->setObjectName(QString::fromUtf8("action_Cascade"));
        action_Next = new QAction(MainWindow);
        action_Next->setObjectName(QString::fromUtf8("action_Next"));
        action_Previous = new QAction(MainWindow);
        action_Previous->setObjectName(QString::fromUtf8("action_Previous"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        action_AboutQT = new QAction(MainWindow);
        action_AboutQT->setObjectName(QString::fromUtf8("action_AboutQT"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mdiArea->sizePolicy().hasHeightForWidth());
        mdiArea->setSizePolicy(sizePolicy);
        mdiArea->setFrameShape(QFrame::Box);
        mdiArea->setFrameShadow(QFrame::Raised);
        mdiArea->setLineWidth(2);
        mdiArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        QBrush brush(QColor(160, 160, 160, 255));
        brush.setStyle(Qt::NoBrush);
        mdiArea->setBackground(brush);
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(false);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 637, 24));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_S = new QMenu(menu_E);
        menu_S->setObjectName(QString::fromUtf8("menu_S"));
        menu_W = new QMenu(menubar);
        menu_W->setObjectName(QString::fromUtf8("menu_W"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_W->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_F->addAction(action_New);
        menu_F->addAction(action_Open);
        menu_F->addSeparator();
        menu_F->addAction(action_Save);
        menu_F->addAction(action_SaveAs);
        menu_F->addSeparator();
        menu_F->addAction(action_Exit);
        menu_E->addAction(action_Redo);
        menu_E->addAction(action_Undo);
        menu_E->addAction(action_Cut);
        menu_E->addAction(action_Copy);
        menu_E->addAction(action_Parse);
        menu_E->addAction(menu_S->menuAction());
        menu_S->addAction(action_UTF_8);
        menu_S->addAction(action_GB2312);
        menu_W->addAction(action_Close);
        menu_W->addAction(action_CloseAll);
        menu_W->addAction(action_Tile);
        menu_W->addAction(action_Cascade);
        menu_W->addAction(action_Next);
        menu_W->addAction(action_Previous);
        menu_H->addAction(action_About);
        menu_H->addAction(action_AboutQT);
        toolBar->addAction(action_New);
        toolBar->addSeparator();
        toolBar->addAction(action_Open);
        toolBar->addAction(action_Save);
        toolBar->addAction(action_Close);
        toolBar->addAction(action_CloseAll);
        toolBar->addSeparator();
        toolBar->addAction(action_Cut);
        toolBar->addAction(action_Copy);
        toolBar->addAction(action_Parse);
        toolBar->addSeparator();
        toolBar->addAction(action_Redo);
        toolBar->addAction(action_Undo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266(&N)", nullptr));
        action_Open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266(&O)", nullptr));
        action_Save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
        action_SaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", nullptr));
        action_Exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&E)", nullptr));
        action_Redo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&R)", nullptr));
        action_Undo->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215(&U)", nullptr));
        action_Cut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", nullptr));
        action_Copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", nullptr));
        action_Parse->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", nullptr));
        action_UTF_8->setText(QApplication::translate("MainWindow", "UTF-8", nullptr));
        action_GB2312->setText(QApplication::translate("MainWindow", "GB2312", nullptr));
        action_Close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&0)", nullptr));
        action_CloseAll->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211(&A)", nullptr));
        action_Tile->setText(QApplication::translate("MainWindow", "\345\271\263\351\223\272(&T)", nullptr));
        action_Cascade->setText(QApplication::translate("MainWindow", "\345\261\202\345\217\240(&C)", nullptr));
        action_Next->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(&N)", nullptr));
        action_Previous->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252(&P)", nullptr));
        action_About->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", nullptr));
        action_AboutQT->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216QT(&Q)", nullptr));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_S->setTitle(QApplication::translate("MainWindow", "\347\274\226\347\240\201\346\240\274\345\274\217(&S)", nullptr));
        menu_W->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243(&W)", nullptr));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
