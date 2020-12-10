#ifndef PATH1_H
#define PATH1_H

#include <QDialog>

namespace Ui {
class path1;
}

class path1 : public QDialog
{
    Q_OBJECT

public:
    explicit path1(QWidget *parent = nullptr);
    ~path1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::path1 *ui;
};

#endif // PATH1_H
