/*
 * Отвечает за работу с задачами внесенными в QList. Добавлен метод предзагрузки задач из файла и дозаписи каждой новой задачи в файл.
 * Для задач создан отельных класс
 */


#ifndef DATEWORKER_H
#define DATEWORKER_H

#include <QObject>
#include "taskdata.h"
#include <QDebug>

#include <QFile>

class DataWorker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int taskCounter READ getCounter NOTIFY taskValueChange)
public:
    explicit DataWorker(QObject *parent = nullptr);

    Q_INVOKABLE void addData(int, QString, int, QString, int);

    int getCounter();

signals:
    void addTask();

    void taskValueChange(int); // Сигнал о изменении количества задач

    void mistakeSend(); // Сигнал если введены не валидные значения

private slots:
    void preLoadData();
    void saveData();

private:
    QList<taskData> allTask;
    int taskCounter = 0;
};

#endif // DATEWORKER_H
