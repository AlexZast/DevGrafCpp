#include "task1.h"
#include "ui_task1.h"
#include "parser.h"

task1::task1(QWidget *parent) : QDialog(parent), ui(new Ui::task1)
{
    ui->setupUi(this);
}

task1::~task1()
{
    delete ui;
}


void task1::on_plainTextEdit_textChanged()
{
    Parser::Cahnge(ui->plainTextEdit);
}

void task1::on_pushButton_clicked()
{
    close();
}

