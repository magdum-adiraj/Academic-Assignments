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
    void bl(int,int,int,int);
    int sign(int m);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);

private:
    Ui::MainWindow *ui;
    int a[20],b[20],ver,temp;
    bool start;
    float slope_inverse[20],x_inc[20];
};
#endif // MAINWINDOW_H
