#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <type_traits>
#include <utility>

#include <QFrame>
#include <QQueue>
#include <QObject>

#include "utilities.h"

class QHBoxLayout;
class QPushButton;
class QLabel;
class QIcon;
class QToolButton;



class TitleBar : public QFrame
{
    Q_OBJECT

public:


    explicit TitleBar(const std::size_t& width, const std::size_t& height, QFrame *parent = nullptr);
    virtual ~TitleBar() = default;

    TitleBar(const TitleBar&)=delete;
    TitleBar& operator=(const TitleBar&)=delete;


    void setTitle(const QString& str)noexcept;
private:
    void initUi();
    void setUiPara()noexcept;
    void layoutItem()noexcept;


private:
    Pair<QLabel*, QLabel*> m_Labels{};
    Queue<QToolButton*> m_Buttons{};

    QHBoxLayout* m_MainLayout{nullptr};
};



#endif // TITLEBAR_H
