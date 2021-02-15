#ifndef URLPARSER_H
#define URLPARSER_H

#include <QObject>

class urlParser : public QObject
{
    Q_OBJECT
public:
    explicit urlParser(QObject *parent = nullptr);
    QList<QString> *getUrls(const QString&);

signals:

private:


};

#endif // URLPARSER_H
