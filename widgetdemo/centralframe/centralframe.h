#ifndef CENTRALFRAME_H
#define CENTRALFRAME_H

#include <QFrame>
#include <QQueue>
#include <QBoxLayout>

#include "utilities.h"

class QStackWidget;
class NavigationBar;

class CentralFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CentralFrame(QFrame* parent = nullptr);
    virtual ~CentralFrame()=default;

    CentralFrame(const CentralFrame&)=delete;
    CentralFrame& operator=(const CentralFrame&)=delete;

    void setMinimumSize(const std::size_t& widthMM, const std::size_t& heightMM)noexcept;

private:
//    using QFrame::setMinimumSize;//!!!!!!!!!!!

    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;

private:

    NavigationBar* m_NavigationBar{nullptr};
    Queue<QFrame*> m_WidgetsForStacked{};
    Map<QBoxLayout*, Queue<QFrame*>> m_WidgetsForLayout{};
    QStackWidget* m_StackWidget{nullptr};
    QVBoxLayout* m_MainLayout{nullptr};
};



#endif // CENTRALFRAME_H
