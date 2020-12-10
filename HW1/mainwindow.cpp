#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "path1.h"
#include "path2.h"
#include "path3.h"

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


void MainWindow::on_pushButton_clicked()
{
    path1 window;
    window.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    path2 window;
    window.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    path3 window;
    window.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}
