#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    gridLay = new QGridLayout(this);        // создаем слой для компоновки
    this->setLayout(gridLay);               // устанавливаем слой на виджет
    tree = new QTreeView(this);
    gridLay->addWidget(tree, 1, 0, 10, 10); // размещен на первой строке
    line = new QTextEdit(this);

    setMinimumSize(500, 600);               // ограничиваем размер виджета
    if(QSysInfo::productType() == "windows")
       {
            disckSelBox = new QComboBox(this);
            QFileInfoList list = QDir::drives();
            QFileInfoList::const_iterator listdisk = list.begin();
            int amount = list.count();
            for (int i = 0; i < amount; i++)
            {
                disckSelBox->addItem(listdisk->path());
                listdisk++;
            }
            if (amount > 0)
            {
                rebuildModel(list.at(0).path());
            }

            gridLay->addWidget(disckSelBox, 0, 0, 1, 2); // координаты
            connect(disckSelBox, SIGNAL(activated(int)), this, SLOT(chgDisk(int)));
            line -> setMaximumSize(600, 30);
            line->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
            gridLay->addWidget(line, 11, 0, 1, 10);

            line->setText(list.at(0).absoluteFilePath());

            connect(tree, SIGNAL(clicked(QModelIndex)), this, SLOT(click()));;


       } else {
           mainPath = new QPushButton(this);
           mainPath->setText("/");
           gridLay->addWidget(mainPath, 0, 0, 1, 2);
           connect(mainPath, SIGNAL(clicked()), this, SLOT(goMainPath()));
           rebuildModel("/");
       }
    // Поиск ****************
    searchEdit = new QLineEdit(this);
    gridLay->addWidget(searchEdit, 12, 0, 1, 3);
    selDrive = new QComboBox(this);
    gridLay->addWidget(selDrive, 12, 3);
    if (QSysInfo::productType() == "windows") // Для ОС Windows
       {
           QFileInfoList infolist = QDir::drives();
           int amount = infolist.count();
           for (int i = 0; i < amount; i++)
           {
               selDrive->addItem(infolist.at(i).path());
           }

       }
       else {                                    // Для UNIX-подобных систем
           QStringList str = {"/", "/home/", "/mount/", "/opt/"};
           int amount = str.count();
           for (int i = 0; i < amount; i++)
           {
               selDrive->addItem(str.at(i));
           }
       }
    startFindButton = new QPushButton(this);
       startFindButton->setText(tr("Find"));
       gridLay->addWidget(startFindButton, 12, 5);
       connect(startFindButton, SIGNAL(clicked()), this, SLOT(findFileSlot()));
       infoText = new QTextEdit(this);
       gridLay->addWidget(infoText, 13, 0, 10, 10);
       controllerl = new Controller(this);
       statusLabel = new QLabel(this);
       QStatusBar *statusBar = new QStatusBar();
       statusBar->addWidget(statusLabel);
       gridLay->addWidget(statusBar);
       connect(controllerl, SIGNAL(changFindPath(QString)), this, SLOT(changStatusLabel(QString)));
       connect(controllerl, SIGNAL(genPathOfFile(QString)), this, SLOT(printFindFile(QString)));
       connect(controllerl, SIGNAL((newFind())), infoText, SLOT(clear()));
}




Widget::~Widget()
{
    delete ui;
}

void Widget::setNewModel(QStandardItemModel *newmodel)
{
    tree->setModel(newmodel);
    model = newmodel;
}

void Widget::rebuildModel(QString str)
{
    curretnPath = str;
    QStandardItemModel *model = new QStandardItemModel(this);
    QList<QStandardItem*> items;
    items.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveHDIcon)), str));
    model->appendRow(items);

    QDir dir(str);
    dir.setFilter(QDir::Hidden | QDir::NoSymLinks | QDir::Dirs);
    QStringList list = dir.entryList();
    int amount = list.count();
    QList<QStandardItem*>folders;
    for (int i = 0; i < amount; i++)
    {
        QStandardItem* f = new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DirIcon)), list.at(i));
        folders.append(f);
    }
    items.at(0)->appendRows(folders);
    dir.setFilter(QDir::Hidden | QDir::NoSymLinks | QDir::Files);amount = list.count();
    QList<QStandardItem*>files;
    for (int i = 0; i < amount; i++)
    {
        QStandardItem* f = new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)), list.at(i));
        files.append(f);
    }
    items.at(0)->appendRows(files);
    setNewModel(model);
}

void Widget::clearTree()
{

}

void Widget::chgDisk(int index)
{
    QFileInfoList list = QDir::drives();
    rebuildModel(list.at(index).path());
}

void Widget::goMainPath()
{
    rebuildModel("/");
}

void Widget::click()
{
    qDebug() << tree->currentIndex();

    curretnPath += tree->currentIndex().data(2).toString()+"/";
    rebuildModel(curretnPath);
    line->setText(curretnPath);
}

void Widget::findFileSlot()
{
   QString linesearch = searchEdit->text();
   if (linesearch.length() == 0) return;
   controllerl->startFind(selDrive->currentText(), linesearch);
}

void Widget::changStatusLabel(QString line)
{
   statusLabel->setText(line);
}

void Widget::printFindFile(QString str)
{
   infoText->append(str);
}



