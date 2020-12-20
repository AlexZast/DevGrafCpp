#include "task2.h"
#include "ui_task2.h"

task2::task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);

    //Создание списка с иконками
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/img/cpplogo.png"), "C++");
    ui->listWidget->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem(QIcon(":/img/pythonlogo.png"), "Python");
    ui->listWidget->addItem(item2);
    QListWidgetItem *item3 = new QListWidgetItem(QIcon(":/img/javalogo.png"), "Java");
    ui->listWidget->addItem(item3);
    QListWidgetItem *item4 = new QListWidgetItem(QIcon(":/img/csharplogo.png"), "C#");
    ui->listWidget->addItem(item4);
    QListWidgetItem *item5 = new QListWidgetItem(QIcon(":/img/phplogo.png"), "PHP");
    ui->listWidget->addItem(item5);
    QListWidgetItem *item6 = new QListWidgetItem(QIcon(":/img/javascriptlogo.png"), "JavaScript");
    ui->listWidget->addItem(item6);

    //Установка возможности перетаскивания
    ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);

}

void task2::on_pushButton_clicked()
{
    //Создание нового объекта через диалоговое окно с вводом имени
    bool ok;
    QString str = QInputDialog::getText(0,  "Input", "Name", QLineEdit::Normal, "Language name", &ok);
    if(ok){
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/img/defaultlogo.png"), str);
    ui->listWidget->addItem(item);
    }
}

//Удаление элемента
void task2::on_pushButton_2_clicked()
{
    delete ui->listWidget->currentItem();

}

void task2::on_pushButton_3_clicked()
{
    close();
}

task2::~task2()
{
    delete ui;
}

//При двойном клике на ITEM делаем его редактируемым
void task2::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
        item->setFlags((item->flags () | Qt::ItemIsEditable));
}

void task2::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        ui->listWidget->setViewMode(QListView::IconMode);
    } else {
        ui->listWidget->setViewMode(QListView::ListMode);
        ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);
    }
}
