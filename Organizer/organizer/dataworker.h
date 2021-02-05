/*
 * Отвечает за работу с задачами внесением и считыванием данных из SQL.
 */

#ifndef DATEWORKER_H
#define DATEWORKER_H

#include <QObject>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QTableView>
#include <QSqlRelationalTableModel>

class DataWorker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int taskCounter READ getCounter NOTIFY taskValueChange)
public:
    explicit DataWorker(QObject *parent = nullptr);
    ~DataWorker();

    Q_INVOKABLE void addData(int, QString, int, QString, int);
    Q_INVOKABLE void showTasks();

    int getCounter();
    void sqlDatabaseInit();

signals:
    void taskValueChange(int); // Сигнал о изменении количества задач
    void mistakeSend(); // Сигнал если введены не валидные значения

private:
    int taskCounter = 0;
    // Создание БД сделал в приват области что-бы подключение существовало пока запущено приложение
    QSqlDatabase base;
    QTableView w;
};

#endif // DATEWORKER_H
