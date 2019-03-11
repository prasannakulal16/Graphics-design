#include<windows.h>
#include <GL/glut.h>
#include<GL/glu.h>

void init()
{
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D (0.0,640.0,0.0,480.0);
 }
void circleMidPoint()
{
int xCenter = 300 ;
int yCenter = 200;
int radius = 100;

    int x = 0;
    int y = radius;
    int p = 1 - radius;

     while(x<y)  {
         x++;
         if(p < 0)
              p += 2*x + 1;
         else {
              y--;
              p += 2 * (x - y) + 1;
         }
     glBegin(GL_POINTS);
         glVertex2i(xCenter + x, yCenter + y);
         glVertex2i(xCenter - x, yCenter + y);
         glVertex2i(xCenter + x, yCenter - y);
         glVertex2i(xCenter - x, yCenter - y);
         glVertex2i(xCenter + y, yCenter + x);
         glVertex2i(xCenter - y, yCenter + x);
         glVertex2i(xCenter + y, yCenter - x);
         glVertex2i(xCenter - y, yCenter - x);
     glEnd();
     }
     glBegin(GL_POINTS);
         glVertex2i(xCenter,yCenter);
     glEnd();
}
void display()
{

     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0,1.0,0);
     glPointSize(3.0);

     circleMidPoint();
     glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
	init();
    glutDisplayFunc(display);
    glutMainLoop();
}
