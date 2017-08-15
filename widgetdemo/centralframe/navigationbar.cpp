

#include <QPushButton>
#include <QHBoxLayout>
#include <QToolButton>

#include "navigationbar.h"



NavigationBar::NavigationBar(QFrame *parent)
              :QFrame{parent},
               m_MainLayout{new QHBoxLayout{}}
{
    this->initUi();
    this->initUiPara();
    this->layoutItem();
}


void NavigationBar::setMinimumSize(const std::size_t &widthMM, const std::size_t &heightMM)noexcept
{
    this->QFrame::setMinimumSize(widthMM, heightMM);
    for(auto button : m_NavigationBtns){
        button->setMinimumSize(widthMM/10, heightMM/3*2);
    }
}



void NavigationBar::initUi()
{
    std::size_t index{0};
    for(; index != 4; ++index){
        m_NavigationBtns.push_back(new QToolButton{});
    }
}

void NavigationBar::initUiPara()noexcept
{
    for(auto button : m_NavigationBtns){
        button->setFocusPolicy(Qt::NoFocus);
        button->setArrowType(Qt::NoArrow); //取消向下的箭头.
    }
}

void NavigationBar::layoutItem()noexcept
{
    m_MainLayout->addStretch();
    m_MainLayout->setAlignment(Qt::AlignBottom);
    m_MainLayout->setMargin(0);
    m_MainLayout->setSpacing(0);
    for(auto button : m_NavigationBtns){
        m_MainLayout->addWidget(button);
    }
    m_MainLayout->addStretch();

    this->setLayout(m_MainLayout);
}
