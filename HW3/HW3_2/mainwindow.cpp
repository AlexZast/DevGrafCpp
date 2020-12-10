#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weatherpars.h"

#include <QFileDialog>
#include <QMessageBox>

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


void MainWindow::on_pushButton_2_clicked() //открыть файл
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.html");
    QFile file(str);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        ui->plainTextEdit->setPlainText(ba.data());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    // Поиск курса доллара (привязался к иконке)
    QString text = ui->plainTextEdit->toPlainText();
    qint32 fnd;
    qint32 start, stop;
    fnd = text.indexOf("rate__icon_usd", 0); // находим иконку доллара
    fnd = text.indexOf("rate__currency", fnd); //находим строку с курсом
    start = text.indexOf(">", fnd); // находим ковычку с которой начинается курс
    stop = text.indexOf("<", fnd); // находим закрываюющую ковычку для курса
    QString exRate = text.mid(start+1,stop-start-1);
    ui->label_usd->setText(exRate);

    //Поиск курса евро
    fnd = text.indexOf("rate__icon_eur", 0);
    fnd = text.indexOf("rate__currency", fnd);
    start = text.indexOf(">", fnd);
    stop = text.indexOf("<", fnd);
    exRate = text.mid(start+1,stop-start-1);
    ui->label_euro->setText(exRate);

    //Погода
    //Текущая температура
    ui->label_temp->setText(weatherPars::parse(text, "weather__temp"));
    //Влажность
    ui->label_humidity->setText(weatherPars::parse(text, "weather__humidity"));

}


void MainWindow::on_pushButton_clicked()
{
    close();
}
