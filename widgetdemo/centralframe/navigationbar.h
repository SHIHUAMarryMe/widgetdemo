#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H


#include <QFrame>
#include <QList>

#include "utilities.h"


class QHBoxLayout;
class QToolButton;
class QPushButton;

class NavigationBar : public QFrame
{
    Q_OBJECT

public:
    explicit NavigationBar(QFrame* parent = nullptr);
    virtual ~NavigationBar()=default;

    NavigationBar(const NavigationBar&)=delete;
    NavigationBar& operator=(const NavigationBar&)=delete;

    void setFixedSize(const std::size_t& widthFixed, const std::size_t& heightFixed)noexcept;

signals:
    void onStackWidgetIndexChanged(std::size_t index);

private:
    using QFrame::setFixedSize;

    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;
    void initConnect()noexcept;

    void setItemObjectName()noexcept;

private:
    Queue<QPushButton*> m_NavigationBtns{};
    QHBoxLayout* m_MainLayout{nullptr};
};


#endif // NAVIGATIONBAR_H
