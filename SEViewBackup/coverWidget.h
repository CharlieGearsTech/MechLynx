#ifndef COVERWIDGET_H
#define COVERWIDGET_H

#include <QWidget>

#define HEIGHT 500
#define WIDTH 375
#define MARGIN 25

class CoverWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CoverWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent* );
};

#endif // COVERWIDGET_H
