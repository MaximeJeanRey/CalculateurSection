import QtQuick
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    ToDoList {
        anchors.centerIn: parent
    }
}
