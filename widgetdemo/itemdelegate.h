#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H



#include <QStyledItemDelegate>
#include <QDebug>


class QStyleOptionViewItem;
class QPinter;
class QModelIndex;




class PixmapItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    PixmapItemDelegate(QObject* parent = nullptr);
    virtual ~PixmapItemDelegate()=default;

    PixmapItemDelegate(const PixmapItemDelegate&)=delete;
    PixmapItemDelegate& operator=(const PixmapItemDelegate&)=delete;


    //In display model
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index)const override;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void destroyEditor(QWidget* editor, const QModelIndex& index)const override;

};




#endif // ITEMDELEGATE_H
