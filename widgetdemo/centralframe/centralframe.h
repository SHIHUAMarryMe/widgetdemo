#ifndef CENTRALFRAME_H
#define CENTRALFRAME_H

#include <QFrame>
#include <QQueue>
#include <QBoxLayout>

#include "utilities.h"

class QStackWidget;

class CentralWidget : public QFrame
{
    Q_OBJECT

public:
    explicit CentralWidget(QFrame* parent = nullptr);
    virtual ~CentralWidget()=default;

    CentralWidget(const CentralWidget&)=delete;
    CentralWidget& operator=(const CentralWidget&)=delete;

private:
    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;

private:


    QStackWidget* m_StackWidget{nullptr};
    QBoxLayout* m_MainLayout{nullptr};
};



#endif // CENTRALFRAME_H
