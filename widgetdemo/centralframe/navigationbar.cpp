

#include <QPushButton>
#include <QHBoxLayout>
#include <QToolButton>
#include <QDebug>
#include <cassert>

#include "navigationbar.h"



NavigationBar::NavigationBar(QFrame *parent)
              :QFrame{parent},
               m_MainLayout{new QHBoxLayout{}}
{
    this->initUi();
    this->initUiPara();
    this->layoutItem();
    this->initConnect();
    this->setItemObjectName();
}


void NavigationBar::setFixedSize(const std::size_t &widthFixed, const std::size_t &heightFixed)noexcept
{
    this->QFrame::setFixedSize(widthFixed, heightFixed);
    for(auto button : m_NavigationBtns){
        button->setFixedSize(widthFixed/10, heightFixed/2);
    }
}


void NavigationBar::setTheMinimumSize(const std::size_t& widthMM, const std::size_t& heightMM)noexcept
{
    this->QFrame::setMinimumSize(widthMM, heightMM);
    for(auto button : m_NavigationBtns){
        button->setFixedSize(widthMM/10, heightMM/2);
    }
}



void NavigationBar::initUi()
{
    std::size_t index{0};
    for(; index != 4; ++index){
        m_NavigationBtns.push_back(new QPushButton{});
    }
}

void NavigationBar::initUiPara()noexcept
{
    const std::size_t widthMM{this->widthMM()};
    const std::size_t heightMM{this->heightMM()};

    for(auto button : m_NavigationBtns){
        button->setFocusPolicy(Qt::NoFocus);
        button->setCheckable(true);
        button->setFlat(true);
        button->setMinimumSize(widthMM/10, heightMM/2);
    }

    m_NavigationBtns[0]->setChecked(true);

    m_NavigationBtns[0]->setText(tr("Home"));
    m_NavigationBtns[1]->setText(tr("Message"));
    m_NavigationBtns[2]->setText(tr("Leaf"));
    m_NavigationBtns[3]->setText(tr("Chart"));
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

void NavigationBar::initConnect()noexcept
{
    Queue<QPushButton*>::iterator beg = m_NavigationBtns.begin();
    Queue<QPushButton*>::iterator end = m_NavigationBtns.end();

    std::size_t index{0};
    for(; beg != end; ++beg, ++index){
        QObject::connect(*beg, &QPushButton::clicked,
                         [this, index]{ emit onStackWidgetIndexChanged(index); }
                        );
    }
}


void NavigationBar::setItemObjectName()noexcept
{
    m_NavigationBtns[0]->setObjectName(QString{"NavigationBtn1"});
    m_NavigationBtns[1]->setObjectName(QString{"NavigationBtn2"});
    m_NavigationBtns[2]->setObjectName(QString{"NavigationBtn3"});
    m_NavigationBtns[3]->setObjectName(QString{"NavigationBtn4"});

//    this->setObjectName(QString{"NavigationBar"});
}

