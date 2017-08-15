#ifndef STATUSBAR_H
#define STATUSBAR_H


#include <QFrame>


class StatusBar : public QFrame
{
    Q_OBJECT

public:
    explicit StatusBar(QFrame* parent = nullptr);
    virtual ~StatusBar()=default;

    StatusBar(const StatusBar&)=delete;
    StatusBar& operator=(const StatusBar&)=delete;
};

#endif // STATUSBAR_H
