#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QApplication>
#include<QMouseEvent>
#include<QtDebug>
#include"QColorDialog"
#include<QTime>
#include<iostream>
using namespace std;
QImage img(600,600,QImage::Format_RGB888);
static QColor color ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = 0;
    start = true;
}
MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::sign(int k)
{
    if (k<0)
        return (-1);
    else
        return (1);
}

void MainWindow::bl(int x1,int y1,int x2,int y2)
{
    int p,dx,dy;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    int i = 0;
    int x = x1;
    int y = y1;
    if ((dx)>=(dy))
    {
        p = 2*(dy) - dx;
        while (i<=dx)
        {
            img.setPixel(x,y,color.rgb());
            if (p<0)
            {
                p = p + 2*(dy);
            }
            else
            {
                p = p + 2*(dy - dx);
                y = y + sign(y2 - y1);
            }
            x = x + sign(x2 - x1);
            i++;
        }
    }
    else
    {
        p = 2*(dx - dy);
        while (i<=dy)
        {
            img.setPixel(x,y,color.rgb());
        if (p<0)
            p = p + 2*(dx);
        else
        {
            p = p +2*(dx - dy);
            x = x + sign(x2 - x1);
        }
        y = y + sign(y2 - y1);
        i++;

        }

    }

    ui->label->setPixmap(QPixmap::fromImage(img));

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(start)
    {
        int p=event->pos().x();
        int q=event->pos().y();
        a[ver] = p;
        b[ver] = q;

        if( event->button() == Qt::RightButton)
        {
            bl(a[0],b[0],a[ver-1],b[ver-1]);
            start = false;
        }
        else
        {
            if(ver>0)
            {
                bl(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
}




void MainWindow::on_pushButton_clicked()
{
     color = QColorDialog::getColor();
}

void MainWindow::on_pushButton_2_clicked()
{
    int yMin = 600, yMax = 0,temp;
    float slope[100];
    for(int i=0;i<ver;i++)
    {
        if(b[i] > yMax)
            yMax = b[i];
        if(b[i] < yMin)
            yMin = b[i];
    }
    a[ver] = a[0];
    b[ver] = b[0];
    for(int i=0;i<ver;i++)
    {
        float dx = a[i+1] - a[i];
        float dy = b[i+1] - b[i];
        if(dx==0.0)
        {
            slope[i]=0.0;
        }
        if(dy==0.0)
        {
            slope[i]=1.0;
        }
        if(dx != 0.0 && dy != 0.0)
        {
            slope[i] = (float(dx)/float(dy));
        }
     }
        int k;
        for (int j=yMin;j<yMax;j++)
        {
            k = 0;
            for(int i=0;i<ver;i++)
            {
                if(((b[i]<=j) && (b[i+1]>j)) || ((b[i]>j) && (b[i+1]<=j)))
                {
                    x_inc[k] = float(a[i]+slope[i]*(j-b[i]));
                    k++;
                }
            }
            for(int m=0;m<k-1;m++)
            {
                for(int i=0;i<k-m-1;i++)
                {
                    if(x_inc[i]>x_inc[i+1])
                    {
                        temp = x_inc[i];
                        x_inc[i] = x_inc[i+1];
                        x_inc[i+1] = temp;
                    }
                }
            }
            for(int i=0;i<k;i=i+2)
            {
                bl(x_inc[i],j,x_inc[i+1]+1,j);
            }
        }
}

