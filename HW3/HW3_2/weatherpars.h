#ifndef WEATHERPARS_H
#define WEATHERPARS_H

#include <QString>

class weatherPars
{
public:
    weatherPars();

    static QString parse(QString text, char *fn);
};

#endif // WEATHERPARS_H
