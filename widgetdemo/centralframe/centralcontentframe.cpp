

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QDebug>

#include "centralcontentframe.h"



CentralContentFrame::CentralContentFrame(QFrame *parent)
                    :QFrame{parent},
                     m_LeftFrame{new QFrame{}},
                     m_RightFrame{new QStackedWidget{}},
                     m_ButtonLayout{new QVBoxLayout{}},
                     m_MainLayout{new QHBoxLayout{}}
{
    this->initUi();
    this->initUiPara();
    this->layoutItem();
    this->initConnect();
}


void CentralContentFrame::setFixedSize(const std::size_t &widthFixed, const std::size_t &heightFixed)noexcept
{
    this->QFrame::setFixedSize(widthFixed, heightFixed);//notice that: must do this!

    m_LeftFrame->setFixedSize(widthFixed/6, heightFixed);
    m_RightFrame->setFixedSize(widthFixed/6*5, heightFixed);


    Queue<QPushButton*>::iterator beg = m_Buttons.begin();
    Queue<QPushButton*>::iterator last = m_Buttons.end();

    for(; beg != last; ++beg){
        (*beg)->setFixedSize(widthFixed/6, heightFixed/7);
    }
}



void CentralContentFrame::initUi()
{
   std::size_t index{0};
   for(; index != 3; ++index){
       m_Buttons.push_back(new QPushButton{});
   }

   index = 0;
   for(; index != 3; ++index){
       m_WidgetForStack.push_back(new QFrame{});
   }
}


void CentralContentFrame::initUiPara()noexcept
{
    //can set text to QPushButton
    Queue<QPushButton*>::iterator beg = m_Buttons.begin();
    Queue<QPushButton*>::iterator last = m_Buttons.end();
    for(; beg != last; ++beg){
        (*beg)->setFocusPolicy(Qt::NoFocus);
        (*beg)->setCheckable(true);
    }

}


void CentralContentFrame::layoutItem()noexcept
{
    Queue<QPushButton*>::iterator beg = m_Buttons.begin();
    Queue<QPushButton*>::iterator last = m_Buttons.end();

    m_ButtonLayout->setAlignment(Qt::AlignCenter);
    m_ButtonLayout->setSpacing(0);
    m_ButtonLayout->setMargin(0);
    for(; beg != last; ++beg){
        m_ButtonLayout->addWidget(*beg);
    }
    m_ButtonLayout->addStretch(0);
    m_LeftFrame->setLayout(m_ButtonLayout);


    Queue<QFrame*>::iterator beg_1 = m_WidgetForStack.begin();
    Queue<QFrame*>::iterator end_1 = m_WidgetForStack.end();
    for(; beg_1 != end_1; ++beg_1){
        m_RightFrame->addWidget(*beg_1);
    }

    m_MainLayout->setSpacing(0);
    m_MainLayout->setMargin(0);
    m_MainLayout->addWidget(m_LeftFrame);
    m_MainLayout->addWidget(m_RightFrame);


    this->setLayout(m_MainLayout);
}


void CentralContentFrame::initConnect()noexcept
{
    Queue<QPushButton*>::iterator beg = m_Buttons.begin();
    Queue<QPushButton*>::iterator end = m_Buttons.end();

    std::size_t index{0};
    for(; beg != end; ++beg, ++index){
        QObject::connect(*beg, &QPushButton::clicked,
                         [this, index]{ emit currentButtonIndex(index); }
                         );
    }


    QObject::connect(this, &CentralContentFrame::currentButtonIndex, this, &CentralContentFrame::onCurrentButtonIndexChanged);
}


void CentralContentFrame::onCurrentButtonIndexChanged(std::size_t index)noexcept
{
    LOG(index);
    m_RightFrame->setCurrentIndex(index);
}


void CentralContentFrame::setItemObjectName()noexcept
{
    for(auto contentButton : m_Buttons){
        contentButton->setObjectName(QString{"ContentButton"});
    }
}
