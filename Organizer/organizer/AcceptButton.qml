import QtQuick 2.0

Rectangle {
    id: _newButtonName

    property color first: "#8000FFFF"
    property color second: "#800000FF"
    signal clicked;

    gradient: Gradient {
              GradientStop { position: 0.0; color: first }
              GradientStop { position: 0.2; color: second }
              GradientStop { position: 0.5; color: first }
              GradientStop { position: 1.0; color: first }
    }

    width: 15 + _txt.width;
    height: 30
    border.color: "grey"
    border.width: 1
    property alias text: _txt.text

    Text {
        id: _txt

        color: "#281020"
        font.family: "Bahnschrift SemiLight"
        font.italic: true
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 14

        anchors.centerIn: parent

    }

    MouseArea{
        id: _mouse
        anchors.fill: parent
        onClicked: parent.clicked();

        onPressed: {
            _newButtonName.first = "#800000FF"
            _newButtonName.second = "#8000FFFF"
            }

        onReleased: {
            _newButtonName.first = "#8000FFFF"
            _newButtonName.second = "#800000FF"
        }
    }




}


