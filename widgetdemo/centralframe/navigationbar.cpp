

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

void NavigationBar::initUi()
{
    std::size_t index{0};
    for(; index != 4; ++index){
        m_NavigationBtns.append(new QPushButton{});
    }
}

void NavigationBar::initUiPara()noexcept
{
    std::size_t width{this->widthMM()};
    std::size_t height{this->heightMM()};

    for(auto button : m_NavigationBtns){
        button->setMinimumSize(width/10, height);
        button->setFocusPolicy(Qt::NoFocus);
        button->setArrowType(Qt::NoArrow); //取消向下的箭头.
    }
}

void NavigationBar::layoutItem()noexcept
{

    m_MainLayout->setMargin(0);
    m_MainLayout->setSpacing(0);
    m_MainLayout->addStretch();
    for(auto button : m_NavigationBtns){
        m_MainLayout->addWidget(button);
    }
    m_MainLayout->addStretch();

    this->setLayout(m_MainLayout);
}
