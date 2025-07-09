#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(600,600,QImage::Format_RGB888);
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
     int level;
     level=ui->textEdit->toPlainText().toInt();
     int x1=100,x5=400,y1=280,y5=280;
     snowflake(level,x1,y1,x5,y5);
     ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::dda(int x1,int y1, int x2, int y2){
    float dx = x2 -x1;
    float dy = y2 - y1;
    float steps;
    if(abs(dx) > abs(dy))
    {
         steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    float xinc = dx/steps;
    float yinc = dy/steps;
    float x = x1;
    float y = y1;

    for(int i = 0; i < steps; i++)
    {
        img.setPixel(x,y,qRgb(255,0,0));
        x += xinc;
        y += yinc;
    }
}
void MainWindow::snowflake(int order,int x1,int y1, int x5,int y5)
{
    int delX,delY,x2,y2,x3,y3,x4,y4;
    if(order==1)
        dda(x1,y1,x5,y5);
    else
    {
        delX=x5-x1;
        delY=y5-y1;
        x2=x1+delX/3;
        y2=y1+delY/3;
        x3=int((x1+x5)/2+(sqrt(3.0)/6)*(y1-y5));
        y3=int((y1+y5)/2+(sqrt(3.0)/6)*(x5-x1));
        x4=x1+delX*2/3;
        y4=y1+delY*2/3;

        snowflake(order-1,x1,y1,x2,y2);
        snowflake(order-1,x2,y2,x3,y3);
        snowflake(order-1,x3,y3,x4,y4);
        snowflake(order-1,x4,y4,x5,y5);
    }
}
