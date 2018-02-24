#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <anotherwindow.h>
#include <QPainter>
#include <QApplication>
#include <QEvent>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //-----------------------z----------------------------
    //---------------------------------------------------
    void updateSins(int num); // обновление массива синусов

    void updateSum();         // обновление суммы синусов

    void bigUpdate(int n);    // предыдущие две в одной
    //---------------------------------------------------
    //---------------------------------------------------
    //bool eventFilter(QObject *target, QEvent *event);
private slots:

    void updateAll();
    //---------------------------------------------------
    //----------Слоты управления амплитудами-------------
    //---------------------------------------------------
    void on_verticalSlider_actionTriggered(int action);

    void on_verticalSlider_2_actionTriggered(int action);

    void on_verticalSlider_3_actionTriggered(int action);

    void on_verticalSlider_4_actionTriggered(int action);
    //---------------------------------------------------
    //----------Слоты для выбора синусоиды---------------
    //---------------------------------------------------
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();
    //---------------------------------------------------
    //---------------------------------------------------

    //-----------Кнопка сброса на нач значения-----------
    void on_pushButton_clicked();

    //-----------Кнопка выхода из программы--------------
    void on_pushButton_2_clicked();

    //---------------------------------------------------
    //---------------------------------------------------

    //-----------Слайдер для смещения--------------------
    void on_horizontalSlider_actionTriggered(int action);

    //-----------Слайдер для коэф------------------------
    void on_horizontalSlider_2_actionTriggered(int action);

    //---------------------------------------------------
    //---------------------------------------------------

protected:
   virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;

    anotherWindow *sWindow;
};

#endif // MAINWINDOW_H
