import QtQuick
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Frame {
    ListView {
        implicitWidth: 250
        implicitHeight: 250

        model: 2
        delegate : RowLayout {
            CheckBox{}
            TextField{}
        }
    }
}
