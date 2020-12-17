#include "shortcut.h"
#include "ui_shortcut.h"
#include "texteditor.h"

#include <QDebug>
#include <QKeyEvent>

shortcut::shortcut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shortcut)
{
    ui->setupUi(this);
}


shortcut::~shortcut()
{
    delete ui;
}

//Создаем таблицу с действиями по полученому указателю
void shortcut::resirvedPointer(QMenu *p)
{
    pn = p; // сохраним указатель для дальнейших вызовов
    // Получили указатель на пункты меню, создадим таблицу
    int n = p->actions().count();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnHidden(2,true);
    ui->tableWidget->setRowCount(n);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //запрет редактирования
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    QList<QAction*> l = p->actions(); // Лист со всеми пунктами меню
    for(int i = 0; i < n; ++i){
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(l[i]->text()); // Наименование меню
        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setText(l[i]->shortcut().toString()); // сочетание горячих клавишь
        ui->tableWidget->installEventFilter(this);
        ui->tableWidget->setItem(i,0,item);
        ui->tableWidget->setItem(i,1,item2);
      //  ui->tableWidget->setItem(i,2,item3);

    }
}

//когда мы в таблице выбираем сочетание, то записываем в переменные адрес действия и индекс строки для использования при изменении
void shortcut::on_tableWidget_clicked(const QModelIndex &index)
{
       // qDebug() << "colum= " << index.column() <<",  row = " << index.row();
        if(index.column()){
            current = pn->actions().at(index.row());
            indx = index.row();
            flage = true;
        }
}

//Перегруженный фильтр нажатий, без него через стандартный keyEvent не заработало, вязто из документации QT
//Ошибка устранена, модифаеры обрабатываются отдельно
bool shortcut::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        Qt::KeyboardModifiers modifiers = keyEvent->modifiers();
        qDebug() << keyEvent->key();
        keyInt = keyEvent->key();
        if(modifiers & Qt::ShiftModifier)
            keyInt += Qt::SHIFT;
        if(modifiers & Qt::ControlModifier)
            keyInt += Qt::CTRL;
        if(modifiers & Qt::AltModifier)
            keyInt += Qt::ALT;
        if(modifiers & Qt::MetaModifier)
            keyInt += Qt::META;
        QString keyText = keyEvent->text();
        keyText = keyEvent->text();
        qDebug() << QKeySequence(keyInt).toString(QKeySequence::NativeText);
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
}

//Как только клавиша отжата, записываем ранее нажатые клавиши в сочетание выбранного действия,
//flage введен что бы запись происходила только один раз после нажатия(выбора) ячейки
void shortcut::keyReleaseEvent(QKeyEvent *event)
{
    if(flage == true && event->type() == QEvent::KeyRelease){
        //qDebug() << "Realise EVENT = " << shor[0] << shor[1] << shor[2] << shor[3]; // какие клавиши были нажаты
       current->setShortcut(QKeySequence(keyInt));
       // qDebug() << current->shortcut().toString(); //Проверка сочетания
        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setText(current->shortcut().toString()); //Повторная запись в таблицу
        ui->tableWidget->setItem(indx,1,item2);
    }
    flage = false;                          // защчита от повторной записи после первой
    count = 0;                              // сброс счетчика, используется как защита при записи массива (мах 4 значения)
}

void shortcut::on_pushButton_clicked()
{
    close();
}

