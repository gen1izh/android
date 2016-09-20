import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 400

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {

        }
    }



    TextEdit {
        id: textEdit1
        x: 0
        y: 20
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.bold: true
        font.pixelSize: 12
    }
}

