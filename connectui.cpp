#include "connectui.h"

#include <QDebug>
#include <QQmlContext>
#include <QQuickItem>


ConnectUI::ConnectUI(QObject *parent) : QObject(parent)
{

}



void ConnectUI::uiChartpointClear()
{
    QObject *rootObject = gEngine->rootObjects().first();   //寻找根目录
    QObject * chartchange = rootObject->findChild<QObject*>("chartchange");
    QMetaObject::invokeMethod(chartchange, "clearChartData");//注意参数
}

void ConnectUI::uiChartpointAdd(double m_x,double m_y)
{
    QObject *rootObject = gEngine->rootObjects().first();   //寻找根目录
    QObject * chartchange = rootObject->findChild<QObject*>("chartchange");
    QMetaObject::invokeMethod(chartchange, "addChartData",Q_ARG(QVariant, m_x),Q_ARG(QVariant, m_y));//注意参数

}




void ConnectUI::button_createdata_clicked()
{

    QObject *rootObject = gEngine->rootObjects().first();   //寻找根目录
    QObject * spinBox_clustnum = rootObject->findChild<QObject*>("spinBox_clustnum");
    QObject * spinBox_datanum = rootObject->findChild<QObject*>("spinBox_datanum");

    m_kmeans.dataNum = spinBox_datanum->property("value").toInt();
    m_kmeans.dataClust = spinBox_clustnum->property("value").toInt();


    m_kmeans.clearData();
    m_kmeans.randomGenerateNode();
    m_kmeans.showDataSet();
    unsigned int i=0;

    uiChartpointClear();
    tableModel.mysetNodeDelteALL();
    for(i=0;i<m_kmeans.dataSet.size();i++)
    {
        tableModel.mysetNodeData(i,m_kmeans.dataSet[i]);
//        emit drawchart(m_kmeans.dataSet[i].x,m_kmeans.dataSet[i].y);
        uiChartpointAdd(m_kmeans.dataSet[i].x,m_kmeans.dataSet[i].y);
    }

}




void ConnectUI::button_start_clicked()
{
    m_kmeans.randomCentroids();
    m_kmeans.showCentroids();
    m_kmeans.runKmeans();
    m_kmeans.showCentroids();

    unsigned int i=0;

//    tableModel.mysetNodeDelteALL();
    uiChartpointClear();
    tableModel.mysetNodeDelteALL();
    for(i=0;i<m_kmeans.dataSet.size();i++)
    {
        tableModel.mysetNodeData(i,m_kmeans.dataSet[i]);
        uiChartpointAdd(m_kmeans.dataSet[i].x,m_kmeans.dataSet[i].y);
    }
    for(i=0;i<m_kmeans.centroids.size();i++)
    {
        tableModel.mysetNodeData(i,m_kmeans.centroids[i]);
        uiChartpointAdd(m_kmeans.centroids[i].x,m_kmeans.centroids[i].y);
    }

}

void ConnectUI::modelData_Changed()
{
//    gEngine->rootContext()->setContextProperty("QTableModel", &tableModel);
//    const QUrl url(QStringLiteral("qrc:/main.qml"));

//    gEngine->load(url);
    emit drawchart(3,3);
    qDebug()<<"%%%%%";
}
