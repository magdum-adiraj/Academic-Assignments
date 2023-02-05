#include "clip.h"
#include "ui_clip.h"
#include<QApplication>
#include<QMouseEvent>
#include<QtDebug>
#include"QColorDialog"
#include<QTime>
#include<iostream>
using namespace std;
QImage img(500,500,QImage::Format_RGB888);
QImage img1(500,500,QImage::Format_RGB888);
clip::clip(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::clip)
{
    ui->setupUi(this);
    ver = 0;
    accept = true;
}

clip::~clip()
{
    delete ui;
}


int clip::sign(int k)
{
    if (k<0)
        return (-1);
    else
        return (1);
}

void clip::bl(int x1,int y1,int x2,int y2,int choice)
{

    int p,dx,dy;
    dx = abs(x1 - x2);
    dy = abs(y2 - y1);
    int i = 0;
    int x = x1;
    int y = y1;
    if ((dx)>=(dy))
    {
        p = 2*(dy) - dx;
        while (i<dx)
        {
            if (choice == 1)
                {

                    img.setPixel(x,y,qRgb(0, 255, 0));
                }
            else if (choice == 2)
                {
                    img1.setPixel(x,y,qRgb(0, 255, 0));
                }
            else
                {
                    img.setPixel(x,y,qRgb(0, 255, 0));
                    img1.setPixel(x,y,qRgb(0, 255, 0));
                }

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
            if (choice == 1)
            {
                img.setPixel(x,y,qRgb(0, 255, 0));
            }
            else if (choice == 2)
            {
                img1.setPixel(x,y,qRgb(0, 255, 0));
            }
            else
            {
                img.setPixel(x,y,qRgb(0, 255, 0));
                img1.setPixel(x,y,qRgb(0, 255, 0));
            }

        if (p<0)
            p = p + 2*(dx);
        else
        {
            p = p +2*(dx - dy);
            x = x + sign(x2 - x1);
        }
        y = y + sign(y2 - y1 );
        i++;

        }

    }

    ui->label->setPixmap(QPixmap::fromImage(img));

}

int clip::computecode(double x,double y)
{
    int code = INSIDE;
    if(x < Xmin)
    {
        code |= LEFT;
    }
    else if (x > Xmax)
    {
        code |= RIGHT;
    }
    if(y < Ymin)
    {
        code |= TOP;
    }
    else if(y > Ymax)
    {
        code |= BOTTOM;
    }
    return code;
}

void clip::clipping(int x1,int y1,int x2,int y2)
{
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    int code1 = computecode(x1,y1);
    int code2 = computecode(x2,y2);

    bool accept = false;

    while(true)
    {
        if((code1 == 0) && (code2==0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x,y;
            if(code1 != 0)
            {
                code_out = code1;
            }
            else
            {
                code_out = code2;
            }
            if(code_out & BOTTOM)
            {
                x = x1 + (x2-x1)*(Ymax-y1)/(y2 - y1);
                y = Ymax;
            }
            else if(code_out & TOP)
            {
                x = x1 + (x2-x1)*(Ymin-y1)/(y2-y1);
                y = Ymin;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2-y1)*(Xmax-x1)/(x2-x1);
                x=Xmax;
            }
            else if (code_out & LEFT)
            {

                y = y1 + (y2-y1)*(Xmin-x1)/(x2-x1);
                x = Xmin;
            }
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 =computecode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computecode(x2, y2);
            }
        }

    }
    if(accept)
    {
        bl(x1,y1,x2,y2,2);
    }

}

void clip::mousePressEvent(QMouseEvent *event)
{
    if(accept)
    {
        int p=event->pos().x();
        int q=event->pos().y();
        a[ver] = p;
        b[ver] = q;

        if( event->button() == Qt::RightButton)
        {
            accept = false;
        }
        else
        {
            a[ver]=p;
            b[ver]=q;
            if (ver>0 && ver % 2==1)
            {
                bl(a[ver], b[ver], a[ver-1], b[ver-1],1);
            }
        }
        ver++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}



void clip::on_pushButton_clicked()
{
    Xmin = ui->textEdit->toPlainText().toInt();
    Ymin = ui->textEdit_2->toPlainText().toInt();
    Xmax = ui->textEdit_3->toPlainText().toInt();
    Ymax = ui->textEdit_4->toPlainText().toInt();
    bl(Xmin, Ymin, Xmax, Ymin, 3);
    bl(Xmax, Ymin, Xmax, Ymax, 3);
    bl(Xmax, Ymax, Xmin, Ymax, 3);
    bl(Xmin, Ymax, Xmin, Ymin, 3);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label_6->setPixmap(QPixmap::fromImage(img1));

}


void clip::on_pushButton_2_clicked()
{
    for (int i=0;i<=(ver-1)/2;i++)
    {

        int x1, y1, x2, y2;
        x1 = a[2*i];
        y1 = b[2*i];
        x2 = a[2*i+1];
        y2 = b[2*i+1];
        computecode(x1, y1);
        computecode(x2, y2);

        clipping(x1, y1, x2, y2);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label_6->setPixmap(QPixmap::fromImage(img1));
    }
}
