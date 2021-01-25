import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3


Item {
    property int day: _day.currentItem.text
    property string mouth: _mouth.currentItem.text
    property int year: _year.currentItem.text

    property var mouthModel: ["Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"]

    ListModel {
        id: yearModel
    }

    ListModel{
        id: dayModel
    }

    Component.onCompleted: {
        loadSampleYears();
        loadSampleDays();
    }

    function loadSampleYears() {
        for (var i = 2020; i < 2050; i++) {
            yearModel.append({i});
        }
    }
    function loadSampleDays() {
        for (var i = 1; i < 32; i++) {
            dayModel.append({i});
        }
    }

    RowLayout {
        id: rowLayout
        anchors.fill: parent

        Tumbler {
            id: _day
            width: 53
            height: 120
            model: dayModel
            font.pointSize: 11
        }

        Tumbler {
            id: _mouth
            width: 53
            height: 120
            model: mouthModel
            font.pointSize: 11
        }

        Tumbler {
            id: _year
            width: 53
            height: 120
            model: yearModel
            font.pointSize: 11
        }

    }
}
