#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H


#include <QFrame>
#include <QQueue>

#include "utilities.h"


class NavigationBar : public QFrame
{
    Q_OBJECT

public:
    explicit NavigationBar(QFrame* parent = nullptr);
    virtual ~NavigationBar()=default;

    NavigationBar(const NavigationBar&)=delete;
    NavigationBar& operator=(const NavigationBar&)=delete;


private:
    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;


private:
    QQueue<QPushButton*> m_NavigationBtns{};
    QHBoxLayout* m_MainLayout{nullptr};
};



#endif // NAVIGATIONBAR_H
