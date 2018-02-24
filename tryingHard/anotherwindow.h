#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class anotherWindow;
}

class anotherWindow : public QWidget
{
    Q_OBJECT

public:
    explicit anotherWindow(QWidget *parent = 0);
    ~anotherWindow();

signals:
    void sizeChanged();
protected:
    virtual void resizeEvent(QResizeEvent*);

private:
    void paintEvent(QPaintEvent *event = 0);
    //void mousePressEvent(QMouseEvent* event);
    //void mouseMoveEvent(QMouseEvent* event);
    Ui::anotherWindow *ui;


};

#endif // ANOTHERWINDOW_H
