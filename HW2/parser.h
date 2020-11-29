/*
 * Класс Parser принимает ссылку на окно типа PlaintTextEdit и в данном окне меняет запись вида #@_____@ на символы по маске
 * Возможно было реализовать автозамну без использования конструкции #@__@, но есть риск автозамены текста который нет необходимости менять.
 */

#ifndef SYMBOLCHANGE_H
#define SYMBOLCHANGE_H

#include <QPlainTextEdit>

class Parser
{
public:

    static void Cahnge(QPlainTextEdit *p);

};

#endif // SYMBOLCHANGE_H
