#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "urlparser.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);

    downloader = new Downloader(this);

    connect(downloader, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(slotDownloadProgress(qint64,qint64)));
    connect(downloader, SIGNAL(done(const QUrl&, const QByteArray&)),
            this, SLOT(slotDone(const QUrl&, const QByteArray&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    urlParser *parser = new urlParser;
    QList<QString>* urls = parser->getUrls(ui->lineEdit->text());

    for (int i = 0; i < 3; ++i) {
        qDebug() << urls->back();

        downloader->download(urls->back());

        urls->pop_back();
    }

}

void MainWindow::error()
{
    QMessageBox::critical(this, "Error", "ERRROOOR");
}

void MainWindow::slotDownloadProgress(qint64 reveived, qint64 total)
{
    ui->progressBar->setValue(100 * reveived/total);
}

void MainWindow::slotDone(const QUrl &url, const QByteArray &ba)
{
    QFile file(url.path().section('/', -1));
    if(file.open(QIODevice::WriteOnly)){
    file.write(ba);
    file.close();
    }

    showPic(file.fileName());
}

void MainWindow::showPic(const QString &path)
{
    QPixmap pix(path);
    pix = pix.scaled(800,600, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QLabel *label = new QLabel;
    label->setPixmap(pix);
    label->setFixedSize(pix.size());
    label->show();
}
