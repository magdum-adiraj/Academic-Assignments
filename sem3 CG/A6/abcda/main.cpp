#define GLUT_DISABLE_ATEXIT_HACK
#include<windows.h>
#include <GL\glut.h>
#include<iostream>
#include<string.h>
using namespace std;


int cnt=0;
void error1()
{ for(int i=0;i<3;i++)
{
glBegin(GL_LINES);
glColor3f(1.0,0.0,0.0);
glVertex2f(240+i*75, 260);
glVertex2f(270+i*75, 290);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,0.0,0.0);
glVertex2f(240+i*75, 290);
glVertex2f(270+i*75, 260);
glEnd();
}
}
void error2()
{ for(int i=0;i<3;i++)
{
glBegin(GL_LINES);
glColor3f(1.0,0.0,0.0);
glVertex2f(240+i*75, 180);
glVertex2f(270+i*75, 210);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,0.0,0.0);
glVertex2f(240+i*75, 210);
glVertex2f(270+i*75, 180);
glEnd();
}
}
void output(char *s,int len,float x)
{
glColor3f(1.0,0.0,0.0 );
glRasterPos2f(x, 230.0);
int i=0;
while(i<len)
{
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s);
*s++;
i++;
}
}
void init(void)
{
//set Background color last value alpha=1 opaque range 0 to 1
glClearColor(0,0,0,1); //1=opaque, 0=transparent
glLineWidth(10.0f);
}
//specify object
void display()
{
//clear Frame Buffer
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
if(cnt>0)
{
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex2f(10, 10);
glVertex2f(10, 80);
glVertex2f(120, 80);
glVertex2f(120, 10);
glEnd();
}

if(cnt>1)
{
glBegin(GL_POLYGON);
glColor3f(0.0,1.0,1.0);
glVertex2f(10,95);
glVertex2f(10, 165);
glVertex2f(120, 165);
glVertex2f(120, 95);
glEnd();
}
if(cnt>2 )
{
glBegin(GL_POLYGON);
glColor3f(0.0,1.0,0.0);
glVertex2f(10,175);
glVertex2f(10, 255);
glVertex2f(120, 255);
glVertex2f(120, 175);
glEnd();
}
if(cnt>3 )
{
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);
glVertex2f(10,265);
glVertex2f(10, 345);
glVertex2f(120, 345);
glVertex2f(120, 265);
glEnd();

}
if(cnt>4 )
{
glBegin(GL_POLYGON);
glColor3f(1.0,0.0,1.0);
glVertex2f(10,355);
glVertex2f(10, 435);
glVertex2f(120, 435);
glVertex2f(120, 355);
glEnd();

}

if(cnt>5)
{
error1();
char s[]="Stack Overflow!!";
output(s,16,270.0);
error2();
}
if(cnt<=0)
{ char s[]="Stack Empty!!";
if(cnt<0)
{
error1();
output(s,13,280.0);
error2();

}

else
{
output(s,13,280.0);
}


}

glFlush();
}


void reshape(int w,int h)
{
//use whole window
glViewport(0,0,w,h);
//projection
glMatrixMode(GL_PROJECTION);
//clear projection matrix
glLoadIdentity();
gluOrtho2D(0,500,0,500);
glMatrixMode(GL_MODELVIEW);
}

void specialKeys( int key, int x, int y ) {

if (key == GLUT_KEY_UP)

{ cnt++;
if (cnt<=5 and cnt>0)
cout<<"\nElement no. "<<cnt<<" pushed on the stack."<<endl;
if(cnt==5)
cout<<"\nStack Limit reached!"<<endl;
if(cnt<0)
cnt=1;
}
if (key == GLUT_KEY_DOWN)
{
if (cnt>=5)
cnt=5;
if(cnt<=5 && cnt>0)
cout<<"\nElement no. "<<cnt<<" popped from the stack."<<endl;
if(cnt==1)
cout<<"\nLast Element Popped!"<<endl;
cnt--;

}

// Request display update
glutPostRedisplay();

}
int main(int argc, char** argv)
{
//Initialize communication between windown and application
glutInit(&argc, argv); //Initialise glut library

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0, 0);
glutInitWindowSize(700,700);
glutCreateWindow("Stack");
glutDisplayFunc(display);
glutSpecialFunc(specialKeys);
glutReshapeFunc(reshape);

init();
glutMainLoop();
return 0;
}
