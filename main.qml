import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.2
import QtCharts 2.3
//import MyConnectUI 1.0

ApplicationWindow  {
    visible: true
    width: 800
    height: 600
    color: "#cfc5c6"
    title: qsTr("Hello World")
    objectName: "rootRect"

    TextInput {
        id: textInput_clustnum
        x: 510
        y: 59
        width: 80
        height: 20
        text: qsTr("样本个数：")
        font.pixelSize: 12
    }

    Button {
        id: button_createdata
        x: 510
        y: 198
        width: 102
        height: 42
        text: qsTr("随机生成样本")
        objectName: "button_createdata"
        onClicked: {

        }
    }

    SpinBox {
        id: spinBox_datanum
        objectName: "spinBox_datanum"
        x: 606
        y: 50
        value: 5
        maximumValue: 9999
        font.pointSize: 15

    }

    SpinBox {
        id: spinBox_clustnum
        objectName: "spinBox_clustnum"
        x: 606
        y: 113
        value: 2
        maximumValue: 9999
        font.pointSize: 15
    }

    TextInput {
        id: textInput1_datanum
        x: 510
        y: 123
        width: 80
        height: 20
        text: qsTr("种类个数：")
        font.pixelSize: 12
    }

    Button {
        id: button_start
        x: 646
        y: 198
        width: 87
        height: 42
        text: qsTr("开始聚类")
        objectName: "button_start"
    }

    Rectangle {
        id: tableRct
        x: 501
        y: 266
        width: 248
        height: 311
        //           anchors.fill: parent
        color: "lightblue"

        MyTableView {
            width: 200
            height: 300
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.verticalCenterOffset: 100
            anchors.horizontalCenterOffset: -50
            anchors.centerIn: parent
        }
    }

    Rectangle {
        id: chartRct
        x: 16
        y: 12
        width: 450
        height: 450
        color: "#ffffff"

        ChartView {
            id: scatter
            x: 20
            y: 15
            width: 400
            height: 400

            ValueAxis {
                    id: myAxisX
                    min: 0
                    max: 100
                    tickCount: 1
                    labelsColor: "#fff"
                    labelFormat: "%f"
                }
                ValueAxis {
                    id: myAxisY
                    min: 0
                    max: 100
                    tickCount: 1
                    labelsColor: "#fff"
                    labelFormat: "%f"
                }

            ScatterSeries {
                id: chartseries
                name: "ScatterSeries"


                XYPoint {
                    x: 1
                    y: 1
                }

                XYPoint {
                    x: 2
                    y: 4
                }

                XYPoint {
                    x: 100
                    y: 2
                }

                XYPoint {
                    x: 5
                    y: 100
                }
            }
        }

    }

    Item {
        id: chartchange
        objectName: "chartchange"
        function addChartData(x,y)
        {
            chartseries.append(x,y)
        }

        function clearChartData()
        {
            chartseries.clear()
        }

    }


    Connections {
        target: MConnectui


        function onUidataclear()
        {
            console.log("clear");
            chartseries.clear()

        }

        function onDrawchart(x,y)
        {
            chartseries.append(x,y)
        }
    }

//    ConnectUI {
//        id: connectUIqml
//        function onDrawchart(x,y)
//        {
//            chartseries.append(x,y)
//        }
//    }

    Button {
        id: button_deletaall
        x: 16
        y: 476
        width: 102
        height: 42
        text: qsTr("清空")
        onClicked: {
            chartchange.clearChartData()
        }
    }

    Button {
        id: button_add
        x: 140
        y: 476
        width: 102
        height: 42
        text: qsTr("添加样本")
        onClicked: {
            chartchange.addChartData(2.1,2.3)
        }
    }

    Button {
        id: button_setcentrol
        x: 375
        y: 476
        width: 102
        height: 42
        text: qsTr("选为中心")
    }

    Button {
        id: button_deltaone
        x: 260
        y: 476
        width: 102
        height: 42
        text: "删除样本"
    }

}
