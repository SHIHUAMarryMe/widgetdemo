#ifndef CENTRALCONTENTFRAME_H
#define CENTRALCONTENTFRAME_H



#include <QFrame>


#include "utilities.h"


class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QStackedWidget;


class CentralCententFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CentralCententFrame(QFrame* parent = nullptr);
    CentralCententFrame(const CentralCententFrame&)=delete;
    CentralCententFrame& operator=(const CentralCententFrame&)=delete;


    void setMinimumSize(const std::size_t& widthMM, const std::size_t& heightMM)noexcept;

signals:
    void currentButtonIndex(std::size_t index);


private slots:
    void onCurrentButtonIndexChanged(std::size_t index)noexcept;

private:
    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;

    void initConnect()noexcept;

private:
    QFrame* m_LeftFrame{nullptr};
    Queue<QPushButton*> m_Buttons{};


//    QFrame* m_RightFrame{nullptr};
    QStackedWidget* m_RightFrame{nullptr};
    Queue<QFrame*> m_WidgetForStack{};

    QVBoxLayout* m_ButtonLayout{nullptr};
    QHBoxLayout* m_MainLayout{nullptr};
};





#endif // CENTRALCONTENTFRAME_H
