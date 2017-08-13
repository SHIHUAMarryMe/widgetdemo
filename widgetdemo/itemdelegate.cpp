
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QPainter>


#include "itemdelegate.h"



PixmapItemDelegate::PixmapItemDelegate(QObject *parent)//noexcept(false).
                   :QStyledItemDelegate{parent}{}



void PixmapItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem option_2{option};//copy the option.


    //for fill Qt Style sheet.
    this->initStyleOption(&option_2, index);

    QPixmap backGround{index.data().value<QPixmap>()};
    QRect backGroundRect{option.rect.topLeft(), backGround.size()};


    qDebug() << backGroundRect;

    painter->drawPixmap(backGroundRect, backGround);
}




