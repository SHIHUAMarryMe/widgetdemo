
#include <QVariant>

#include <algorithm>
#include <functional>




#include "listmodel.h"


ListModel::ListModel(QObject *parent)
          :QAbstractListModel{parent}
{

}


QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > m_Pixmaps.size()){
        return QVariant{};
    }


    if(role == Qt::DisplayRole || role == Qt::DecorationRole){
        QVariant var{m_Pixmaps[index.row()]}; //the QPixmap has a function operator QVariant.

        return var;
    }

    return QVariant{};
}


Qt::ItemFlags ListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid()){
        return (this->QAbstractListModel::flags(index) | Qt::ItemIsDropEnabled);
    }

    return (this->QAbstractListModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsSelectable
                                                   | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
}





bool ListModel::insertrRows(int row, int count,  const QModelIndex& parent)
{
    if(row < 0 || count < 1 || row > rowCount(parent)){
        return false;
    }

    std::size_t index{0};
    for(; index != count; ++index){
        m_Pixmaps.insert(row, nullptr);
    }

    return true;
}


bool ListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(count < 0 || row < 0 || row > rowCount(parent)
            || count > rowCount(parent) || (row+count) > rowCount(parent)){

        return false;
    }

    QQueue<QSharedPtr<QPixmap>>::iterator beg = m_Pixmaps.begin();
    QQueue<QSharedPtr<QPixmap>>::iterator last;
    beg += (row - 1);
    last = beg + count;

    m_Pixmaps.erase(beg, last);
}


std::size_t ListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }

    return m_Pixmaps.size();
}


bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() >= 0 && index.row < m_Pixmaps.size() &&
       (Qt::EditRole == role || Qt::DisplayRole == role)){
        m_Pixmaps[index.row()] = std::make_shared<QPixmap>(value.value<QPixmap>());
        emit dataChanged(index, index, QVector<int>{role});

        return true;
    }

    return false;
}


QModelIndex ListModel::sibling(int row, int column, const QModelIndex &idx) const
{
    if(!idx.isValid() || column != 0 || row >= m_Pixmaps.size()){
        return QModelIndex{};
    }

    return (this->QAbstractListModel::createIndex(row, 0));
}



void ListModel::sort(int column, Qt::SortOrder order)
{
    std::function<bool (const QSharedPtr<QPixmap>&, const QSharedPtr<QPixmap>&)> sorter
                        {std::bind(Sort{}, std::placeholders::_1, std::placeholders::_2, order)};

    QQueue<QSharedPtr<QPixmap>>::iterator beg = m_Pixmaps.begin();
    QQueue<QSharedPtr<QPixmap>>::iterator last = m_Pixmaps.end();

    std::sort(beg, last, sorter);
}

Qt::DropActions ListModel::supportedDropActions()const
{
    return (this->QAbstractListModel::supportedDropActions() | Qt::MoveAction);
}






