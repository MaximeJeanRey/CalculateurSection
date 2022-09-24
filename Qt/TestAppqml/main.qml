import QtQuick 2.15
import QtQuick.Controls 6.3
Window {
    // visible is false by default
    transientParent: null
    visible: true

    Item {
        Rectangle {
            id: rectangle
            x: 0
            y: 0
            width: 1080
            height: 2040
            color: "#b6b0b0"

            Rectangle {
                id: rectangle1
                height: 136
                color: "#3e5591"
                border.color: "#4575f2"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                clip: true
                anchors.topMargin: 0
                anchors.leftMargin: 0
                anchors.rightMargin: 0

                ToolButton {
                    id: toolButton
                    x: 22
                    y: 30
                    width: 98
                    height: 76
                    text: qsTr(">")
                    font.weight: Font.Normal
                    display: AbstractButton.TextOnly
                    checkable: false
                    icon.color: "#ddffffff"
                    font.family: "Tahoma"
                    font.bold: true
                    font.pointSize: 29
                    flat: false
                    scale: 1.2
                    icon.width: 34
                }

                Text {
                    id: text1
                    x: 234
                    y: 29
                    text: qsTr("Calculateur de section")
                    font.pixelSize: 59
                    font.bold: true
                }
            }

            Rectangle {
                id: rectangle2
                x: 600
                y: 1176
                width: 684
                height: 1136
                color: "#5c6773"
                radius: 207
            }

            Label {
                id: label
                x: 811
                y: 174
                width: 261
                text: qsTr("Type de câble")
                anchors.horizontalCenterOffset: 10
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 32
            }

            ComboBox {
                id: comboBox
                x: 763
                y: 238
                width: 357
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }

            ComboBox {
                id: comboBox1
                x: 762
                y: 356
                width: 357
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.horizontalCenterOffset: 0
            }

            Label {
                id: label1
                x: 810
                y: 292
                width: 330
                text: qsTr("Matière du cable")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.horizontalCenterOffset: 10
                font.pointSize: 32
            }

            Rectangle {
                id: rectangle3
                x: 201
                y: 497
                width: 479
                height: 39
                color: "#ffffff"
                radius: 24.5

                TextInput {
                    id: textInput
                    x: 25
                    y: 12
                    width: 427
                    height: 29
                    text: qsTr("Text Input")
                    font.pixelSize: 12
                    anchors.horizontalCenterOffset: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

        }

    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:2040;width:1080}D{i:2}D{i:6}D{i:11}
}
##^##*/
