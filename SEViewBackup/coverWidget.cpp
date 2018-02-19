#include "coverWidget.h"
#include <QPainter>

CoverWidget::CoverWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(WIDTH,HEIGHT);
}

void CoverWidget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawPixmap(0,0,width()-MARGIN,height()-MARGIN,
                      QPixmap(":/SEResources/cover.jpg"));
}
