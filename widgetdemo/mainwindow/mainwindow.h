#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <utility>
#include <tuple>
#include <deque>
#include <map>
#include <QQueue>
#include <QFrame>
#include <QPair>




#include "utilities.h"



class QVBoxLayout;
class TitleBar;


class MainWindow : public QFrame
{
    Q_OBJECT

private:

    template<typename... Types>
    using QTuple = std::tuple<Types...>;

    template<typename Type>
    using Queue = std::deque<Type>;

    enum class CursorPosition{
        Up = 0,
        Down,
        Left,
        Right,
        LeftTop,
        LeftBottom,
        RightTop,
        RightBottom,
        None
    };

public:
    MainWindow(std::size_t minimumWidth, std::size_t minimumHeight, QFrame* parent = nullptr);

    virtual ~MainWindow()=default;
    MainWindow(const MainWindow&)=delete;
    MainWindow(MainWindow&&)=delete;

    MainWindow& operator=(const MainWindow&)=delete;
    MainWindow& operator=(MainWindow&&)=delete;


protected:
    virtual void mousePressEvent(QMouseEvent* event)override;
    virtual void mouseMoveEvent(QMouseEvent* event)override;
    virtual void mouseReleaseEvent(QMouseEvent* event)override;



private:
    void checkDragPosition(const QPoint& globalPoint)noexcept;


    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;


private:


    TitleBar* m_TitleBar{nullptr};
    QVBoxLayout* m_MainLayout{nullptr};


    std::size_t m_TheWidth{0};
    std::size_t m_TheHeight{0};
    bool m_IsPressed{false};
    QPoint m_DragPoint{0, 0};

    CursorPosition m_CursorDir{CursorPosition::None};
    constexpr static std::size_t padding{2};
};



#endif // MAINWINDOW_H
