#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<QMessageBox>
#include<math.h>
#include<QMouseEvent>
using namespace std;

QImage img(600,600,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dda(-300,0,300,0,1);
    dda(0,-300,0,300,1);
    start = true;
    ver = 0;
}
MainWindow::~MainWindow()
{
    delete ui;
}
class Matrix
{
    public:
        float a[2][3];
        float b[3][3];
        Matrix operator *(Matrix ob)
        {
            Matrix temp;
            for(int i=0; i<2; i++)
            {
                for (int j=0; j<3; j++)
                {
                    temp.a[i][j] = 0;
                    for (int k=0; k<3; k++)
                    {
                        temp.a[i][j] += a[i][k] * ob.b[k][j];
                    }
                }
            }
            return temp;
        }
};
void MainWindow::on_pushButton_clicked()
{// to transform object
        tx = ui->textEdit->toPlainText().toFloat();
        ty = ui->textEdit_2->toPlainText().toFloat();
        int i;
        for(i=0; i<ver; i++)
        {
            //dda(a[i],b[i],a[i+1],b[i+1],0);
            Matrix M,N,ans;
            float P[2][3] = {{a[i],b[i],1},{a[i+1],b[i+1],1}};
            float T[3][3] = {{1,0,0},{0,1,0},{tx,-ty,1}};
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<3;j++)
                {
                    M.a[i][j] = P[i][j];
                }
            }
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    N.b[i][j] = T[i][j];
                }
            }
            ans = M * N;
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1],1);
            a[i]=ans.a[0][0];
            b[i]=ans.a[0][1];
            if(i==ver-1)
            {
                dda(a[i],b[i],a[0],b[0],1);
                a[i+1]=a[0];
                b[i+1]=b[0];
            }

        }

}
void MainWindow::on_pushButton_2_clicked()
{// to scale object
        sx = ui->textEdit_3->toPlainText().toFloat();
        sy = ui->textEdit_4->toPlainText().toFloat();

        for(int i=0; i<ver; i++)
        {
            //dda(a[i],b[i],a[i+1],b[i+1],0);
            Matrix M,N,ans;
            float P[2][3] = {{a[i],b[i],1},{a[i+1],b[i+1],1}};
            float S[3][3] = {{sx,0,0},{0,sy,0},{0,0,1}};
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<3;j++)
                {
                    M.a[i][j] = P[i][j];
                }
            }
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    N.b[i][j] = S[i][j];
                }
            }
            ans = M * N;
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1],1);
            a[i]=ans.a[0][0];
            b[i]=ans.a[0][1];
            if(i==ver-1)
            {
                dda(a[i],b[i],a[0],b[0],1);
                a[i+1]=a[0];
                b[i+1]=b[0];
            }
        }
}
void MainWindow::on_pushButton_3_clicked()
{// to rotate object
        x = ui->textEdit_5->toPlainText().toFloat();
        x *= 3.142/180;

        for(int i=0; i<ver; i++)
        {
            //dda(a[i],b[i],a[i+1],b[i+1],0);
            Matrix M,N,ans;
            float P[2][3] = {{a[i],b[i],1},{a[i+1],b[i+1],1}};
            float R[3][3] = {{cos(x),(-sin(x)),0},{sin(x),cos(x),0},{0,0,1}};
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<3;j++)
                {
                    M.a[i][j] = P[i][j];
                }
            }
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    N.b[i][j] = R[i][j];
                }
            }
            ans = M * N;
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1],1);
            a[i]=ans.a[0][0];
            b[i]=ans.a[0][1];
            if(i==ver-1)
            {
                dda(a[i],b[i],a[0],b[0],1);
                a[i+1]=a[0];
                b[i+1]=b[0];
            }
        }
}
void MainWindow::dda(float x1, float y1, float x2, float y2,int c)
{
        x1 += 300;
        y1 += 300;
        x2 += 300;
        y2 += 300;

        float dx,dy,length,x,y;
        dx=x2-x1;
        dy=y2-y1;

        if(abs(dx)>abs(dy))
        {
            length=abs(dx);
        }
        else
        {
            length=abs(dy);
        }
        dx=dx/length;
        dy=dy/length;
        x=x1;
        y=y1;
        int i=0;
        if(c==1){
            img.setPixel(x,y,qRgb(255,255,255));
        }
        else if (c==0 && x!=300 && y!=300)
        {
            img.setPixel(x,y,qRgb(0,0,0));
        }
        while(i<length)
        {
            x=x+dx;
            y=y+dy;
            if(c==1){
            img.setPixel(x,y,qRgb(255,255,255));}
            else if(c==0){
                img.setPixel(x,y,qRgb(0,0,0));
            }
            i++;
        }
        ui->label_6->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::Multiplication(float P[][3], float T[][3], float res[][3])
{
    for(int i=0; i<2; i++)
        {
            for (int j=0; j<3; j++)
            {
                res[i][j] = 0;
                for (int k=0; k<3; k++)
                {
                    res[i][j] += P[i][k] * T[k][j];
                }
            }
    }
}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (start)
        {
          int p = ev->pos().x();
          int q = ev->pos().y();
          a[ver] = p-300;
          b[ver] = q-300;

          if(ev-> button() == Qt::RightButton)
          {
               dda(a[0],b[0],a[ver-1],b[ver-1],1);
               start = false;
          }
          else
          {
                if (ver>0)
                {
                    dda(a[ver], b[ver], a[ver-1],b[ver-1],1);
                }
           }
           ver++;
        }
        a[ver] = a[0];
        b[ver] = b[0];
}
