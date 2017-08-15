
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QBoxLayout>

#include "centralframe.h"
#include "navigationbar.h"
#include "centralcontentframe.h"

CentralFrame::CentralFrame(QFrame *parent)
             :QFrame{parent},
              m_NavigationBar{new NavigationBar{}},
              m_StackWidget{new QStackedWidget{}},
              m_MainLayout{new QVBoxLayout{}}
{
    this->initUi();
    this->initUiPara();
    this->layoutItem();
    this->initConnect();
}


void CentralFrame::initUi()
{

    std::size_t index{0};
    for(; index != 4; ++index){
        m_WidgetsForStacked.push_back(new QFrame{});
    }




    index = 0;
    for(; index != 4; ++index){
        auto pair = m_WidgetsForLayout.insert(
                                    Pair<QBoxLayout*, Queue<QFrame*>>{new QBoxLayout{QBoxLayout::Direction::LeftToRight}, Queue<QFrame*>{}}
                                             );

        if(!pair.second){
            LOG("=======================");
            throw std::runtime_error{"Insert error!"};
        }
    }

    auto beg = m_WidgetsForLayout.begin();
    auto end = m_WidgetsForLayout.end();
    beg->second.push_back(new CentralCententFrame{});
    ++beg;
    for(; beg != end; ++beg){
        beg->second.push_back(new QFrame{});
    }

}


void CentralFrame::initUiPara()noexcept
{


}


void CentralFrame::layoutItem()noexcept
{
    Map<QBoxLayout*, Queue<QFrame*>>::iterator beg = m_WidgetsForLayout.begin();
    Map<QBoxLayout*, Queue<QFrame*>>::iterator end = m_WidgetsForLayout.end();

    std::size_t index{0};
    for(; beg != end; ++beg, ++index){

        Queue<QFrame*>::iterator beg_1 = beg->second.begin();
        Queue<QFrame*>::iterator end_1 = beg->second.end();

        for(; beg_1 != end_1; ++beg_1){
            beg->first->setSpacing(0);
            beg->first->setMargin(0);
            beg->first->addWidget(*beg_1);
        }

        m_WidgetsForStacked[index]->setLayout(beg->first);
        m_StackWidget->addWidget(m_WidgetsForStacked[index]);
    }


    m_MainLayout->setSpacing(0);
    m_MainLayout->setMargin(0);
    m_MainLayout->addWidget(m_NavigationBar);
    m_MainLayout->addWidget(m_StackWidget);

    this->setLayout(m_MainLayout);
}


void CentralFrame::setMinimumSize(const std::size_t &widthMM, const std::size_t &heightMM)
{
    this->QFrame::setMinimumSize(widthMM, heightMM);

    m_NavigationBar->setMinimumSize(widthMM, heightMM/5*1);
    m_StackWidget->setMinimumSize(widthMM, heightMM/5*4);

    auto beg = m_WidgetsForLayout.begin();
    auto beg_1 = beg->second.begin();

    if(CentralCententFrame* frame = dynamic_cast<CentralCententFrame*>(*beg_1)){
        frame->setMinimumSize(widthMM, heightMM/5*4);
    }else{
        LOG("==========================");
        throw std::bad_cast{};
    }

}

void CentralFrame::initConnect()noexcept
{
    QObject::connect(m_NavigationBar, &NavigationBar::onStackWidgetIndexChanged,
                     [this](std::size_t index)
                     {
                        m_StackWidget->setCurrentIndex(index);
                     }

                     );
}
