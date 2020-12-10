#ifndef PATH2_H
#define PATH2_H

#include <QDialog>
#include <QtMath>

namespace Ui {
class path2;
}

class path2 : public QDialog
{
    Q_OBJECT

public:
    explicit path2(QWidget *parent = nullptr);
    ~path2();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::path2 *ui;
};

#endif // PATH2_H
