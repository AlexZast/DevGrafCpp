#include "TextEditor.h"
#include <QApplication>
#include <QtTest>
#include "test_texteditor.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    QTest::qExec(new Test_TextEditor, argc, argv);
    return 0;


//    TextEditor w;
//    w.show();
//    return a.exec();






}
