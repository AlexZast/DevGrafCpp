#include "TextEditor.h"
#include "ui_texteditor.h"
#include "fswidget.h"
#include <QDebug>

TextEditor::TextEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    loadStyle(":/style/styleLight.txt");


// Создадим "быстрые" клавиши на панели уплавения

    // Основные клавиши
    QPushButton *button_new = new QPushButton(QIcon(":/icon/new_file.png"), "", this);
    button_new->setToolTip(tr("Новый файл"));
    ui->toolBar->addWidget(button_new);
    connect(button_new, SIGNAL(clicked()), this, SLOT(on_action_8_triggered()));

    QPushButton *button_open = new QPushButton(QIcon(":/icon/open_file.png"),"",this);
    button_open->setToolTip(tr("Открыть"));
    ui->toolBar->addWidget(button_open);
    connect(button_open, SIGNAL(clicked()), this, SLOT(on_action_triggered()));

    QPushButton *button_save = new QPushButton(QIcon(":/icon/save_file.png"),"",this);
    button_save->setToolTip(tr("Сохранить файл"));
    ui->toolBar->addWidget(button_save);
    connect(button_save, SIGNAL(clicked()), this, SLOT(on_action_3_triggered()));

    ui->toolBar->addSeparator();

    // Выравнивание текста
    QPushButton *toLeft = new QPushButton(QIcon(":/icon/toLeft.png"), "" ,this);
    toLeft->setToolTip(tr("По левому краю"));
    ui->toolBar->addWidget(toLeft);
    connect(toLeft, SIGNAL(clicked()), this, SLOT(action_toLeft()));

    QPushButton *toCenter = new QPushButton(QIcon(":/icon/toCenter.png"), "" ,this);
    toCenter->setToolTip(tr("По центру"));
    ui->toolBar->addWidget(toCenter);
    connect(toCenter, SIGNAL(clicked()), this, SLOT(action_toCenter()));

    QPushButton *toRight = new QPushButton(QIcon(":/icon/toRight.png"), "", this);
    toRight->setToolTip(tr("По правому краю"));
    ui->toolBar->addWidget(toRight);
    connect(toRight, SIGNAL(clicked()), this, SLOT(action_toRight()));

    ui->toolBar->addSeparator();

    // Выбор размер текста и шрифта
    QStringList textsize;
    textsize << "8" << "9" << "10" << "11" << "12" << "14" << "16" << "18" << "20" << "24" << "36";
    QComboBox* tSize = new QComboBox(this);
    tSize->addItems(textsize);
    tSize->setCurrentIndex(4);
    ui->toolBar->addWidget(tSize);
    connect(tSize, SIGNAL(currentTextChanged(QString)), this, SLOT(action_textSize(QString)));

    QFontComboBox* fontType = new QFontComboBox(this);
    ui->toolBar->addWidget(fontType);
    connect(fontType, SIGNAL(currentFontChanged(const QFont)), this, SLOT(action_textFont(const QFont)));


    ui->toolBar->addSeparator();

    // Копирование и вставка формата
    QPushButton *copyFormat = new QPushButton(QIcon(":/icon/copyFormat.png"), "", this);
    copyFormat->setToolTip(tr("Копировать форматирование"));
    ui->toolBar->addWidget(copyFormat);
    connect(copyFormat, SIGNAL(clicked()), this, SLOT(action_copyFormat()));

    QPushButton *pastFormat = new QPushButton(QIcon(":/icon/pastFormat.png"), "", this);
    pastFormat->setToolTip(tr("Вставить форматирование"));
    ui->toolBar->addWidget(pastFormat);
    connect(pastFormat, SIGNAL(clicked()), this, SLOT(action_pastFormat()));

    ui->toolBar->addSeparator();
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::loadStyle(QString stylePath)
{
    QFile file(stylePath);
    file.open(QIODevice::ReadOnly);
    QString a = file.readAll();
    qApp->setStyleSheet(a);
}

// Новый файл
void TextEditor::on_action_8_triggered()
{
    directory = nullptr;
    ui->textEdit->setPlainText("");
    ui->textEdit->setReadOnly(false);
}

// Открытие файла
void TextEditor::on_action_triggered()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile file(str);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        ui->textEdit->setPlainText(ba.data());
        directory = str;
    }
    ui->textEdit->setReadOnly(false);
}

// Открыть только для чтения
void TextEditor::on_action_2_triggered()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile file(str);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        ui->textEdit->setPlainText(ba.data());
    }
    ui->textEdit->setReadOnly(true);
}

// Сохранить
//Если файл был открыт то directory будет соответствовать имени открытого файла иначе создадим новый файл при сохранении
void TextEditor::on_action_3_triggered()
{
    if(directory != 0){
        QFile file(directory);
        if(file.open(QIODevice::WriteOnly)){
            QString text = ui->textEdit->toPlainText();
            QByteArray ba = text.toUtf8();
            file.write(ba, ba.size());
        }
    } else {
        QString str = QFileDialog::getSaveFileName(0, "New Save Dialog", "", "*.txt");
        QFile file(str);
        if(file.open(QIODevice::WriteOnly)){
            QString text = ui->textEdit->toPlainText();
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
        QString text = ui->textEdit->toPlainText();
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
    file.open(QIODevice::ReadOnly);
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
    translater.load(":/translate/QtLanguage_en.qm");
    qApp->installTranslator(&translater);
    ui->retranslateUi(this);
}

// Установка русского языка
void TextEditor::on_action_6_triggered()
{
    qApp->removeTranslator(&translater);
    ui->retranslateUi(this);
}

// Загрузка темной темы
void TextEditor::on_action_15_triggered()
{
    loadStyle(":/style/styleDark.txt");
}

// Загрузка светлой темы
void TextEditor::on_action_14_triggered()
{
    loadStyle(":/style/styleLight.txt");
}

// Печать фаyrtyrtйла
void TextEditor::on_action_12_triggered()
{
QPrinter printer;
   QPrintDialog dlg(&printer, this);
   dlg.setWindowTitle("Print");
   if (dlg.exec() != QDialog::Accepted)
       return;
   ui->textEdit->print(&printer);
}

// Выравнивание текста
void TextEditor::action_toLeft()
{
    QTextBlockFormat frm = ui->textEdit->textCursor().blockFormat();
    frm.setAlignment(Qt::AlignLeft);
    ui->textEdit->textCursor().mergeBlockFormat(frm);
}

void TextEditor::action_toCenter()
{
    QTextBlockFormat frm = ui->textEdit->textCursor().blockFormat();
    frm.setAlignment(Qt::AlignCenter);
    ui->textEdit->textCursor().mergeBlockFormat(frm);
}

void TextEditor::action_toRight()
{
    QTextBlockFormat frm = ui->textEdit->textCursor().blockFormat();
    frm.setAlignment(Qt::AlignRight);
    ui->textEdit->textCursor().mergeBlockFormat(frm);
}

void TextEditor::action_textSize(QString text)
{
    int size = text.toInt();
    QTextCharFormat frt = ui->textEdit->textCursor().charFormat();
    frt.setFontPointSize(size);
    ui->textEdit->textCursor().setCharFormat(frt);
}

void TextEditor::action_textFont(QFont font)
{
    QTextCharFormat frt = ui->textEdit->textCursor().charFormat();
    int size = frt.fontPointSize();
    frt.setFont(font);
    frt.setFontPointSize(size);
    ui->textEdit->textCursor().setCharFormat(frt);
}
// Работа с форматами (копирование и вставка)
void TextEditor::action_copyFormat()
{
    frmt = ui->textEdit->textCursor().charFormat();
}

void TextEditor::action_pastFormat()
{
    ui->textEdit->textCursor().setCharFormat(frmt);
}



