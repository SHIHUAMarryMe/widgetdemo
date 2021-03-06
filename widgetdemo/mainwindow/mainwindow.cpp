
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
#include <QToolButton>
#include <QCalendarWidget>
#include <QAbstractButton>
#include <QMenu>


#include "mainwindow.h"
#include "utilities.h"
#include "../titlebar/titlebar.h"


MainWindow::MainWindow(std::size_t minimumWidth, std::size_t minimumHeight, QFrame *parent)
           :QFrame{parent},
            m_TitleBar{new TitleBar{0 , 0}},
            m_TheWidth{minimumWidth},
            m_TheHeight{minimumHeight}
{
    this->setMinimumSize(minimumWidth, minimumHeight);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setMouseTracking(true);
}


void MainWindow::initUi()
{
    //
}

void MainWindow::initUiPara()noexcept
{
    m_TitleBar->setMinimumSize(m_TheWidth/15, m_TheHeight/20);
}


void MainWindow::layoutItem()noexcept
{
    m_MainLayout->addWidget(m_TitleBar);

    this->setLayout(m_MainLayout);
}



void MainWindow::checkDragPosition(const QPoint& globalPoint)noexcept
{


    LOG("Check drag position=========================");

    QRect rect{this->rect()};
    QPoint topLeftPoint{this->mapToGlobal(rect.topLeft())};
    QPoint bottomRightPoint{this->mapToGlobal(rect.bottomRight())};

    std::size_t currentX{globalPoint.x()};
    std::size_t currentY{globalPoint.y()};


    //左上角.
    if(topLeftPoint.x() <= currentX && topLeftPoint.x() + MainWindow::padding >= currentX
            && bottomRightPoint.y() + MainWindow::padding >= currentY && bottomRightPoint.y() <= currentY){

        LOG("LeftTop=====================");

        m_CursorDir = CursorPosition::LeftTop;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));

        return;

    //右下角.
    }else if(bottomRightPoint.x() >= currentX && bottomRightPoint.x() - MainWindow::padding <= currentX
             && bottomRightPoint.y() >= currentY && bottomRightPoint.y() - MainWindow::padding <= currentY){


        LOG("RightBottom=======================");
        m_CursorDir = CursorPosition::RightBottom;
        this->setCursor(QCursor{Qt::SizeFDiagCursor});

        return;

     //左下角
    }else if(topLeftPoint.x() <= currentX && topLeftPoint.x() + MainWindow::padding >= currentX
             && bottomRightPoint.y() >= currentY && bottomRightPoint.y() - MainWindow::padding <= currentY){

        LOG("LeftBottom=========================");
        m_CursorDir = CursorPosition::LeftBottom;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));

        return;
     //右上角.
    }else if(topLeftPoint.x() + m_TheWidth >= currentX && topLeftPoint.x() + m_TheWidth - MainWindow::padding <= currentX
             && topLeftPoint.y() <= currentY && topLeftPoint.y() + MainWindow::padding >= currentY){

        LOG("RightTop==========================");
        m_CursorDir = CursorPosition::RightTop;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));

        return;

        //上
    }else if(topLeftPoint.x() + MainWindow::padding < currentX < topLeftPoint.x() + m_TheWidth - MainWindow::padding
             && topLeftPoint.y() <= currentY && topLeftPoint.y() + MainWindow::padding >= currentY){

        LOG("Up================================");
        m_CursorDir = CursorPosition::Up;
        this->setCursor(QCursor{Qt::SizeVerCursor});

        return;

     //下
    }else if(bottomRightPoint.x() - m_TheWidth + MainWindow::padding <= currentX && bottomRightPoint.x() - MainWindow::padding >= currentX
             && bottomRightPoint.y() >= currentY && bottomRightPoint.y() - MainWindow::padding <= currentY){

        LOG("Down=============================");
        m_CursorDir = CursorPosition::Down;
        this->setCursor(QCursor{Qt::SizeVerCursor});

        return;

     //左
    }else if(topLeftPoint.x() <= currentX && topLeftPoint.x() + MainWindow::padding >= currentX
             && bottomRightPoint.y() - MainWindow::padding > currentY && topLeftPoint.y() + MainWindow::padding <= currentY){

        LOG("Left============================");
        m_CursorDir = CursorPosition::Left;
        this->setCursor(QCursor(Qt::SizeHorCursor));

        return;

        //右
    }else if(bottomRightPoint.x() >= currentX && bottomRightPoint.x() - MainWindow::padding <= currentX
             && bottomRightPoint.y() - MainWindow::padding > currentY && topLeftPoint.y() + MainWindow::padding <= currentY){

        LOG("Right==========================");
        m_CursorDir = CursorPosition::Right;
        this->setCursor(QCursor(Qt::SizeHorCursor));

        return;

     //no direction
    }else{

        LOG("No direction==========================");
        m_CursorDir = CursorPosition::None;
        this->setCursor(QCursor{Qt::ArrowCursor});
    }
}


void MainWindow::mousePressEvent(QMouseEvent* event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
    {
        event->accept();
        m_IsPressed = true;

        LOG("mousePress============");

        if(m_CursorDir != CursorPosition::None){
            this->mouseGrabber();

        }else{
            LOG("get the dragPoint=============");
            m_DragPoint = event->globalPos() - this->frameGeometry().topLeft();
        }

        break;
    }
    case Qt::RightButton:
    {
        this->QWidget::mousePressEvent(event);
        break;
    }
    default:
    {
        this->QWidget::mousePressEvent(event);
        break;
    }
    }
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    LOG("mouseMove===========");

    QPoint globalPoint{event->globalPos()};
    QRect rect{this->rect()};

    QPoint tl{this->mapToGlobal(rect.topLeft())};
    QPoint br{this->mapToGlobal(rect.bottomRight())};

    if(!m_IsPressed){
        this->checkDragPosition(globalPoint);

    }else{

        LOG("Just move no pressing==========================");

        if(m_CursorDir != CursorPosition::None){
            QRect rMove{tl, br};

            switch(m_CursorDir){
            case CursorPosition::Left:
            {
                if(br.x() - globalPoint.x() <= this->minimumWidth()){
                    rMove.setX(tl.x());

                }else{
                    rMove.setX(globalPoint.x());
                }
                break;
            }
            case CursorPosition::Right:
            {
                rMove.setWidth(globalPoint.x() - tl.x());
                break;
            }
            case CursorPosition::Up:
            {
                if(br.y() - globalPoint.y() <= this->minimumHeight()){
                    rMove.setY(tl.y());

                }else{
                    rMove.setY(globalPoint.y());
                }
                break;
            }
            case CursorPosition::Down:
            {
                rMove.setHeight(globalPoint.y() - tl.y());
                break;
            }
            case CursorPosition::LeftTop:
            {
                if(br.x() - globalPoint.x() <= this->minimumWidth()){
                    rMove.setX(tl.x());

                }else{
                    rMove.setX(globalPoint.x());
                }

                if(br.y() - globalPoint.y() <= this->minimumHeight()){

                    rMove.setY(tl.y());
                }else{
                    rMove.setY(globalPoint.y());
                }
                break;
            }
            case CursorPosition::RightTop:
            {
                rMove.setWidth(globalPoint.x() - tl.x());
                rMove.setY(globalPoint.y());
                break;
            }
            case CursorPosition::LeftBottom:
            {
                rMove.setX(globalPoint.x());
                rMove.setHeight(globalPoint.y() - tl.y());
                break;
            }
            case CursorPosition::RightBottom:
            {
                rMove.setWidth(globalPoint.x() - tl.x());
                rMove.setHeight(globalPoint.y() - tl.y());
                break;
            }
            default:
                break;
            }//end swtich


            this->setGeometry(rMove);


        }else{
            this->move(event->globalPos() - m_DragPoint);
            event->accept();
        }
    }

    this->QWidget::mouseMoveEvent(event);
}


void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        m_IsPressed = false;
        if(m_CursorDir!= CursorPosition::None) {
            this->releaseMouse();
            this->setCursor(QCursor(Qt::ArrowCursor));
        }
    }
}
