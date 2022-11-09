#ifndef CONNECTUI_H
#define CONNECTUI_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "main.h"



class ConnectUI : public QObject
{
    Q_OBJECT
public:
    explicit ConnectUI(QObject *parent = nullptr);

    void uiChartpointClear();

    void uiChartpointAdd(double m_x,double m_y);

signals:
    void dataChanged();

    void uidataclear();

    void drawchart(double x,double y);

public slots:
    void button_createdata_clicked();
    void button_start_clicked();

    void modelData_Changed();

};

#endif // CONNECTUI_H
