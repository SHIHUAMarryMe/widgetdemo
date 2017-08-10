#ifndef LISTMODEL_H
#define LISTMODEL_H


#include <QAbstractListModel>
#include <QStringListModel>
#include <QQueue>

#include <memory>

class QListView;
class QPixmap;
class QVariant;


class ListModel: public QAbstractListModel
{
    Q_OBJECT

public:

    template<typename Ty>
    using QSharedPtr = std::shared_ptr<Ty>;

    ListModel(QObject* parent = nullptr);

    ListModel(const ListModel&)=delete;
    ListModel& operator=(const ListModel&)=delete;


    virtual QVariant	data(const QModelIndex &index, int role) const;
    virtual Qt::ItemFlags	flags(const QModelIndex &index) const;
    virtual bool	insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    virtual bool	removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    virtual std::size_t	    rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual bool	setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual QModelIndex	sibling(int row, int column, const QModelIndex &idx) const;
    virtual void	sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
    virtual Qt::DropActions	supportedDropActions() const;

private:
    QQueue<QSharedPtr<QPixmap>> m_Pixmaps{};

};





#endif // LISTMODEL_H
