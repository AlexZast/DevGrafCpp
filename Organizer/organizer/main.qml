import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

import DataWorker 1.0

Window {
    id: _root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    DataWorker{
        id: _DataWorker

    }

//    Component.onCompleted: {
//        _DataWorker.saveD();
//    }


    AcceptButton{
        id: _button
        text: qsTr("Добавить задачу")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: parent.height / 35

        //Запись задачи в таск-лист, вызов метода addData
        onClicked: {console.log("Clicked2  " + _progress.currentIndex);
                    _DataWorker.addData(_calendar.day, _calendar.mouth, _calendar.year, _edit.text, _progress.currentIndex  );
        }

    }

    Text{
        id: _label
        text: qsTr("Введите задачу")
        font.pointSize: 12
        anchors.verticalCenter: _text.verticalCenter
        x: 10
    }

    Rectangle{
        id: _text
        width: parent.width * 3 / 4 - _label.width
        height: 30
        border.color: "black"
        border.width: 1
        anchors.left: _label.right
        anchors.margins: 5

        TextEdit{
            id: _edit
            width: 50
            font.pointSize: 12
            focus: true
            textMargin: 1
            anchors.verticalCenter: _text.verticalCenter
        }
    }

    Calendar{
        id: _calendar
        anchors.top: _text.bottom
        anchors.margins: 20
        anchors.right: _text.left
    }

    Text{
        id: _label2
        text: qsTr("Прогресс")
        font.pointSize: 12
        anchors.verticalCenter: _text.verticalCenter
        anchors.right: parent.right
        anchors.margins: 20
    }

    Tumbler {
        id: _progress
        width: 50
        height: 120
        model: 11
        font.pointSize: 11

        anchors.top: _label2.bottom
        anchors.horizontalCenter: _label2.horizontalCenter
        anchors.margins: 10
    }



}
