#include "urlparser.h"

#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>

#include <QDebug>

urlParser::urlParser(QObject *parent) : QObject(parent)
{

}

QList<QString> *urlParser::getUrls(const QString &request)
{
    QList<QString> *a = new QList<QString>;
    QString yandexUrl = "https://yandex.ru/images/search?text=" + request;

    // Получение html
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(yandexUrl)));
    QEventLoop event;
    QObject::connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    response->deleteLater();
    QString html =  response->readAll();
    //qDebug() << html;

    // Парсинг url  в лист
    qint32 nul = 0, fnd, start, stop;

    for (int i = 0; i < 3; ++i){
        // начало картинки
        fnd = html.indexOf("serp-item serp-item_type_search serp-item_group_search", nul);
        // ищем оригинал
        fnd = html.indexOf("origin", fnd);
        // ищем ссылку
        start = html.indexOf("https", fnd);
        stop = html.indexOf("\"", start);
        nul = stop;
        QString finde = html.mid(start, stop-start);
        a->push_back(finde);
    }



    return a;
}
