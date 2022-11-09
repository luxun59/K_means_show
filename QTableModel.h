#ifndef QTABLEMODEL_H
#define QTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>

#include <list>
#include <vector>

#include <QQmlApplicationEngine>

#include <QQmlContext>


#include "Node.h"

class QTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit QTableModel(QObject *parent = nullptr);

    Q_INVOKABLE QAbstractItemModel *model();

public:
    enum TABLE_ITEM_ROLE
    {
        nodeXRole = Qt::DisplayRole+1,
        nodeYRole,
        nodeTypeRole,
        nodeclassification,
    };


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash <int, QByteArray> roleNames() const override;
//    QModelIndex index(int row, int column, const QModelIndex &parent) const override;

//    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) Q_DECL_OVERRIDE;

    void mysetNodeData(int row,NODE_INFO &node);

    void mysetNodeDelteALL();
signals:
    void dataChanged();

private:
    QList <NODE_INFO> m_showdata;
    QHash<int, QByteArray> m_roleName;
};

#endif // QTABLEMODEL_H
