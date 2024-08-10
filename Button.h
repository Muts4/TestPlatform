#ifndef BUTTON_H
#define BUTTON_H

#include <QAbstractButton>
#include <QPainter>
#include <QStyleOptionButton>

class MyButton : public QAbstractButton
{
    Q_OBJECT

public:
    explicit MyButton(QWidget *parent = nullptr);

protected:

    void paintEvent(QPaintEvent *event) override;

    QSize sizeHint() const override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

};


#endif // BUTTON_H
