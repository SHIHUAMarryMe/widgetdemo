#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>

//! [0]
class Button : public QToolButton
{
    Q_OBJECT

public:
    explicit Button(const QString &text, QWidget *parent = 0);

    QSize sizeHint() const Q_DECL_OVERRIDE;
};
//! [0]


#endif // BUTTON_H
