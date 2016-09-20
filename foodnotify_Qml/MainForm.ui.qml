import QtQuick 2.5

Rectangle {
    property alias mouseArea: mouseArea

    width: 860
    height: 860

    MouseArea {
        id: mouseArea
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
   }

    Text {
        anchors.centerIn: parent
        text: "Hello World"
    }
}

