#ifndef CENTRALFRAME_H
#define CENTRALFRAME_H

#include <QFrame>
#include <QQueue>

#include "utilities.h"



class QVBoxLayout;


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

    QVBoxLayout* m_MainLayout{nullptr};
};



#endif // CENTRALFRAME_H
