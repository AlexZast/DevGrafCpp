#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
}

TextEditor::~TextEditor()
{
    delete ui;
}

// Новый файл
void TextEditor::on_action_8_triggered()
{
    directory = nullptr;
    ui->plainTextEdit->setPlainText("");
    ui->plainTextEdit->setReadOnly(false);
}

// Открытие файла
void TextEditor::on_action_triggered()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile file(str);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        ui->plainTextEdit->setPlainText(ba.data());
        directory = str;
    }
    ui->plainTextEdit->setReadOnly(false);
}

// Открыть только для чтения
void TextEditor::on_action_2_triggered()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile file(str);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        ui->plainTextEdit->setPlainText(ba.data());
    }
    ui->plainTextEdit->setReadOnly(true);
}

// Сохранить
//Если файл был открыт то directory будет соответствовать имени открытого файла иначе создадим новый файл при сохранении
void TextEditor::on_action_3_triggered()
{
    if(directory != 0){
        QFile file(directory);
        if(file.open(QIODevice::WriteOnly)){
            QString text = ui->plainTextEdit->toPlainText();
            QByteArray ba = text.toUtf8();
            file.write(ba, ba.size());
        }
    } else {
        QString str = QFileDialog::getSaveFileName(0, "New Save Dialog", "", "*.txt");
        QFile file(str);
        if(file.open(QIODevice::WriteOnly)){
            QString text = ui->plainTextEdit->toPlainText();
            QByteArray ba = text.toUtf8();
            file.write(ba, ba.size());
            directory = str;
        }
    }
}

// Сохранить как
void TextEditor::on_action_4_triggered()
{
    QString str = QFileDialog::getSaveFileName(0, "Save Dialog", "", "*.txt");
    QFile file(str);
    if(file.open(QIODevice::WriteOnly)){
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        file.write(ba, ba.size());
    }
}

// Закрытие
void TextEditor::on_action_5_triggered()
{

    close();
}

// Вызов справки
void TextEditor::on_action_9_triggered()
{

    QFile file(":/help/help.txt");
    file.open(QIODevice::ReadOnly); //Проверку не далю т.к. подразумевается что файл уже в ресурсах
    QByteArray ba = file.readAll();
    QString message = ba.data();

    QMessageBox a;
    a.setWindowTitle(tr("Справка"));
    a.setText(message);
    a.exec();
}

// Горячие клавиши, передаем указатель на меню в одельное окно, где будем по адресам менять горячие клавиши в действиях (см. shortcut)
void TextEditor::on_action_10_triggered()
{
    shortcut window;
    window.show();
    connect(this, SIGNAL(sendPointer(QMenu*)), &window, SLOT(resirvedPointer(QMenu*))); // Передадим в shortcut указатель на QMenu
    emit sendPointer(ui->menu);
    window.exec();
}

// Установка английского языка
void TextEditor::on_action_7_triggered()
{
    qDebug() << "English click";
    translater.load(":/translate/QtLanguage_en.qm");
    qApp->installTranslator(&translater);
    ui->retranslateUi(this);

}

//Установка русского языка
void TextEditor::on_action_6_triggered()
{
    qDebug() << "Russian click";
    qApp->removeTranslator(&translater);
    ui->retranslateUi(this);
}
