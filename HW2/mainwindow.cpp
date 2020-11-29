#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"

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
    task1 window;
    window.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    task2 window;
    window.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    task3 window;
    window.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}
