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

#include "listmodel.h"
#include "utilities.h"
#include "itemdelegate.h"



class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QLabel;
class QPoint;
class QMouseEvent;
class QListView;
class QSplitter;
class QStackedWidget;
class QStackedLayout;
class QBoxLayout;
class QToolButton;
class Calculator;
class QAbstractButton;
class QMenu;



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
//    virtual void mousePressEvent(QMouseEvent* event)override;
//    virtual void mouseMoveEvent(QMouseEvent* event)override;
//    virtual void mouseReleaseEvent(QMouseEvent* event)override;


signals:
    void currentSelectedButtonMenubar(std::size_t index);
    void currentSelectedButtonLeftCentral(std::size_t index, std::size_t index2);



private slots:
    void changeButtonCheckStateMenuBar(std::size_t index)noexcept;
    void changeButtonCheckStateLeftCentral(std::size_t index, std::size_t index2)noexcept;
    void changeSkin(QAction* action)noexcept;


private:
    void initResource();
    void layoutItems();
    void connectSignalSlot();


    void initListViewModel();

    void setObjectsName()noexcept;
    void setWidgetContent()noexcept;
    void setItemsIcon()noexcept;


//    void checkDragPosition(const QPoint& globalPoint)noexcept;



    QPair<QFrame*, QFrame*> m_TopAndBtmFrames{};
    QTuple<QVBoxLayout*, QHBoxLayout*, QHBoxLayout*> m_TopLayouts{};
    QQueue<QAbstractButton*> m_TopItems{};
    QQueue<QAction*> m_Actions{};
    QMenu* m_SkinsMenu{nullptr};


    QStackedWidget* m_CentralStackedWgt{nullptr};
    QQueue<QFrame*> m_CentralWidgets{};
    QQueue<QHBoxLayout*> m_CentralWigsLayouts{};
    QQueue<QFrame*> m_CentralLeftWidgets{};
    std::map<QVBoxLayout*, QQueue<QPushButton*>> m_CentralLeftWigsSubItems{};
    std::map<QStackedWidget*, QQueue<QFrame*>> m_CentralRightWidgets{};
    std::map<QBoxLayout*, Queue<QWidget*>> m_CentralRightSubWigs{};

    QVBoxLayout* m_MainLayout{nullptr};

    std::unique_ptr<ListModel> m_ListModel{nullptr};
    std::unique_ptr<PixmapItemDelegate> m_ItemDelegate{nullptr};


    std::size_t m_TheWidth{0};
    std::size_t m_TheHeight{0};
    bool m_IsPressed{false};
    QPoint m_DragPoint{0, 0};

    CursorPosition m_CursorDir{CursorPosition::None};
    constexpr static std::size_t padding{2};
    static QString stylesNames[2];
};

#endif // MAINWINDOW_H
