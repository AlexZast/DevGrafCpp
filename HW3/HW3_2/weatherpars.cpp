#include "weatherpars.h"

weatherPars::weatherPars()
{

}

QString weatherPars::parse(QString text, char *fn)
{
    qint32 fnd = text.indexOf(fn, 0);
    qint32 start = text.indexOf(">", fnd);
    qint32 stop = text.indexOf("<", fnd);
    return text.mid(start+1,stop-start-1);
}
