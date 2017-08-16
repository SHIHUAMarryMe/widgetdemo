#ifndef CENTRALCONTENTFRAME_H
#define CENTRALCONTENTFRAME_H



#include <QFrame>


#include "utilities.h"


class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QStackedWidget;


class CentralContentFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CentralContentFrame(QFrame* parent = nullptr);
    CentralContentFrame(const CentralContentFrame&)=delete;
    CentralContentFrame& operator=(const CentralContentFrame&)=delete;


    void setFixedSize(const std::size_t& widthFixed, const std::size_t& heightFixed)noexcept;

signals:
    void currentButtonIndex(std::size_t index);


private slots:
    void onCurrentButtonIndexChanged(std::size_t index)noexcept;

private:
    void initUi();
    void initUiPara()noexcept;
    void layoutItem()noexcept;
    void initConnect()noexcept;

    void setItemObjectName()noexcept;

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
