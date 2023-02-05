#ifndef CLIP_H
#define CLIP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class clip; }
QT_END_NAMESPACE

class clip : public QMainWindow
{
    Q_OBJECT

public:
    clip(QWidget *parent = nullptr);
    ~clip();

private slots:
    void bl(int,int,int,int,int);
    void clipping(int,int,int,int);
    int sign(int);
    int computecode(double,double);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::clip *ui;
    bool accept;
    int Xmin,Ymin,Xmax,Ymax;
    int a[10],b[10];
    int ver;
    const int INSIDE = 0;
    const int LEFT = 1;
    const int RIGHT = 2;
    const int BOTTOM = 4;
    const int TOP = 8;
};
#endif // CLIP_H
