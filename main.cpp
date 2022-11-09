#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>

#include <QQuickItem>

#include <QDebug>


#include <iostream>
#include "QTableModel.h"
#include "Node.h"
#include "kmeans.h"
#include "connectui.h"
#include "main.h"


Kmeans m_kmeans;
QTableModel tableModel;
QQmlApplicationEngine *gEngine;

int main(int argc, char *argv[])
{

    qDebug() << "qstart";
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    gEngine = &engine;

    NODE_INFO node(1,1,0);
    tableModel.mysetNodeData(0,node);

    engine.rootContext()->setContextProperty("QTableModel", &tableModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    ConnectUI m_connectui;

    engine.rootContext()->setContextProperty("MConnectui", &m_connectui);

//    qmlRegisterType<ConnectUI>("MyConnectUI",1,0,"ConnectUI");


    engine.load(url);

    QObject *rootObject = engine.rootObjects().first();   //寻找根目录



    QObject * button_createdata = rootObject->findChild<QObject*>("button_createdata");

    if(button_createdata)
    {
        QObject::connect(button_createdata, SIGNAL(clicked()), &m_connectui, SLOT(button_createdata_clicked()));
    }

    QObject * button_start = rootObject->findChild<QObject*>("button_start");

    if(button_start)
    {
        QObject::connect(button_start, SIGNAL(clicked()), &m_connectui, SLOT(button_start_clicked()));
    }

    QObject::connect(&m_connectui,SIGNAL(dataChanged()),&m_connectui, SLOT(modelData_Changed()));

    return app.exec();
}
