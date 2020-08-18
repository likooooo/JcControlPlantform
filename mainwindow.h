#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>
#include "Lib/PlantformIO/SlnController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void TriggerTest();
private slots:
    void on_actionCreateSln_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
