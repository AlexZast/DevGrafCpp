/*
 * Вынес задачу в отельных класс, для удобства дальнейшей работы с ними. Содержит только конструктор и данные. Пока данные в паблике, в дальнейшем перенесутся в privat и добавятся get и set методы.
 */


#ifndef TASKDATA_H
#define TASKDATA_H

#include <QString>
#include <iostream>

class taskData
{
public:
    taskData(int, QString, int, QString, int);


public:
    int day;
    QString mouth;
    int year;

    QString task;
    int progress;
};




#endif // TASKDATA_H
