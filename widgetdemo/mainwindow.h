#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <new>
#include <memory>
#include <ctime>



#include <QWidget>



class QPoint;
class QMouseEvent;



class MainWindow : public QWidget
{
    Q_OBJECT

private:
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
    MainWindow(QWidget* parent = nullptr);

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


    std::size_t m_TheWidth{0};
    std::size_t m_TheHeight{0};
    bool m_IsPressed{false};
    QPoint m_DragPoint{0, 0};

    CursorPosition m_CursorDir{CursorPosition::None};
    constexpr static std::size_t padding{2};
};

#endif // MAINWINDOW_H
