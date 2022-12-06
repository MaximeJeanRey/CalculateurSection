import QtQuick 2.15
import QtQuick.Controls 2.5

ApplicationWindow{

    width: 640
    height: 800

    id:main
    title: qsTr("MainWindow")

    visible: true

    MainShow {
        id: mainScreen
    }
}


