#include "parser.h"

#define LEN 8

void Parser::Cahnge(QPlainTextEdit *p)
{

    QString text = p->toPlainText();
    QString mask[LEN] = { "RUB", "руб.", "евро", "дол.", "reg", "permil", "pound", "trade"};
    QString symbol[LEN] = {"₽",  "₽",    "€",    "$",    "®",   "‰",      "£",     "™"};
    // в дальнейшем можно сделать словарь по типу значение - символ и записывать его в двумерный массив типа dictionary[][]
    qint32 pos = 0;

    while(true){
        qint32 fnd;
        fnd = text.indexOf("#@",pos);
        if (fnd == -1) return;
        pos = fnd + 1;
        int r = text.indexOf("@", fnd+2);
        int space = text.indexOf(" ", fnd);
        if((r < space || space == -1) && r!= -1){
            int symbol_index = -1;
            QString tomask = text.mid(fnd+2, r-fnd-2);
            for(int i = 0; i < LEN; ++i){
                if(tomask == mask[i]){
                    symbol_index = i;
                    break;
                }
            }
            text.insert(r+1, symbol[symbol_index]);
            text.remove(fnd, r-fnd+1);
            p->setPlainText(text);
        }
    }
}
