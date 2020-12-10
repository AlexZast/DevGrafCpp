#include "path3.h"
#include "ui_path3.h"
#include <QGraphicsTextItem>

path3::path3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::path3)
{
    ui->setupUi(this);
}

path3::~path3()
{
    delete ui;
}

void path3::on_pushButton_clicked()
{
    ui->plainTextEdit->insertPlainText(ui->plainTextEdit_2->toPlainText());

}

void path3::on_pushButton_2_clicked()
{
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText());
}

void path3::on_pushButton_5_clicked()
{
    QGraphicsTextItem b;
    QString a = "<font color=\"red\">Hello</font>";
    b.setHtml(a);
    ui->plainTextEdit_2->appendHtml(b.toHtml());
}

void path3::on_pushButton_3_clicked()
{
    QString a = ui->plainTextEdit_3->toPlainText();
    QGraphicsTextItem b;
    b.setHtml(a);
    ui->plainTextEdit_2->appendHtml(b.toHtml());

}

void path3::on_pushButton_4_clicked()
{
    close();
}
