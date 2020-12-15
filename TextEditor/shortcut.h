#ifndef SHORTCUT_H
#define SHORTCUT_H

#include <QDialog>
#include <QMenu>

namespace Ui {
class shortcut;
}

class shortcut : public QDialog
{
    Q_OBJECT

public:
    explicit shortcut(QWidget *parent = nullptr);
    ~shortcut();

public slots:
    void resirvedPointer(QMenu *p);

private slots:
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

//    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    Ui::shortcut *ui;

    QMenu *pn = 0;
    int count = 0;
    qint32 shor[4] = {0, 0, 0, 0};
    int indx = 0;
    bool flage = false;
    QAction *current = nullptr;
};

#endif // SHORTCUT_H
