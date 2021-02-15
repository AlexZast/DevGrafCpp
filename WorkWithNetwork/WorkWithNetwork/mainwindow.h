#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "downloader.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void error();
    void slotDownloadProgress(qint64, qint64);
    void slotDone(const QUrl&, const QByteArray&);

private:
    Ui::MainWindow *ui;
    Downloader *downloader;



    void showPic(const QString&);
};
#endif // MAINWINDOW_H
