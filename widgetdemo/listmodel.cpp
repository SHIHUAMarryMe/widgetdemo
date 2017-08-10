
#include <QVariant>






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

}
