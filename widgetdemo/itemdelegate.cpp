
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QPainter>
#include <QLabel>
#include <QWidget>

#include <typeinfo>


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

    painter->drawPixmap(backGroundRect, backGround);
}


QWidget* PixmapItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLabel* label{new QLabel{parent}};

    return label;
}


void PixmapItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(QLabel* label = dynamic_cast<QLabel*>(editor)){

        QPixmap backGround{index.data().value<QPixmap>()};
        label->setPixmap(backGround);

    }else{
        LOG("=============");
        throw std::bad_cast{};
    }
}


void PixmapItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QVariant value{index.data()};
    model->setData(index, value,Qt::EditRole);
}

void PixmapItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->QWidget::setGeometry(option.rect);
}


void PixmapItemDelegate::destroyEditor(QWidget *editor, const QModelIndex &index) const
{
    //nothing to do.
}


