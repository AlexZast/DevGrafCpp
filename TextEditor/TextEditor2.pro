QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fswidget.cpp \
    main.cpp \
    shortcut.cpp \
    texteditor.cpp

HEADERS += \
    fswidget.h \
    shortcut.h \
    texteditor.h

FORMS += \
    shortcut.ui \
    texteditor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    help.qrc \
    style.qrc \
    translate.qrc

TRANSLATIONS += QtLanguage_en.ts
CODECFORSRC = UTF-8
