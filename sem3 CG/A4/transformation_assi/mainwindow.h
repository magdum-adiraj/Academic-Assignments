#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void dda(float x1, float y1, float x2, float y2,int c);
    void Multiplication(float P[][3], float T[][3],float res[][3]);
    void mousePressEvent(QMouseEvent *ev);


private:
    Ui::MainWindow *ui;
    float x1,y1,x2,y2,tx,ty,sx,sy,x,c;
    float a[20],b[20];
    int ver;
    bool start;
};
#endif // MAINWINDOW_H
