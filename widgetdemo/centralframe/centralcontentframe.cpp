

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>



#include "centralcontentframe.h"



CentralCententFrame::CentralCententFrame(QFrame *parent)
                    :QFrame{parent},
                     m_LeftFrame{new QFrame{}},
                     m_RightFrame{new QFrame{}},
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
    std::size_t width{this->widthMM()};
    std::size_t height{this->heightMM()};

    m_LeftFrame->setMinimumSize(width/5, height);
    m_RightFrame->setMinimumSize(width/5*4, height);


    Queue<QPushButton*>::iterator beg = m_Buttons.begin();
    Queue<QPushButton*>::iterator last = m_Buttons.end();

    for(; beg != last; ++beg){
        (*beg)->setMinimumSize(m_LeftFrame->widthMM(), m_LeftFrame->heightMM()/6);
    }
}



void CentralCententFrame::initUi()
{
   std::size_t index{0};
   for(; index != 3; ++index){
       m_Buttons.push_back(new QPushButton{});
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

}


void CentralCententFrame::layoutItem()noexcept
{
    Queue<QPushButton*>::iterator beg = m_Buttons.begin();
    Queue<QPushButton*>::iterator last = m_Buttons.end();

    m_ButtonLayout->setAlignment(Qt::AlignLeft);
    m_ButtonLayout->setSpacing(0);
    m_ButtonLayout->setMargin(0);
    for(; beg != last; ++beg){
        m_ButtonLayout->addWidget(*beg);
    }
    m_ButtonLayout->addStretch(0);

    m_LeftFrame->setLayout(m_ButtonLayout);

    m_MainLayout->addWidget(m_LeftFrame);
    m_MainLayout->addWidget(m_RightFrame);


    this->setLayout(m_MainLayout);
}
