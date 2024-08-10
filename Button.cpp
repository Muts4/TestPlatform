#include "Button.h"

MyButton::MyButton(QWidget *parent)
    : QAbstractButton(parent)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void MyButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    QStyleOptionButton option;

    option.initFrom(this);

    if (isDown())
    {
        option.state |= QStyle::State_Sunken;
    }

    style()->drawControl(QStyle::CE_PushButton, &option, &painter, this);

    painter.drawText(rect(), Qt::AlignCenter, text());
}

QSize MyButton::sizeHint() const
{
    return QSize(100,30);
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    QAbstractButton::mousePressEvent(event);
    update();
}

void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    QAbstractButton::mouseReleaseEvent(event);
    update();
}
