/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.2
import QtQuick.Controls 6.2

Rectangle {
    id: rectangle

    //width: 640
    //height: 1200

        width: parent.width
        height: parent.height
    // Set it after*/
    Column {
        id: column
        x: parent.x
        y: parent.y + 15
        spacing: 5
        height: parent.height - 15
        width: parent.width

        Row {
            id: row1
            x: 8
            width: parent.width
            height: 50

            Label {
                id: label
                text: qsTr("Type d'installation :")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.bold: false
                font.family: "Arial"
                font.pointSize: 15
            }

            Item {
                id: item1
                width: 15
                height: 1
            }

            ComboBox {
                id: comboBox
                width: parent.width - 16 - x
                height: 50
                font.pointSize: 20
                currentIndex: 0
                model: ListModel {
                    id: listeInstalation
                    ListElement {
                        text: "Source"
                    }
                    ListElement {
                        text: "Terminaux"
                    }
                    ListElement {
                        text: "Tableau"
                    }
                }
               onCurrentIndexChanged: back.setInstallation(listeInstalation.get(currentIndex).text)
            }
        }

        Row {
            id: row2
            x: 8
            width: parent.width
            height: 100

            Label {
                id: label1
                text: qsTr("Type de cable : ")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.bold: false
                font.family: "Arial"
                font.pointSize: 15
            }

            Item {
                id: item2
                width: 15
                height: 1
            }

            Column {
                id: column1
                width: parent.width - x
                height: parent.height
                anchors.verticalCenter: parent.verticalCenter

                ComboBox {
                    id: typedecable
                    width: parent.width - 16 - x
                    height: 50
                    font.pointSize: 20

                    model: ListModel {
                        id: listeElement
                        ListElement {
                            text: "Cuivre"
                        }
                        ListElement {
                            text: "Aluminium"
                        }
                    }
                    onCurrentIndexChanged: back.setCableElementType(listeElement.get(currentIndex).text)
                }

                ComboBox {
                    id: typedecable1
                    width: parent.width - 16 - x
                    height: 50
                    model: ListModel {
                        id: listePhase
                        ListElement {
                            text: "Monophasé"
                        }

                        ListElement {
                            text: "Triphasé"
                        }
                    }
                    onCurrentIndexChanged: back.setCablePhaseType(listePhase.get(currentIndex).text)
                    font.pointSize: 20
                }
            }
        }

        Row {
            id: row3
            x: 8
            width: parent.width
            height: 50
            Label {
                id: label6
                text: qsTr("Longueur du cable :")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 15
                font.family: "Arial"
                font.bold: false
            }

            Item {
                id: item3
                width: 15
                height: 1
            }

            TextField {
                id: textField5
                x: parent.x + 8
                width: parent.width - 50 - x
                placeholderText: qsTr("Longueur")
                font.pointSize: 19
                validator: IntValidator {bottom: 1; top: 10000}
            }

            Item {
                id: item4
                width: 7
                height: 1
            }

            Label {
                id: label7
                text: qsTr("m")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 15
                font.family: "Arial"
                font.bold: false
            }
        }

        Row {
            id: row4
            x: 8
            width: parent.width
            height: 50
            Label {
                id: label8
                text: qsTr("Valeur :")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 15
                font.family: "Arial"
                font.bold: false
            }

            Item {
                id: item5
                width: 15
                height: 1
            }

            TextField {
                id: textField6
                x: parent.x + 8
                width: parent.width - 160
                placeholderText: qsTr("Valeur")
                font.pointSize: 19
            }

            Item {
                id: item6
                width: 7
                height: 1
            }

            ComboBox {
                id: comboBox1
                width: parent.width - 16 - textField6.width - label8.width
                       - item6.width - item5.width
                model: ListModel {
                    id: model4
                    ListElement {
                        text: "A"
                    }

                    ListElement {
                        text: "W"
                    }
                    ListElement {
                        text: "SA"
                    }
                }
                font.pointSize: 13
            }
        }
        Row {
            id: row5
            x: 8
            width: parent.width
            height: 50
            Label {
                id: label9
                text: qsTr("Chute de tension relative max : ")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 15
                font.family: "Arial"
                font.bold: false
            }

            Item {
                id: item7
                width: 15
                height: 1
            }

            TextField {
                id: textField7
                x: parent.x + 8
                width: parent.width - 50 - x
                placeholderText: qsTr("Chute")
                font.pointSize: 19
                validator: IntValidator {bottom: 1; top: 130}
            }

            Item {
                id: item8
                width: 7
                height: 1
            }

            Label {
                id: label10
                text: qsTr("%")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 15
                font.family: "Arial"
                font.bold: true
            }
        }

        Item {
            id: item9
            width: 200
            height: 45
        }

        Rectangle {
            id: rectangle1
            width: parent.width
            height: 5
            color: "#2f2f2f"
        }

        Item {
            id: item10
            width: 200
            height: 45
        }

        Row {
            id: row6
            x: 8
            width: parent.width
            height: 50
            opacity: 1

            Label {
                id: label5
                x: parent.x + 8
                text: qsTr("Chute de tension réele (%) : ")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 15
                font.family: "Arial"
                font.bold: true
            }

            Item {
                id: item11
                width: 15
                height: 1
            }

            TextField {
                id: textField8
                x: parent.x + 8
                width: parent.width - 50 - x
                font.pointSize: 19
                placeholderText: qsTr("Text Field")
                readOnly: true
            }

            Item {
                id: item12
                width: 7
                height: 1
            }

            Label {
                id: label13
                text: qsTr("%")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 15
                font.family: "Arial"
                font.bold: true
            }
        }

        Row {
            id: row7
            x: 8
            width: parent.width
            height: 50
            opacity: 1

            Label {
                id: label12
                x: textField.x
                text: qsTr("Section : ")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 15
                font.family: "Arial"
                font.bold: true
            }

            Item {
                id: item13
                width: 15
                height: 1
            }

            TextField {
                id: textField9
                x: parent.x + 8
                width: parent.width - 180 - x
                font.pointSize: 19
                placeholderText: qsTr("Text Field")
            }

            Label {
                id: label2
                text: qsTr("mm²")
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 15
            }
        }
        Button {
            id: button
            text: qsTr("Obtenir section")
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Verdana"
            onClicked: back.test()
        }
    }

    MouseArea {
        id: mouseArea
        x: 0
        y: 0
        z: -1 //permet de ne pas interférer avec les autres éléments
        width: parent.width
        height: parent.height
        onClicked: Qt.inputMethod.hide()
    }
    states: [
        State {
            name: "clicked" 
            //            when: button.checked
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/


