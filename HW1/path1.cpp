#include "path1.h"
#include "ui_path1.h"
#include <math.h>


path1::path1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::path1)
{
    ui->setupUi(this);
}

path1::~path1()
{
    delete ui;
}

void path1::on_pushButton_clicked()
{
    // Получение данных с веденных форм
    float a = ui->lineEdit_a->text().toFloat();
    float b = ui->lineEdit_b->text().toFloat();
    float c = ui->lineEdit_c->text().toFloat();

    // Расчет дискриминанта
    float D = b*b - 4 * a * c;

    // Если D меньше 0 нет решений в действ числах
    // Если D равно 0 то одно решение
    // Иначе 2 корня
    // если а равно 0 то линейное уравнение

    if(a == 0 && b!=0){
        ui->label_output_x1->setText(QString::number(-c/b));
        ui->label_output_x2->setText("Линейное уравнение");
    } else if(a == 0 && c == 0) {
        ui->label_output_x1->setText("0");
        ui->label_output_x2->setText("Линейное уравнение");
    } else
    {
        if (D < 0){
            ui->label_output_x1->setText("Нет решения");
            ui->label_output_x2->setText("Нет решения");
        } else if (D == 0) {

                ui->label_output_x1->setText(QString::number(-b/(2*a)));
                ui->label_output_x2->setText("Одни корень");

        } else {
            ui->label_output_x1->setText(QString::number((-b-sqrt(D))/(2*a)));
            ui->label_output_x2->setText(QString::number((-b+sqrt(D))/(2*a)));
        }
    }
}

void path1::on_pushButton_4_clicked()
{
    close();
}
