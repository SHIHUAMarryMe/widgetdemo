

#include <QIcon>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>


#include "titlebar.h"




TitleBar::TitleBar(QFrame* parent)
         :QFrame{parent},
           m_Labels{std::make_pair(new QLabel{}, new QLabel{})},
           m_MainLayout{new QHBoxLayout{}}
{
    this->initUi();
    this->setUiPara();
    this->layoutItem();
}


void TitleBar::setTitle(const QString &str)noexcept
{
    m_Labels.first->setText(str);
}

void TitleBar::setLogo(const QIcon &icon)noexcept
{
}

void TitleBar::setLogo(const QString &str)noexcept
{
}


void TitleBar::setMinimumSize(const std::size_t &widthMM, const std::size_t &heightMM)noexcept
{
    this->QFrame::setMinimumSize(widthMM, heightMM);

    Queue<QToolButton*>::iterator beg = m_Buttons.begin();
    Queue<QToolButton*>::iterator last = m_Buttons.end();
    for(; beg != last; ++beg){
        (*beg)->setCheckable(true);
        (*beg)->setMinimumSize(widthMM/30, heightMM);
        (*beg)->setFocusPolicy(Qt::NoFocus);
        (*beg)->setArrowType(Qt::NoArrow);
    }

    m_Labels.first->setMinimumSize(widthMM/30, heightMM);
    m_Labels.second->setMinimumSize(widthMM/30, heightMM);
}


void TitleBar::initUi()
{
    std::size_t index{0};
    for(; index != 3; ++index){
        m_Buttons.push_back(new QToolButton{});
    }
}


void TitleBar::setUiPara()noexcept
{
}


void TitleBar::layoutItem()noexcept
{
    m_MainLayout->setAlignment(Qt::AlignCenter);
    m_MainLayout->setSpacing(0);
    m_MainLayout->setMargin(0);
    m_MainLayout->addWidget(m_Labels.first);
    m_MainLayout->addWidget(m_Labels.second);
    m_MainLayout->addStretch(0);

    auto beg = m_Buttons.begin();
    auto last = m_Buttons.end();
    for(; beg != last; ++beg){
        m_MainLayout->addWidget(*beg);
    }


    this->setLayout(m_MainLayout);
}





