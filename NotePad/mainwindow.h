#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();

    void closeEvent(QCloseEvent *event);
private slots:
    void doProcessTriggeredByNew(bool);
    void doProcessTriggeredByOpen(bool);
    void doProcessTriggeredByUTF_8(bool);
    void doProcessTriggeredByGB2312(bool);
    void doProcessTriggerByExit(bool);
    void doProcessTriggerBySave(bool);
    void doProcessTriggerBySaveAs(bool);
    void doProcessTriggerByClose(bool);
    void doProcessTriggerByCloseAll(bool);
    void doProcessTriggerByTile(bool);
    void doProcessTriggerByCascade(bool);
    void doProcessTriggerByNext(bool);
    void doProcessTriggerByPrevious(bool);
    void doProcessTriggerByAbout(bool);
    void doProcessTriggerByAboutQt(bool);

    void doProcessTriggerByRedo(bool);
    void doProcessTriggerByUndo(bool);
    void doProcessTriggerByCut(bool);
    void doProcessTriggerByCopy(bool);
    void doProcessTriggerByParse(bool);

private:
    Ui::MainWindow *ui;
    QString codeName;

    QLabel *m_CodeName;
};
#endif // MAINWINDOW_H
