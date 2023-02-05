#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int xc,yc,r,r1,d,x,y;
        xc=ui->textEdit->toPlainText().toInt();
        yc=ui->textEdit_2->toPlainText().toInt();
        r=ui->textEdit_3->toPlainText().toInt();
        x = 0;
        y = r;
        d = 3 - 2*r;
        while(x<=y)
        {
            img.setPixel(y + xc,x+ yc,qRgb(255,255,255));
            img.setPixel(x + xc,y+ yc,qRgb(255,255,255));
            img.setPixel(-x + xc,y+ yc,qRgb(255,255,255));
            img.setPixel(-y + xc,x+ yc,qRgb(255,255,255));
            img.setPixel(-y + xc,-x+ yc,qRgb(255,255,255));
            img.setPixel(-x + xc,-y+ yc,qRgb(255,255,255));
            img.setPixel(x + xc,-y+ yc,qRgb(255,255,255));
            img.setPixel(y + xc,-x+ yc,qRgb(255,255,255));
            if (d<0)
                d = d + 4*x + 6;
            else
            {
                d = d + 4*(x-y) + 10;
                y = y- 1;
            }
            x = x + 1;
        }
        r1=r*0.5;
        x = 0;
        y = r1;
        d = 3 - 2*r1;
        while(x<=y)
        {
            img.setPixel(y + xc,x+ yc,qRgb(255,255,255));
            img.setPixel(x + xc,y+ yc,qRgb(255,255,255));
            img.setPixel(-x + xc,y+ yc,qRgb(255,255,255));
            img.setPixel(-y + xc,x+ yc,qRgb(255,255,255));
            img.setPixel(-y + xc,-x+ yc,qRgb(255,255,255));
            img.setPixel(-x + xc,-y+ yc,qRgb(255,255,255));
            img.setPixel(x + xc,-y+ yc,qRgb(255,255,255));
            img.setPixel(y + xc,-x+ yc,qRgb(255,255,255));
            if (d<0)
                d = d + 4*x + 6;
            else
            {
                d = d + 4*(x-y) + 10;
                y = y- 1;
            }
            x = x + 1;
        }
        ui->label_4->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()
{
    float xc,yc,r,x1,x2,y1,y2,dx,dy,step,x_in,y_in;
    xc=ui->textEdit->toPlainText().toInt();
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();
    x1=xc+0.866*r;
    x2=xc;
    y1=yc+0.5*r;
    y2=yc-r;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
        step=abs(dx);
    else
        step=abs(dy);
    x_in=dx/step;
    y_in=dy/step;
    img.setPixel(x1,y1,qRgb(255,255,255));
    for(int i=0;i<step;i++) {
        x1+=x_in;
        y1+=y_in;
        img.setPixel(x1,y1,qRgb(255,255,255));
        }
    x2=xc-0.866*r;
    y2=yc+0.5*r;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
        step=abs(dx);
    else
        step=abs(dy);
    x_in=dx/step;
    y_in=dy/step;
    img.setPixel(x1,y1,qRgb(255,255,255));
    for(int i=0;i<step;i++) {
        x1+=x_in;
        y1+=y_in;
        img.setPixel(x1,y1,qRgb(255,255,255));
        }
    x1=xc+0.866*r;
    y1=yc+0.5*r;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
        step=abs(dx);
    else
        step=abs(dy);
    x_in=dx/step;
    y_in=dy/step;
    img.setPixel(x1,y1,qRgb(255,255,255));
    for(int i=0;i<step;i++) {
        x1+=x_in;
        y1+=y_in;
        img.setPixel(x1,y1,qRgb(255,255,255));
        }
    ui->label_4->setPixmap(QPixmap::fromImage(img));
}

