#ifndef TEST_TEXTEDITOR_H
#define TEST_TEXTEDITOR_H

#include <QObject>
#include "TextEditor.h"
#include <QtTest>

class Test_TextEditor : public QObject
{
    Q_OBJECT
public:
    explicit Test_TextEditor(QObject *parent = nullptr);

signals:


private slots:

// методы для тестирования
    void testGUI();



};

#endif // TEST_TEXTEDITOR_H
