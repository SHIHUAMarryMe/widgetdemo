#ifndef CENTRALFRAME_H
#define CENTRALFRAME_H

#include <QFrame>

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

    void setMinimumSize(const std::size_t& widthMM, const std::size_t& heightMM);

private:
    using QFrame::setMinimumSize;//!!!!!!!!!!!

    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;
private:

    NavigationBar* m_NavigationBar{nullptr};
    Queue<QFrame*> m_WidgetsForStacked{};
    Map<QBoxLayout*, Queue<QFrame*>> m_WidgetsForLayout{};
    QStackedWidget* m_StackWidget{nullptr};
    QVBoxLayout* m_MainLayout{nullptr};
};



#endif // CENTRALFRAME_H
