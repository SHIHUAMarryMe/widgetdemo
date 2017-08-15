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
class QLabel;


class TitleBar : public QFrame
{
    Q_OBJECT

public:


    explicit TitleBar(QFrame *parent = nullptr);
    virtual ~TitleBar() = default;

    TitleBar(const TitleBar&)=delete;
    TitleBar& operator=(const TitleBar&)=delete;


    void setMinimumSize(const std::size_t& widthMM, const std::size_t& heightMM)noexcept;
    void setTitle(const QString& str)noexcept;
    void setLogo(const QString& url)noexcept;

signals:
    void onClicked(std::size_t index);

private:
    using QFrame::setMinimumSize;

    void initUi();
    void setUiPara()noexcept;
    void layoutItem()noexcept;
    void initConnect()noexcept;

    void setItemObjectName()noexcept;//for qss.

private:
    Pair<QLabel*, QLabel*> m_Labels{};
    Queue<QToolButton*> m_Buttons{};
    QHBoxLayout* m_MainLayout{nullptr};
};



#endif // TITLEBAR_H
