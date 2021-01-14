#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include "shortcut.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QByteArray>
#include <QKeyEvent>
#include <QPushButton>
#include <QDebug>
#include <QMenu>

#include <QApplication>
#include <QTranslator>


#include <QPrinter>
#include <QPrintDialog>

#include <QFontComboBox>
#include <QTextCharFormat>


QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

    void loadStyle(QString stylePath);

signals:
    void sendPointer(QMenu *p);

private slots:
    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_3_triggered();
    void on_action_4_triggered();
    void on_action_5_triggered();
    void on_action_6_triggered();
    void on_action_7_triggered();
    void on_action_8_triggered();
    void on_action_9_triggered();
    void on_action_10_triggered();
    void on_action_15_triggered();
    void on_action_14_triggered();
    void on_action_12_triggered();

    // Выравнивание текста
    void action_toLeft();
    void action_toCenter();
    void action_toRight();

    // Изменения шрифта и размера
    void action_textSize(QString);
    void action_textFont(QFont);
    void action_copyFormat();
    void action_pastFormat();


private:
    Ui::TextEditor *ui;
    QTranslator translater;
    QString directory = 0; //Переменная хранит путь директории
    QTextCharFormat frmt;

};


#endif // TEXTEDITOR_H
