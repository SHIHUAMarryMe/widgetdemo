#ifndef LISTMODEL_H
#define LISTMODEL_H


#include <QQueue>
#include <QList>
#include <QAbstractListModel>


#include <memory>
#include <type_traits>


#include "utilities.h"

class QListView;
class QPixmap;
class QVariant;
class QAbstractListModel;
class QModelIndex;


class ListModel: public QAbstractListModel
{
    Q_OBJECT

public:

    template<typename Ty>
    using QSharedPtr = std::shared_ptr<Ty>;

    explicit ListModel(QObject* parent = nullptr);

    ListModel(const ListModel&)=delete;
    ListModel& operator=(const ListModel&)=delete;


    virtual QVariant	data(const QModelIndex &index, int role) const override;
    virtual Qt::ItemFlags	flags(const QModelIndex &index) const override;
    virtual bool	insertRows(int row, int count, const QModelIndex &parent = QModelIndex())  override;
    virtual bool	removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    virtual int	    rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual bool	setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    virtual QModelIndex	sibling(int row, int column, const QModelIndex &idx) const override;
    virtual void	sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
    virtual Qt::DropActions	supportedDropActions() const override;


    void addPixmaps(QList<QPixmap>&& list);
    void addPixmaps(const QList<QPixmap>& list);

private:
    struct Sort
    {
        inline bool operator()(const QSharedPtr<QPixmap>& lh, const QSharedPtr<QPixmap>& rh, Qt::SortOrder order)const noexcept
        {
            if(order == Qt::AscendingOrder){

                if(lh < rh){
                    return true;
                }

                return false;
            }


            if(order == Qt::DescendingOrder){
                if(lh > rh){
                    return true;
                }

                return false;
            }
        }
    };


    template<typename Iter, typename = typename std::enable_if<
                                       std::is_copy_constructible<Iter>::value ||
                                       std::is_copy_assignable<Iter>::value, void>::type>
    void append(Iter begin, Iter last);


    QQueue<QSharedPtr<QPixmap>> m_Pixmaps{};

};





#endif // LISTMODEL_H
