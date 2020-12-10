#include "TextEditor.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_action_triggered() //Открытие файла
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile file(str);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        ui->plainTextEdit->setPlainText(ba.data());
        directory = str;
    }
}

void MainWindow::on_action_3_triggered() // Сохраниение файла как
{
    QString str = QFileDialog::getSaveFileName(0, "Save Dialog", "", "*.txt");
    QFile file(str);
    if(file.open(QIODevice::WriteOnly)){
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        file.write(ba, ba.size());
    }
}

void MainWindow::on_action_4_triggered()
{
    close();
}

void MainWindow::on_action_2_triggered() //Вызов справки
{
    QFile file(":/help/help.txt");
    file.open(QIODevice::ReadOnly); //Проверку не далю т.к. подразумевается что файл уже в ресурсах
    QByteArray ba = file.readAll();
    QString message = ba.data();

    QMessageBox a;
    a.setText(message);
    a.exec();
}

void MainWindow::on_action_5_triggered() //Если файл был открыт то directory будет соответствовать имени открытого файла иначе создадим новый файл при сохранении
{
    if(directory != 0){
        QFile file(directory);
        if(file.open(QIODevice::WriteOnly)){
            QString text = ui->plainTextEdit->toPlainText();
            QByteArray ba = text.toUtf8();
            file.write(ba, ba.size());
        }
    } else {
        QString str = QFileDialog::getSaveFileName(0, "New Save Dialog", "", "*.txt");
        QFile file(str);
        if(file.open(QIODevice::WriteOnly)){
            QString text = ui->plainTextEdit->toPlainText();
            QByteArray ba = text.toUtf8();
            file.write(ba, ba.size());
            directory = str;
        }
    }
}
