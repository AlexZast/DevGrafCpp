#include "dataworker.h"

#include <QDataStream>

// Конструктор который предзагружает данные из файла
DataWorker::DataWorker(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(addTask()), this, SLOT(saveData()));
    preLoadData();
}

// Добавление новой задачи в лист задач.
void DataWorker::addData(int d, QString m, int y, QString t, int p)
{
    taskData* newTask = new taskData(d, m, y, t, p);

    allTask.push_back(*newTask);

    // Для отслеживания и отладки)
    qDebug() << "Day:" << newTask->day << " Mouth:" << newTask->mouth<< " Year:" << newTask->year << " Task:" << newTask->task << " Progress:" << newTask->progress;

    //запись в файл
    emit addTask();

}

// Предзагрузка задач из файла в QList
void DataWorker::preLoadData()
{
    QFile file("task.bin");
    QDataStream output(&file);

    if(file.open(QIODevice::ReadOnly))
    {
        int i = 0;
        while(!output.atEnd())
        {

            int d;
            QString m;
            int y;
            QString t;
            int p;

            output >> d >> m >> y >> t >> p;

            taskData* newTask = new taskData(d, m, y, t, p);

            allTask.push_back(*newTask);

            qDebug() << "Задача №" << (i+1) << allTask.back().day << allTask.back().mouth << allTask.back().year << allTask.back().task << allTask.back().progress;
            ++i;
        }
           file.close();
}
}


// Запись последней добавленной задачи в файл.
void DataWorker::saveData()
{
    //тут запись данных в файл
    taskData n = allTask.back();

    QFile file("task.bin");

    QDataStream output(&file);
    if(file.open(QIODevice::Append))
    {
        output << n.day << n.mouth << n.year <<  n.task << n.progress;
        file.close();
    }









}
