#ifndef TASK2_H
#define TASK2_H

#include <QDialog>
#include <QListWidgetItem>
#include <QIcon>
#include <QListWidget>
#include <QInputDialog>

namespace Ui {
class task2;
}

class task2 : public QDialog
{
    Q_OBJECT

public:
    explicit task2(QWidget *parent = nullptr);
    ~task2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::task2 *ui;
};

#endif // TASK2_H
