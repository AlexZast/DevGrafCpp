#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


#include <QTreeView>
#include <QPushButton>
#include <QGridLayout>
#include <QStandardItemModel>
#include <QComboBox>
#include <QApplication>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QStatusBar>


#include <QDir>
#include <QDebug>
#include <QFileSystemModel>

#include "controller.h"

Q_PROPERTY(QFileSystemModel *model READ getCurrentModel WRITE setNewModel)

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
     Widget(QWidget *parent = nullptr);
     ~Widget();


     QStandardItemModel *getCurrentModel()const
        {
            return model;
        }


        void setNewModel(QStandardItemModel *newmodel);
        void rebuildModel(QString str);
        void clearTree();

private:
    Ui::Widget *ui;

    QGridLayout *gridLay;
    QTreeView *tree;
    QPushButton *mainPath;
    QComboBox *disckSelBox;

    QTextEdit *line;
    QStandardItemModel *model;
    QString curretnPath;

    QLineEdit *searchEdit;
    QPushButton *startFindButton;
    QTextEdit *infoText;
    QComboBox *selDrive;
    Controller *controllerl;
    QLabel *statusLabel;




private slots:
   void chgDisk(int index); // получаем индекс выбранного диска
   void goMainPath();       // Для UNIX-подобных ОС верхним уровнем является путь /
   void click();

   void findFileSlot();
   void changStatusLabel(QString);
   void printFindFile(QString);
};
#endif // WIDGET_H
