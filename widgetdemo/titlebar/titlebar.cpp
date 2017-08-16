

#include <QIcon>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

#include "titlebar.h"




TitleBar::TitleBar(QFrame* parent)
         :QFrame{parent},
           m_Labels{std::make_pair(new QLabel{}, new QLabel{})},
           m_MainLayout{new QHBoxLayout{}}
{

    this->setMouseTracking(true);

    this->initUi();
    this->setUiPara();
    this->layoutItem();
    this->initConnect();
    this->setItemObjectName();
}


void TitleBar::setTitle(const QString& str)noexcept
{
    m_Labels.first->setText(str);
}

void TitleBar::setLogo(const QString& url)noexcept
{
    QPixmap backgroundPic{url};
    QSize picSize{m_Labels.second->sizeHint() * 2};

    backgroundPic = backgroundPic.scaled(picSize,  Qt::KeepAspectRatio);
    m_Labels.second->setPixmap(backgroundPic);
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
    this->setFixedHeight(m_Labels.second->sizeHint().height()*2);

    for(auto button : m_Buttons){
        button->setCheckable(true);
        button->setFocusPolicy(Qt::NoFocus);
        button->setArrowType(Qt::NoArrow);
    }

    m_Buttons[0]->setIcon(QIcon{":/img/appbar.minus.png"});
    m_Buttons[1]->setIcon(QIcon{":/img/appbar.fullscreen.box.png"});
    m_Buttons[2]->setIcon(QIcon{":/img/appbar.close.png"});
}


void TitleBar::setFixedSize(const std::size_t &widthFixed, const std::size_t &heightFixed)noexcept
{
    this->QFrame::setFixedSize(widthFixed, heightFixed);

    Queue<QToolButton*>::iterator beg = m_Buttons.begin();
    Queue<QToolButton*>::iterator last = m_Buttons.end();
    for(; beg != last; ++beg){
        (*beg)->setFixedSize(widthFixed/30, heightFixed);
    }

    m_Labels.first->setFixedSize(widthFixed/15, heightFixed);
    m_Labels.second->setFixedSize(widthFixed/20, heightFixed);
}


//void TitleBar::setTheMinimumSize(const std::size_t& widthMM, const std::size_t& heightMM)noexcept
//{
//    this->setMinimumSize(widthMM, heightMM);

//    for(auto button : m_Buttons){
//        button->setMinimumSize(widthMM/30, heightMM);
//    }

//    m_Labels.first->setMinimumSize(widthMM/20, heightMM);
//    m_Labels.second->setMinimumSize(widthMM/20, heightMM);
//}


void TitleBar::layoutItem()noexcept
{

    QSize size{this->size()};

    m_MainLayout->setAlignment(Qt::AlignTop);
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


void TitleBar::initConnect()noexcept
{
    Queue<QToolButton*>::iterator beg = m_Buttons.begin();
    Queue<QToolButton*>::iterator end = m_Buttons.end();

    std::size_t index{0};
    for(; beg != end; ++beg, ++index){
        QObject::connect(*beg, &QToolButton::clicked,
                         [this, index]{ emit onClicked(index); }
                         );
    }
}


void TitleBar::setItemObjectName()noexcept
{
    m_Labels.first->setObjectName(QString{"TitleBarLabel"});
    m_Labels.second->setObjectName(QString{"TitleBarLabel"});

    m_Buttons[0]->setObjectName(QString{"TitleButton"});
    m_Buttons[1]->setObjectName(QString{"TitleButton"});

    m_Buttons[2]->setObjectName(QString{"TitleCloseButton"});

//    this->setObjectName(QString{"TitleBar"});
}





