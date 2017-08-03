

#include <QDebug>


#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "mainwindow.h"
#include "utilities.h"



MainWindow::MainWindow(std::size_t minimumWidth, std::size_t minimumHeight, QWidget *parent)
           :QWidget{parent},
            m_TheWidth{minimumWidth},
            m_TheHeight{minimumHeight}
{
    this->setMinimumSize(minimumWidth, minimumHeight);
    this->setMouseTracking(true);


    this->initResource();
    this->layoutItems();

}


void MainWindow::initResource()
{
    std::size_t index{0};
    for(; index != 6; ++index){
        m_Widgets.append(new QWidget{});
    }

    index = 0;
    for(; index != 3; ++index){
        m_HLayouts.append(new QHBoxLayout{});
    }


    index = 0;
    for(; index != 6; ++index){
        m_Buttons.append(new QPushButton{});
    }

    m_Widgets[0]->setMinimumSize(m_TheWidth, (m_TheHeight/8)*1);
    m_Widgets[1]->setMinimumSize(m_TheWidth, (m_TheHeight/8)*6);
    m_Widgets[2]->setMinimumSize(m_TheWidth, (m_TheHeight/8)*1);
    m_Widgets[3]->setMinimumSize(m_TheWidth/4, (m_TheHeight/8)*6);
    m_Widgets[4]->setMinimumSize((m_TheWidth/4)*3, (m_TheHeight/8)*6);



    m_TotalLayout = new QVBoxLayout{this};
}


void MainWindow::layoutItems()noexcept
{

    m_HLayouts[0]->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
    m_HLayouts[0]->setSizeConstraint(QLayout::SetMinimumSize);
    std::size_t index{0};
    for(; index != 3; ++index){
        m_Buttons[index]->setMaximumSize(m_TheWidth/7, ((m_TheHeight/7)*2)/3);
        m_HLayouts[0]->addWidget(m_Buttons[index]);
    }
    m_Widgets[0]->setLayout(m_HLayouts[0]);


    m_TotalLayout->addWidget(m_Widgets[0]);
    m_TotalLayout->addWidget(m_Widgets[1]);
    m_TotalLayout->addWidget(m_Widgets[2]);

    this->setLayout(m_TotalLayout);
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
