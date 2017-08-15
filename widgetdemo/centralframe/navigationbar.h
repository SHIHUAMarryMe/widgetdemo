#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H


#include <QFrame>

#include "utilities.h"


class QHBoxLayout;
class QToolButton;

class NavigationBar : public QFrame
{
    Q_OBJECT

public:
    explicit NavigationBar(QFrame* parent = nullptr);
    virtual ~NavigationBar()=default;

    NavigationBar(const NavigationBar&)=delete;
    NavigationBar& operator=(const NavigationBar&)=delete;

    void setMinimumSize(const std::size_t& widthMM, const std::size_t& heightMM)noexcept;


signals:
    void onStackWidgetIndexChanged(std::size_t index);

private:
    using QFrame::setMinimumSize;

    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;
    void initConnect()noexcept;


private:
    Queue<QToolButton*> m_NavigationBtns{};
    QHBoxLayout* m_MainLayout{nullptr};
};


#endif // NAVIGATIONBAR_H
