#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imageprocessing.h"
#include <QMainWindow>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QFileSystemWatcher>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString LoadPath;
    QString SavePath;
    int pixFromLeft;
    int pixWidth;
    int widthFinal;
    int lengthFinal;

    ImageProcessing *imageProcessing = nullptr;
};
#endif // MAINWINDOW_H
