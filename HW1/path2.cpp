#include "path2.h"
#include "ui_path2.h"

path2::path2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::path2)
{
    ui->setupUi(this);
}

path2::~path2()
{
    delete ui;
}

void path2::on_pushButton_clicked()
{
    float A = ui->lineEdit_A->text().toFloat();
    float B = ui->lineEdit_B->text().toFloat();
    float gr = ui->lineEdit_G->text().toFloat();
    // Проверка что значения не 0
    if (A ==0 || B == 0 || gr == 0){
        ui->labeloutput->setText("Нет решения");
    }
    if (ui->radioButton_g->isChecked()){
        gr = qDegreesToRadians(gr);
    }
    ui->labeloutput->setText(QString::number(sqrt(A*A+B*B-2*A*B*qCos(gr))));
}


void path2::on_pushButton_4_clicked()
{
    close();
}


