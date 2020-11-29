#include "task3.h"
#include "ui_task3.h"

task3::task3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task3)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(6);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "№" << "Имя компьютера" << "IP адрес" << "MAC адрес");
    // Заполнение нумерации
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i){
        QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(i+1));
        ui->tableWidget->setItem(i,0,item);
    }
    // Заполнение имен
    QStringList a {"Rio" , "Mio", "Tigra", "Pikachu", "Johan", "Potato"};
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i){
        QTableWidgetItem *item = new QTableWidgetItem(a[i]);
        ui->tableWidget->setItem(i,1, item);
    }
    // Заполнение IP
    QStringList ip {"192.168.0.1" , "192.168.0.100", "192.168.0.200", "127.0.0.1", "155.18.0.15", "192.168.20.101"};
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i){
        QTableWidgetItem *item = new QTableWidgetItem(ip[i]);
        ui->tableWidget->setItem(i, 2, item);
    }
    // Заполнение MAC
    QStringList mac {"A5:C3:96:50:CC:A8" , "C3:1C:66:6C:07:08", "66:FC:92:60:83:82", "FC:21:D9:DF:9D:D9", "21:54:A3:43:F2:47", "54:9D:C3:9A:AB:14"};
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i){
        QTableWidgetItem *item = new QTableWidgetItem(mac[i]);
        ui->tableWidget->setItem(i,3, item);
    }





}

// Кнопка покраски заденго фона
void task3::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->currentItem()->row();
    for(int i =0; i<ui->tableWidget->columnCount(); ++i){
        ui->tableWidget->item(row,i)->setBackgroundColor("green");
    }
}

void task3::on_pushButton_clicked()
{
    close();
}

task3::~task3()
{
    delete ui;
}
