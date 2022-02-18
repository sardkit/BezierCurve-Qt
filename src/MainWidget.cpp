#include "MainWidget.h"

#include <QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet("background-color:white;");

    this->init();
}

void Widget::init()
{
    qDebug() << "Widget::init starts...";

    //Add point: you can add any number points here.
	m_pointsInput << BeizierCurve::Point(20, 10, 0);
    m_pointsInput << BeizierCurve::Point(600, 400, 0);
    m_pointsInput << BeizierCurve::Point(700, 40, 0);

    BeizierCurve berzier(m_pointsInput);
    berzier.Calculate(21);	//parameter means how many points will in output vector
    m_pointsOutput = berzier.GetOutputPoints();
    for(BeizierCurve::Point p : m_pointsOutput) {
        qDebug() << "point location: " << p.x << p.y;
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.save();
    QPen mypen1(Qt::red);
    mypen1.setWidth(5);
    painter.setPen(mypen1);
    for(BeizierCurve::Point p : m_pointsOutput) {
        painter.drawPoint(p.x, p.y);
    }
    painter.restore();

    QPen mypen2(Qt::blue);
    mypen2.setWidth(3);
    painter.setPen(mypen2);
    for(int i = 1; i < m_pointsInput.length(); i++) {
        painter.drawLine(m_pointsInput[i-1].x, m_pointsInput[i-1].y, m_pointsInput[i].x, m_pointsInput[i].y);
    }

    this->update();
}


