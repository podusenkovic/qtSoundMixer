#define PI 3.1415
#include "mainwindow.h"
#include "ui_mainwindow.h"

int DOTS = 3200;

QPoint **sins = new QPoint*[4];
QPoint *sinsSum = new QPoint[DOTS*4];

double ampl[] = {0, 0, 0, 0};     // массив амплитуд
double deltas[] = {0, 0, 0, 0};   // массив смещений
double koef[] = {1, 1, 1, 1};     // массив коэффициентов для х
int deltasData[] = {0, 0, 0, 0};  // массив значений слайдера смещений
int koefData[] = {1, 1, 1, 1};    // массив значений слайдера коэф

int yDelta = 180;
//int xWidth = 1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 4; i++)
        sins[i] = new QPoint[DOTS*4];

    this->setWindowTitle("NE QT, A CUTE");
    this->move(250,100);

    //----------------Добавление второго окна------------
    sWindow = new anotherWindow();
    sWindow->setWindowTitle("TYPA OKNO");
    sWindow->show();
    sWindow->move(530, 150);
    //---------Соединение сигнала изменения размера окна и------
    //----------увеличения количества рабочих точек синусов-----
    connect(sWindow, SIGNAL(sizeChanged()), this, SLOT(updateAll()));

}

MainWindow::~MainWindow()
{
    delete[] sinsSum;
    for (int i = 0; i < 4; i++)
        delete[] sins[i];
    delete[] sins;
    delete ui;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
void MainWindow::on_verticalSlider_actionTriggered(int action)
{
    int data = ui->verticalSlider->value();
    ampl[0] = data * 1.0 / 5;
    this->bigUpdate(0);

    ui->lcdNumber->display(data);
    if (sWindow!=NULL)
        sWindow->update();

}
//-----------------------------------------------------------------
void MainWindow::on_verticalSlider_2_actionTriggered(int action)
{
    int data = ui->verticalSlider_2->value();
    ampl[1] = data * 1.0 / 5;
    this->bigUpdate(1);

    ui->lcdNumber_2->display(data);
    if (sWindow!=NULL)
        sWindow->update();
}
//-----------------------------------------------------------------
void MainWindow::on_verticalSlider_3_actionTriggered(int action)
{
    int data = ui->verticalSlider_3->value();
    ampl[2] = data * 1.0/5;
    this->bigUpdate(2);

    ui->lcdNumber_3->display(data);
    if (sWindow!=NULL)
        sWindow->update();
}
//-----------------------------------------------------------------
void MainWindow::on_verticalSlider_4_actionTriggered(int action)
{
    int data = ui->verticalSlider_4->value();
    ampl[3] = data * 1.0 / 5;
    this->bigUpdate(3);

    ui->lcdNumber_4->display(data);
    if (sWindow!=NULL)
        sWindow->update();}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
void MainWindow::on_radioButton_clicked()
{
    ui->horizontalSlider->setValue(deltasData[0]);
    ui->horizontalSlider_2->setValue(koefData[0]);
}
//-----------------------------------------------------------------

void MainWindow::on_radioButton_2_clicked()
{
    ui->horizontalSlider->setValue(deltasData[1]);
    ui->horizontalSlider_2->setValue(koefData[1]);
}
//-----------------------------------------------------------------

void MainWindow::on_radioButton_3_clicked()
{
    ui->horizontalSlider->setValue(deltasData[2]);
    ui->horizontalSlider_2->setValue(koefData[2]);
}
//-----------------------------------------------------------------

void MainWindow::on_radioButton_4_clicked()
{
    ui->horizontalSlider->setValue(deltasData[3]);
    ui->horizontalSlider_2->setValue(koefData[3]);
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < 4; i++){
        ampl[i] = 0;
        deltas[i] = 0;
        koef[i] = 1;
        deltasData[i] = 0;
        koefData[i] = 1;
    }

    ui->radioButton->setChecked(true);

    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    ui->lcdNumber_3->display(0);
    ui->lcdNumber_4->display(0);

    ui->verticalSlider->setValue(0);
    ui->verticalSlider_2->setValue(0);
    ui->verticalSlider_3->setValue(0);
    ui->verticalSlider_4->setValue(0);

    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider_2->setValue(1);

    for (int i = 0; i < 4; i++)
        this->bigUpdate(i);

    sWindow->update();
}
//-----------------------------------------------------------------
void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    if (sWindow!=NULL)
        sWindow->close();
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    int data = ui->horizontalSlider->value();

    if (ui->radioButton->isChecked())
    {
        deltas[0] = -data * 2*PI / 100;
        deltasData[0] = data;
        this->bigUpdate(0);
    }
    else if (ui->radioButton_2->isChecked())
    {
        deltas[1] = -data * 2*PI / 100;
        deltasData[1] = data;
        this->bigUpdate(1);
    }
    else if (ui->radioButton_3->isChecked())
    {
        deltas[2] = -data * 2*PI / 100;
        deltasData[2] = data;
        this->bigUpdate(2);
    }
    else if (ui->radioButton_4->isChecked())
    {
        deltas[3] = -data * 2*PI / 100;
        deltasData[3] = data;
        this->bigUpdate(3);
    }
    sWindow->update();
}
//-----------------------------------------------------------------
void MainWindow::on_horizontalSlider_2_actionTriggered(int action)
{
    double data = ui->horizontalSlider_2->value();
    if (ui->radioButton->isChecked())
    {
        if (data <= 0.1)
            koef[0] = 1 / (abs(data) + 1);
        else koef[0] = data;
        koefData[0] = data;
        this->bigUpdate(0);
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (data <= 0.1)
            koef[1] = 1 / (abs(data) + 1);
        else koef[1] = data;
        koefData[1] = data;
        this->bigUpdate(1);
    }
    else if (ui->radioButton_3->isChecked())
    {
        if (data <= 0.1)
            koef[2] = 1 / (abs(data) + 1);
        else koef[2] = data;
        koefData[2] = data;
        this->bigUpdate(2);
    }
    else if (ui->radioButton_4->isChecked())
    {
        if (data <= 0.1)
            koef[3] = 1 / (abs(data) + 1);
        else koef[3] = data;
        koefData[3] = data;
        this->bigUpdate(3);
    }
    sWindow->update();
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MainWindow::updateSins(int num){
    double x = 0;
    double y;
    for (int i = 0; i <= DOTS; i++)
    {
        y = ampl[num] * sin(x / (2 * koef[num]) + deltas[num]);
        sins[num][i] = QPoint(x*10,y*10);
        x += PI/200;
    }
}
//-----------------------------------------------------------------
void MainWindow::updateSum(){
    double x = 0;
    for (int j = 0; j <= DOTS; j++)
    {
        sinsSum[j] = QPoint(x * 10,0);
        for (int i = 0; i < 4; i++){
            sinsSum[j].setY(sinsSum[j].y() + sins[i][j].y());
        }
        x += PI/200;
    }
}
//-----------------------------------------------------------------
void MainWindow::bigUpdate(int n){
    this->updateSins(n);
    this->updateSum();
}

void MainWindow::updateAll(){
    for (int i = 0; i < 4; i++)
        this->bigUpdate(i);
    sWindow->update();
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space)
        QApplication::beep();
    if(event->key() == Qt::Key_A)
    {

    }
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
