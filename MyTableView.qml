import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQml.Models 2.2

Rectangle {
    id: tableViewRct

//    width: 200
//    height: 300
    anchors.fill: parent

    border.color: "red"
    border.width: 2

    TableView {
        id: tableView

        anchors.fill: parent

        model: QTableModel
//        Component.onCompleted: {
////            model = QTableModel.model();
//            model: $QTableModel
//        }

        itemDelegate: tableViewDelegate
        headerDelegate: Rectangle {
            height: 35
            Text {
                anchors.centerIn: parent
                text: styleData.value
                color: "#46a4bb"
            }
        }

        TableViewColumn {
            role: "nodeX"
            title: "X"
            width: 30
        }

        TableViewColumn {
            role: "nodeY"
            title: "Y"
            width: 30
        }
        TableViewColumn {
            role: "nodeType"
            title: "Type"
            width: 30
        }
        TableViewColumn {
            role: "nodeClassification"
            title: "Classification"
            width: 30
        }
    }

    Component {
        id: tableViewDelegate

        Rectangle {
            height: 50
            width: 100

            Text {
                anchors.centerIn: parent
                color: "red"
                elide: styleData.elideMode
                text: styleData.value
                font.pointSize: 10
                font.bold: true
            }
        }
    }
}
