#include "dataworker.h"
#include <QDataStream>

// Конструктор который предзагружает данные из файла
DataWorker::DataWorker(QObject *parent) : QObject(parent)
{
    //qDebug() << "create object DW";
    sqlDatabaseInit();
}

DataWorker::~DataWorker()
{
    base.close();
    //qDebug() << "Connect close;";
}

// Добавление новой задачи в лист задач.
void DataWorker::addData(int d, QString m, int y, QString t, int p)
{
    // Проверка введенных значений, если бы даты и прогресс были бы не в виде тумблеров, проверялись бы тут же
    if(t == ""){
        //qDebug() << "Enemy Task";
        emit mistakeSend();
        return;;
    }

    //Добавление задачи в SQL
    QSqlQuery query;
    QString insert = "INSERT INTO taskdata(task, date, progress) VALUES ('%1','%2','%3');";
    QString date = "%1-%2-%3";

    query.exec(insert.arg(t).arg(date.arg(d).arg(m).arg(y)).arg(p));
    emit taskValueChange(++taskCounter);
}

//Вывод задач записанных в базу данных
void DataWorker::showTasks()
{
    QSqlRelationalTableModel *model;
    model = new QSqlRelationalTableModel(this);
    model->setTable("taskdata");
    model->select();
    model->setEditStrategy(QSqlTableModel::EditStrategy::OnFieldChange);

    w.setModel(model);
    w.resize(590,700);
    w.setColumnWidth(1,250);
    w.show();
}

//для получения значения после загрузки данных
int DataWorker::getCounter()
{
    return taskCounter;
}

//Инициация подключения к б.д. и получение общего числа записей
void DataWorker::sqlDatabaseInit()
{
    // Предзагрузка
    base = QSqlDatabase::addDatabase("QSQLITE");
    base.setDatabaseName("task.db");
    base.open();

    //Создание таблицы для записи данных, если еще не создана
     QSqlQuery query;
    if(!query.exec("CREATE TABLE taskdata("
                      "id	INTEGER NOT NULL UNIQUE,"
                      "task	TEXT NOT NULL,"
                      "date	TEXT NOT NULL,"
                      "progress	INTEGER,"
                      "PRIMARY KEY(id AUTOINCREMENT));"))
    {
        //qDebug() << "Create`s error  (file created early or other error)";
    }
    // Получение количества уже записанных задач
    query.exec("SELECT COUNT(id) FROM taskdata;");
    if(query.next()){
        taskCounter = query.value(0).toInt();
        emit taskValueChange(taskCounter);
    }
}


