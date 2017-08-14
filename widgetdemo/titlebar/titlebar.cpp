

#include <QIcon>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>


#include "titlebar.h"




TitleBar::TitleBar(const std::size_t &width, const std::size_t &height, QFrame* parent)
         :QFrame{parent},
           m_Labels{std::make_pair(new QLabel{}, new QLabel{})},
           m_MainLayout{new QHBoxLayout{}}
{
    this->setMinimumSize(width, height);


    this->initUi();
    this->setUiPara();
    this->layoutItem();
}


void TitleBar::setTitle(const QString &str)noexcept
{
    m_Labels.first->setText(str);
}


void TitleBar::initUi()
{
    std::size_t index{0};
    for(; index != 3; ++index){
        m_Buttons.append(new QPushButton{});
    }
}


void TitleBar::setUiPara()noexcept
{
    std::size_t height{ this->height()};
    std::size_t width{this->width()};

    QQueue<QToolButton*>::iterator beg = m_Buttons.begin();
    QQueue<QToolButton*>::iterator last = m_Buttons.end();
    for(; beg != last; ++beg){
        (*beg)->setCheckable(true);
        (*beg)->setFixedHeight((height)/3*2);
        (*beg)->setFixedWidth(width/15);
        (*beg)->setFocusPolicy(Qt::NoFocus);
        (*beg)->setArrowType(Qt::NoArrow);
    }
}


void TitleBar::layoutItem()noexcept
{
    m_MainLayout->setSpacing(0);
    m_MainLayout->setMargin(0);
    m_MainLayout->addWidget(m_Labels.first);
    m_MainLayout->addWidget(m_Labels.second);
    m_MainLayout->addStretch();

    auto beg = m_Buttons.begin();
    auto last = m_Buttons.end();

    for(; beg != last; ++beg){
        m_MainLayout->addWidget(*beg);
    }


    this->setLayout(m_MainLayout);
}


