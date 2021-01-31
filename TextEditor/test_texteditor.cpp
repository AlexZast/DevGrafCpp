#include "test_texteditor.h"

#include <QTextEdit>

Test_TextEditor::Test_TextEditor(QObject *parent) : QObject(parent)
{

}

void Test_TextEditor::testGUI()
{
    TextEditor nw;
    nw.show();
    QTest::keyClicks((nw.getText()), "Test string");
    QCOMPARE(nw.getText()->toPlainText(), "Test string");
}
