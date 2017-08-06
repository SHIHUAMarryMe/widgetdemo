

#include <QDebug>
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListView>
#include <QSpacerItem>
#include <QSplitter>
#include <QStackedWidget>
#include <QBoxLayout>

#include "mainwindow.h"
#include "utilities.h"



MainWindow::MainWindow(std::size_t minimumWidth, std::size_t minimumHeight, QFrame *parent)
           :QFrame{parent},
            m_TheWidth{minimumWidth},
            m_TheHeight{minimumHeight}
{
    this->setMinimumSize(minimumWidth, minimumHeight);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setMouseTracking(true);



    this->initResource();
    this->layoutItems();
    this->connectSignalSlot();
    this->setItemsIco();
}


void MainWindow::initResource()
{
    std::size_t index{0};
    m_TopAndBtmFrames = QPair<QFrame*, QFrame*>{new QFrame{}, new QFrame{}};

    m_TopLayouts = std::make_tuple(new QVBoxLayout{},
                                   new QHBoxLayout{},
                                   new QHBoxLayout{});



    index = 0;
    for(; index != 6; ++index){
        m_TopItems.append(new QPushButton{});
    }


    m_CentralStackedWgt = new  QStackedWidget{};

    index = 0;
    for(; index != 3; ++index){
        m_CentralWidgets.append(new QFrame{});
    }


    index = 0;
    for(; index != 3; ++index){
        m_CentralLeftWidgets.append(new QFrame{});
    }

    index = 0;
    for(; index != 3; ++index){

        QQueue<QPushButton*> tempQue;
        for(std::size_t index2 = 0; index2 != 3; ++index2){
            tempQue.append(new QPushButton{});
        }

        m_CentralLeftWigsSubItems.insert(
          std::pair<QVBoxLayout*, QQueue<QPushButton*>>{new QVBoxLayout{}, tempQue}
                                         );
    }

    index = 0;
    for(; index != 9; ++index){
        QQueue<QFrame*> tempQue;
        for(std::size_t internalI = 0; internalI != 3; ++internalI){
            tempQue.append(new QFrame{});
        }
        m_CentralRightWidgets.insert(std::make_pair(new QStackedWidget{}, tempQue));
    }

    index = 0;
    for(; index != 3; ++index){
        m_CentralWigsLayouts.append(new QHBoxLayout{});
    }



    m_MainLayout = new QVBoxLayout{this};
}


void MainWindow::layoutItems()noexcept
{

//    static int number{0};

    std::size_t index{0};

    //set the size of top of frame.
    m_TopAndBtmFrames.first->setMinimumSize(m_TheWidth, (m_TheHeight/10)*2);



    QHBoxLayout* topHLayout1{std::get<1>(m_TopLayouts)};
    topHLayout1->setSpacing(0);
    topHLayout1->setMargin(0);
    topHLayout1->setAlignment(Qt::AlignRight | Qt::AlignTop);
    topHLayout1->addStretch();
    for(; index != 3; ++index){
        m_TopItems[index]->setMinimumSize((m_TheWidth/10)*1/10, (m_TheHeight/10)*2/5*3/5);
        m_TopItems[index]->setFocusPolicy(Qt::NoFocus);
        topHLayout1->addWidget(m_TopItems[index]);
    }


    QHBoxLayout* topHLayout2{std::get<2>(m_TopLayouts)};
    topHLayout2->setSpacing(0);
    topHLayout2->setMargin(0);
    topHLayout2->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    topHLayout2->addStretch();
    index = 3;
    for(; index != 6; ++index){
        m_TopItems[index]->setMinimumSize((m_TheWidth/10)*1, (m_TheHeight/10)*2/5*3);
        m_TopItems[index]->setFocusPolicy(Qt::NoFocus);
        topHLayout2->addWidget(m_TopItems[index]);
    }
    topHLayout2->addStretch();


    QVBoxLayout* topVLayout{std::get<0>(m_TopLayouts)};
    topVLayout->setSpacing(0);
    topVLayout->setMargin(0);
    topVLayout->addLayout(topHLayout1);
    topVLayout->addLayout(topHLayout2);
    m_TopAndBtmFrames.first->setLayout(topVLayout);


    index = 0;
    for(; index != 3; ++index){

        //for test.
        if(index == 0){
            m_CentralWidgets[index]->setStyleSheet(QString{"background-color: red"});
        }

        if(index == 1){
            m_CentralWidgets[index]->setStyleSheet(QString{"background-color: yellow"});
        }

        if(index == 2){
            m_CentralWidgets[index]->setStyleSheet(QString{"background-color: blue"});
        }
        //for test.


        m_CentralStackedWgt->addWidget(m_CentralWidgets[index]);
    }

    index = 0;
    for(; index != 3; ++index){
        m_CentralWidgets[index]->setLayout( m_CentralWigsLayouts[index] );
    }

    index= 0;
    std::map<QStackedWidget*, QQueue<QFrame*>>::iterator beg = m_CentralRightWidgets.begin();
    std::map<QStackedWidget*, QQueue<QFrame*>>::iterator end = m_CentralRightWidgets.end();
    for(; index != 3 && beg != end; ++index,++beg){
        m_CentralWigsLayouts[index]->setSpacing(0);
        m_CentralWigsLayouts[index]->setMargin(0);
        m_CentralWigsLayouts[index]->addWidget(m_CentralLeftWidgets[index]);
        m_CentralWigsLayouts[index]->addWidget(beg->first);
    }



    //left-center.
    index = 0;
    std::map<QVBoxLayout*, QQueue<QPushButton*>>::iterator beg_1 = m_CentralLeftWigsSubItems.begin();
    std::map<QVBoxLayout*, QQueue<QPushButton*>>::iterator end_1 = m_CentralLeftWigsSubItems.end();
    for(;index != 3 && beg_1 != end_1; ++index, ++beg_1){
        m_CentralLeftWidgets[index]->setMinimumSize((m_TheWidth/5)*1, (m_TheHeight/10)*7);
        m_CentralLeftWidgets[index]->setLayout(beg_1->first);
    }


    beg_1 = m_CentralLeftWigsSubItems.begin();
    for(; beg_1 != end_1; ++beg_1){

        QQueue<QPushButton*>::iterator beg_2 = beg_1->second.begin();
        QQueue<QPushButton*>::iterator end_2 = beg_1->second.end();
        for(; beg_2 != end_2; ++beg_2){
            (*beg_2)->setMinimumSize((m_TheWidth/5)*1, (m_TheHeight/10)*7/8);
            (*beg_2)->setFocusPolicy(Qt::NoFocus);
            beg_1->first->addWidget(*beg_2);
        }

        beg_1->first->setSpacing(0);
        beg_1->first->setMargin(0);
        beg_1->first->setAlignment(Qt::AlignTop);
    }


    //right-center
    beg = m_CentralRightWidgets.begin();
    for(; beg != end; ++beg){

        QQueue<QFrame*>::iterator beg_3 = beg->second.begin();
        QQueue<QFrame*>::iterator end_3 = beg->second.end();
        for(; beg_3 != end_3; ++beg_3){
            (*beg_3)->setMinimumSize((m_TheWidth/5)*1, (m_TheHeight/10)*7/8);
            beg->first->addWidget(*beg_3);
        }
    }



    m_CentralStackedWgt->setMinimumSize(m_TheWidth, (m_TheHeight/10)*7);
    m_CentralStackedWgt->setCurrentIndex(0);
    m_TopAndBtmFrames.second->setMinimumSize(m_TheWidth, (m_TheHeight/10)*1);


    m_MainLayout->setSpacing(0);
    m_MainLayout->setMargin(0);
    m_MainLayout->addWidget(m_TopAndBtmFrames.first);
    m_MainLayout->addWidget(m_CentralStackedWgt);
    m_MainLayout->addWidget(m_TopAndBtmFrames.second);


    topHLayout1 = nullptr;
    topHLayout2 = nullptr;
}


void MainWindow::connectSignalSlot()noexcept
{
    std::size_t index{3};
    for(; index != 6; ++index){
        QObject::connect(m_TopItems[index], &QPushButton::clicked,
                         [this, index]{
                         (this->m_CentralStackedWgt)->setCurrentIndex(index-3);
                         });
    }

    std::map<QStackedWidget*, QQueue<QFrame*>>::iterator beg = m_CentralRightWidgets.begin();
    std::map<QStackedWidget*, QQueue<QFrame*>>::iterator end = m_CentralRightWidgets.end();
    std::map<QVBoxLayout*, QQueue<QPushButton*>>::iterator buttons_beg = m_CentralLeftWigsSubItems.begin();
    std::map<QVBoxLayout*, QQueue<QPushButton*>>::iterator buttons_end = m_CentralLeftWigsSubItems.end();
    for(; buttons_beg != buttons_end && beg != end; ++buttons_beg, ++beg){
        std::size_t index2{0};
        for(auto button : buttons_beg->second){
            QObject::connect(button, &QPushButton::clicked,
                             [=]{
                                 beg->first->setCurrentIndex(index);
                                }
                            );

            ++index2;
        }
    }



    //close window event.
    index = 2;
    QObject::connect(m_TopItems[index], &QPushButton::clicked,
                     [this]{this->close();}
                    );

}


void MainWindow::setItemsIco()noexcept
{
    m_TopItems[2]->setIcon(QIcon{":/styles/img/close.ico"});
}


//void MainWindow::checkDragPosition(const QPoint& globalPoint)noexcept
//{


//    LOG("Check drag position=========================");

//    QRect rect{this->rect()};
//    QPoint topLeftPoint{this->mapToGlobal(rect.topLeft())};
//    QPoint bottomRightPoint{this->mapToGlobal(rect.bottomRight())};

//    std::size_t currentX{globalPoint.x()};
//    std::size_t currentY{globalPoint.y()};


//    //左上角.
//    if(topLeftPoint.x() <= currentX && topLeftPoint.x() + MainWindow::padding >= currentX
//            && bottomRightPoint.y() + MainWindow::padding >= currentY && bottomRightPoint.y() <= currentY){

//        LOG("LeftTop=====================");

//        m_CursorDir = CursorPosition::LeftTop;
//        this->setCursor(QCursor(Qt::SizeFDiagCursor));

//        return;

//    //右下角.
//    }else if(bottomRightPoint.x() >= currentX && bottomRightPoint.x() - MainWindow::padding <= currentX
//             && bottomRightPoint.y() >= currentY && bottomRightPoint.y() - MainWindow::padding <= currentY){


//        LOG("RightBottom=======================");
//        m_CursorDir = CursorPosition::RightBottom;
//        this->setCursor(QCursor{Qt::SizeFDiagCursor});

//        return;

//     //左下角
//    }else if(topLeftPoint.x() <= currentX && topLeftPoint.x() + MainWindow::padding >= currentX
//             && bottomRightPoint.y() >= currentY && bottomRightPoint.y() - MainWindow::padding <= currentY){

//        LOG("LeftBottom=========================");
//        m_CursorDir = CursorPosition::LeftBottom;
//        this->setCursor(QCursor(Qt::SizeBDiagCursor));

//        return;
//     //右上角.
//    }else if(topLeftPoint.x() + m_TheWidth >= currentX && topLeftPoint.x() + m_TheWidth - MainWindow::padding <= currentX
//             && topLeftPoint.y() <= currentY && topLeftPoint.y() + MainWindow::padding >= currentY){

//        LOG("RightTop==========================");
//        m_CursorDir = CursorPosition::RightTop;
//        this->setCursor(QCursor(Qt::SizeFDiagCursor));

//        return;

//        //上
//    }else if(topLeftPoint.x() + MainWindow::padding < currentX < topLeftPoint.x() + m_TheWidth - MainWindow::padding
//             && topLeftPoint.y() <= currentY && topLeftPoint.y() + MainWindow::padding >= currentY){

//        LOG("Up================================");
//        m_CursorDir = CursorPosition::Up;
//        this->setCursor(QCursor{Qt::SizeVerCursor});

//        return;

//     //下
//    }else if(bottomRightPoint.x() - m_TheWidth + MainWindow::padding <= currentX && bottomRightPoint.x() - MainWindow::padding >= currentX
//             && bottomRightPoint.y() >= currentY && bottomRightPoint.y() - MainWindow::padding <= currentY){

//        LOG("Down=============================");
//        m_CursorDir = CursorPosition::Down;
//        this->setCursor(QCursor{Qt::SizeVerCursor});

//        return;

//     //左
//    }else if(topLeftPoint.x() <= currentX && topLeftPoint.x() + MainWindow::padding >= currentX
//             && bottomRightPoint.y() - MainWindow::padding > currentY && topLeftPoint.y() + MainWindow::padding <= currentY){

//        LOG("Left============================");
//        m_CursorDir = CursorPosition::Left;
//        this->setCursor(QCursor(Qt::SizeHorCursor));

//        return;

//        //右
//    }else if(bottomRightPoint.x() >= currentX && bottomRightPoint.x() - MainWindow::padding <= currentX
//             && bottomRightPoint.y() - MainWindow::padding > currentY && topLeftPoint.y() + MainWindow::padding <= currentY){

//        LOG("Right==========================");
//        m_CursorDir = CursorPosition::Right;
//        this->setCursor(QCursor(Qt::SizeHorCursor));

//        return;

//     //no direction
//    }else{

//        LOG("No direction==========================");
//        m_CursorDir = CursorPosition::None;
//        this->setCursor(QCursor{Qt::ArrowCursor});
//    }
//}


//void MainWindow::mousePressEvent(QMouseEvent* event)
//{
//    switch(event->button())
//    {
//    case Qt::LeftButton:
//    {
//        event->accept();
//        m_IsPressed = true;

//        LOG("mousePress============");

//        if(m_CursorDir != CursorPosition::None){
//            this->mouseGrabber();

//        }else{
//            LOG("get the dragPoint=============");
//            m_DragPoint = event->globalPos() - this->frameGeometry().topLeft();
//        }

//        break;
//    }
//    case Qt::RightButton:
//    {
//        this->QWidget::mousePressEvent(event);
//        break;
//    }
//    default:
//    {
//        this->QWidget::mousePressEvent(event);
//        break;
//    }
//    }
//}


//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    LOG("mouseMove===========");

//    QPoint globalPoint{event->globalPos()};
//    QRect rect{this->rect()};

//    QPoint tl{this->mapToGlobal(rect.topLeft())};
//    QPoint br{this->mapToGlobal(rect.bottomRight())};

//    if(!m_IsPressed){
//        this->checkDragPosition(globalPoint);

//    }else{

//        LOG("Just move no pressing==========================");

//        if(m_CursorDir != CursorPosition::None){
//            QRect rMove{tl, br};

//            switch(m_CursorDir){
//            case CursorPosition::Left:
//            {
//                if(br.x() - globalPoint.x() <= this->minimumWidth()){
//                    rMove.setX(tl.x());

//                }else{
//                    rMove.setX(globalPoint.x());
//                }
//                break;
//            }
//            case CursorPosition::Right:
//            {
//                rMove.setWidth(globalPoint.x() - tl.x());
//                break;
//            }
//            case CursorPosition::Up:
//            {
//                if(br.y() - globalPoint.y() <= this->minimumHeight()){
//                    rMove.setY(tl.y());

//                }else{
//                    rMove.setY(globalPoint.y());
//                }
//                break;
//            }
//            case CursorPosition::Down:
//            {
//                rMove.setHeight(globalPoint.y() - tl.y());
//                break;
//            }
//            case CursorPosition::LeftTop:
//            {
//                if(br.x() - globalPoint.x() <= this->minimumWidth()){
//                    rMove.setX(tl.x());

//                }else{
//                    rMove.setX(globalPoint.x());
//                }

//                if(br.y() - globalPoint.y() <= this->minimumHeight()){

//                    rMove.setY(tl.y());
//                }else{
//                    rMove.setY(globalPoint.y());
//                }
//                break;
//            }
//            case CursorPosition::RightTop:
//            {
//                rMove.setWidth(globalPoint.x() - tl.x());
//                rMove.setY(globalPoint.y());
//                break;
//            }
//            case CursorPosition::LeftBottom:
//            {
//                rMove.setX(globalPoint.x());
//                rMove.setHeight(globalPoint.y() - tl.y());
//                break;
//            }
//            case CursorPosition::RightBottom:
//            {
//                rMove.setWidth(globalPoint.x() - tl.x());
//                rMove.setHeight(globalPoint.y() - tl.y());
//                break;
//            }
//            default:
//                break;
//            }//end swtich


//            this->setGeometry(rMove);


//        }else{
//            this->move(event->globalPos() - m_DragPoint);
//            event->accept();
//        }
//    }

//    this->QWidget::mouseMoveEvent(event);
//}


//void MainWindow::mouseReleaseEvent(QMouseEvent *event)
//{
//    if(event->button() == Qt::LeftButton) {
//        m_IsPressed = false;
//        if(m_CursorDir!= CursorPosition::None) {
//            this->releaseMouse();
//            this->setCursor(QCursor(Qt::ArrowCursor));
//        }
//    }
//}
