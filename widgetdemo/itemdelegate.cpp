
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QPainter>


#include "itemdelegate.h"



PixmapItemDelegate::PixmapItemDelegate(QObject *parent)//noexcept(false).
                   :QStyledItemDelegate{parent}{}



void PixmapItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem option_2{option};//copy the option.


    this->initStyleOption(&option_2, index);

    QPixmap backGround{index.data().value<QPixmap>()};
    QRect backGroundRect{option.rect};

    painter->drawPixmap(backGroundRect, backGround);
}




