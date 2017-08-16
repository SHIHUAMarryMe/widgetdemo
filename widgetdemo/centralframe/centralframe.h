#ifndef CENTRALFRAME_H
#define CENTRALFRAME_H

#include <QFrame>
#include <QList>

#include "utilities.h"

class QStackedWidget;
class NavigationBar;
class QVBoxLayout;
class QBoxLayout;

class CentralFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CentralFrame(QFrame* parent = nullptr);
    virtual ~CentralFrame()=default;

    CentralFrame(const CentralFrame&)=delete;
    CentralFrame& operator=(const CentralFrame&)=delete;

    void setFixedSize(const std::size_t& widthFixed, const std::size_t& heightFixed);
//    void setTheMinimumSize(const std::size_t& widthMM, const std::size_t& heightMM)noexcept;

private:
    using QFrame::setFixedSize;//notice that!

    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;
    void initConnect()noexcept;
    void setItemObjectName()noexcept;
private:

    NavigationBar* m_NavigationBar{nullptr};
    Queue<QFrame*> m_WidgetsForStacked{};
    Map<QBoxLayout*, Queue<QFrame*>> m_WidgetsForLayout{};
    QStackedWidget* m_StackWidget{nullptr};
    QVBoxLayout* m_MainLayout{nullptr};
};



#endif // CENTRALFRAME_H
