#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "BeizierCurve.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    void init();

    void paintEvent(QPaintEvent *event) override;

private:
    QVector<BeizierCurve::Point> m_pointsInput;
    QVector<BeizierCurve::Point> m_pointsOutput;
};
#endif // WIDGET_H
