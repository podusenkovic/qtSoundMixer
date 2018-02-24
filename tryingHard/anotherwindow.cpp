#include "anotherwindow.h"
#include "ui_anotherwindow.h"

extern int DOTS;

extern QPoint **sins;
extern QPoint *sinsSum;

extern int yDelta;
extern int xWidth;


anotherWindow::anotherWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::anotherWindow)
{
    ui->setupUi(this);
}

anotherWindow::~anotherWindow()
{
    delete ui;
}

//-----------------------------------------------------------------
//--------------Функция прорисовки синусов на 2ом окне-------------
//-----------------------------------------------------------------
void anotherWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    for (int i = 0; i <= DOTS; i++)
    {
        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
        painter.drawPoint(sinsSum[i].x(), sinsSum[i].y() + yDelta);

        painter.setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::FlatCap));
        painter.drawPoint(sins[0][i].x(), sins[0][i].y() + yDelta);

        painter.setPen(QPen(Qt::yellow, 3, Qt::SolidLine, Qt::FlatCap));
        painter.drawPoint(sins[1][i].x(), sins[1][i].y() + yDelta);

        painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::FlatCap));
        painter.drawPoint(sins[2][i].x(), sins[2][i].y() + yDelta);

        painter.setPen(QPen(Qt::green, 3, Qt::SolidLine, Qt::FlatCap));
        painter.drawPoint(sins[3][i].x(), sins[3][i].y() + yDelta);

    }
}
//-----------------------------------------------------------------
//-----------------Событие изменения размепра второго окна---------
void anotherWindow::resizeEvent(QResizeEvent * event){
    yDelta = this->rect().height() / 2;
    DOTS = this->rect().width() * 3200 / 444;
    emit sizeChanged();
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
/*void anotherWindow::mousePressEvent(QMouseEvent* event){
    QPoint pos = event->pos();

    painter.setPen(QPen(Qt::cyan, 10, Qt::SolidLine, Qt::FlatCap));
    painter.drawPoint(pos);
}

//void anotherWindow::mouseMoveEvent(QMouseEvent* event){

}*/

