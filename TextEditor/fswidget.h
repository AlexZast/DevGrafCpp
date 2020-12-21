#ifndef FSWIDGET_H
#define FSWIDGET_H

#include <QWidget>

#include <QTreeView>
#include <QPushButton>
#include <QGridLayout>
#include <QStandardItemModel>
#include <QComboBox>
#include <QApplication>
#include <QTextEdit>

Q_PROPERTY(QStandartItemModel *model READ getCurrentModel WRITE setNewModel)

class FSWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FSWidget(QWidget *parent = nullptr);
    void clearTree();
    QStandardItemModel *getCurrentModel()const
       {
           return model;
       }
       void setNewModel(QStandardItemModel *newmodel);
       void rebuildModel(QString str);




private:
    QGridLayout *gridLay;
    QTreeView *tree;
    QPushButton *mainPath;
    QComboBox *disckSelBox;

    QTextEdit *line;


    QStandardItemModel *model;
    QString curretnPath;

private slots:
   void chgDisk(int index); // получаем индекс выбранного диска
   void goMainPath();       // Для UNIX-подобных ОС верхним уровнем является путь /
   void click();
};

#endif // FSWIDGET_H
