#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QFileSystemWatcher>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{
    LoadPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 ".",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_1->setText(LoadPath);
}


void MainWindow::on_pushButton_2_clicked()
{
    SavePath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 ".",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_2->setText(SavePath);
}


void MainWindow::on_pushButton_3_clicked()
{
    pixFromLeft=ui->lineEdit_3->text().toInt();
    pixWidth = ui->lineEdit_4->text().toInt();
    if(pixFromLeft>=0 && pixFromLeft<9999 && pixWidth>=0 && pixWidth<9999){
        imageProcessing = new ImageProcessing(LoadPath,SavePath,pixFromLeft,pixWidth);
        imageProcessing->processImage();
    }
}
