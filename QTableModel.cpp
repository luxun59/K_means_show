#include "QTableModel.h"

#include "main.h"

#include <QQmlApplicationEngine>

#include <QQmlContext>


QTableModel::QTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_showdata = {
    };

    m_roleName.insert(nodeXRole, "nodeX");
    m_roleName.insert(nodeYRole, "nodeY");
    m_roleName.insert(nodeTypeRole, "nodeType");
    m_roleName.insert(nodeclassification,"nodeClassification");
}

QAbstractItemModel *QTableModel::model()
{
    return this;
}


int QTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_showdata.count();
}

int QTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 2;
}

QVariant QTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role)
    {
    case nodeXRole:
        return m_showdata[index.row()].x;
    case nodeYRole:
        return m_showdata[index.row()].y;
    case nodeTypeRole:
        return m_showdata[index.row()].type;
    case nodeclassification:
        return m_showdata[index.row()].classification;
    default:
        break;
    }

    // FIXME: Implement me!
    return QVariant();
}

//QModelIndex QTableModel::index(int row, int column, const QModelIndex &parent) const
//{
//    if(!hasIndex(row, column, parent))
//    {
//        return QModelIndex();
//    }

//    return createIndex(row, column, parent.internalId());
//}

QHash<int, QByteArray> QTableModel::roleNames() const
{
    return m_roleName;
}


void QTableModel::mysetNodeData(int row, NODE_INFO &node)
{
    beginResetModel();
    m_showdata.append(node);
    endResetModel();
//    emit dataChanged();
}

void QTableModel::mysetNodeDelteALL()
{
    m_showdata.clear();
}
//QObject::connect(&tableModel,SIGNAL(dataChanged()),&tableModel, SLOT(modelData_Changed()));
//bool QTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
//{
//    if (!index.isValid())
//        return false;

//    if (role == Qt::EditRole) {
//        const int row = index.row();
//        switch (index.column())
//        {
//        case 0: m_modelData[row].name = value.toString(); break;
//        case 1: m_modelData[row].sex = (value.toString() == "man") ? 1 : 0; break;
//        case 2: m_modelData[row].age = value.toInt(); break;
//        case 3: m_modelData[row].score = value.toInt(); break;
//        }
//        //发送信号触发刷新
//        emit dataChanged(index, index, QVector<int>() << role);
//        return true;
//    }

//    if (role == Qt::CheckStateRole && index.column() == CHECK_BOX_COLUMN)
//    {
//        if (value == Qt::Checked)
//        {
//            m_modelData[index.row()].bChecked = true;
//        }
//        else
//        {
//            m_modelData[index.row()].bChecked = false;
//        }
//        return true;
//    }

//    return false;
//    //return QAbstractTableModel::setData(index, value, role);

//}


