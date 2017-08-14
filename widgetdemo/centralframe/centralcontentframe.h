#ifndef CENTRALCONTENTFRAME_H
#define CENTRALCONTENTFRAME_H



#include <QFrame>
#include <QQueue>


class QPushButton;
class QVBoxLayout;
class QHBoxLayout;


class CentralCententFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CentralCententFrame(QFrame* parent);
    CentralCententFrame(const CentralCententFrame&)=delete;
    CentralCententFrame& operator=(const CentralCententFrame&)=delete;


private:
    void initUi();
    void initUiPara()noexcept;
    void layoutItem();

private:
    QFrame* m_LeftFrame{nullptr};
    QQueue<QPushButton*> m_Buttons{};
    QFrame* m_RightFrame{nullptr};

};





#endif // CENTRALCONTENTFRAME_H
