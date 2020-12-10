#ifndef PATH3_H
#define PATH3_H

#include <QDialog>

namespace Ui {
class path3;
}

class path3 : public QDialog
{
    Q_OBJECT

public:
    explicit path3(QWidget *parent = nullptr);
    ~path3();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::path3 *ui;
};

#endif // PATH3_H
