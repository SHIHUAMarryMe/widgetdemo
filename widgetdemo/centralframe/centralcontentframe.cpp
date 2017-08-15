

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>


#include "centralcontentframe.h"



CentralCententFrame::CentralCententFrame(QFrame *parent)
                    :QFrame{parent},
                     m_LeftFrame{new QFrame{}},
                     m_RightFrame{new QStackedWidget{}},
                     m_ButtonLayout{new QVBoxLayout{}},
                     m_MainLayout{new QHBoxLayout{}}
{
    this->initUi();
    this->initUiPara();
    this->layoutItem();
}


void CentralCententFrame::setMinimumSize(const std::size_t &widthMM, const std::size_t &heightMM)noexcept
{
    this->QFrame::setMaximumSize(widthMM, heightMM);//notice that: must do this!

    m_LeftFrame->setMinimumSize(widthMM/6, heightMM);
    m_RightFrame->setMinimumSize(widthMM/6*5, heightMM);


    Queue<QPushButton*>::iterator beg = m_Buttons.begin();
    Queue<QPushButton*>::iterator last = m_Buttons.end();

    for(; beg != last; ++beg){
        (*beg)->setMinimumSize(widthMM/6, heightMM/7);
    }
}



void CentralCententFrame::initUi()
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


void CentralCententFrame::initUiPara()noexcept
{
    //can set text to QPushButton
    Queue<QPushButton*>::iterator beg = m_Buttons.begin();
    Queue<QPushButton*>::iterator last = m_Buttons.end();
    for(; beg != last; ++beg){
        (*beg)->setFocusPolicy(Qt::NoFocus);
        (*beg)->setCheckable(true);
    }



    //show the top widget;
    m_RightFrame->setCurrentIndex(0);

}


void CentralCententFrame::layoutItem()noexcept
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
