#ifndef MAINWINDOW_H
#define MAINWINDOW_H





#include <QQueue>
#include <QFrame>
#include <QPair>


class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QLabel;
class QPoint;
class QMouseEvent;
class QListView;
class QSplitter;
class QStackedWidget;
class QBoxLayout;



class MainWindow : public QFrame
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
    MainWindow(std::size_t minimumWidth, std::size_t minimumHeight, QFrame* parent = nullptr);

    virtual ~MainWindow()=default;
    MainWindow(const MainWindow&)=delete;
    MainWindow(MainWindow&&)=delete;

    MainWindow& operator=(const MainWindow&)=delete;
    MainWindow& operator=(MainWindow&&)=delete;


protected:
//    virtual void mousePressEvent(QMouseEvent* event)override;
//    virtual void mouseMoveEvent(QMouseEvent* event)override;
//    virtual void mouseReleaseEvent(QMouseEvent* event)override;


private:

    void connectSignalSlot()noexcept;

    void initResource();// new may be throw.
    void layoutItems()noexcept;

//    void checkDragPosition(const QPoint& globalPoint)noexcept;


    QQueue<QPushButton*> m_Buttons{};
    QQueue<QHBoxLayout*> m_HLayouts{};
    QQueue<QFrame*> m_Widgets{};


    QVBoxLayout* m_LeftVLayout{nullptr};
    QVBoxLayout* m_TotalLayout{nullptr};


    QStackedWidget* m_StackedWidget{nullptr};


    QFrame* m_LeftWidget{nullptr};
    QFrame* m_BottomWidget{nullptr};


    QQueue<QLabel*> m_StakedWigContent{};



    std::size_t m_TheWidth{0};
    std::size_t m_TheHeight{0};
//    bool m_IsPressed{false};
//    QPoint m_DragPoint{0, 0};

    CursorPosition m_CursorDir{CursorPosition::None};
//    constexpr static std::size_t padding{2};
};

#endif // MAINWINDOW_H
