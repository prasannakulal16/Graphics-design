#include<windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include<math.h>

void ano(int x,int y,int r)
{
    float f;
    glBegin(GL_POLYGON);
    for( int angle = 0; angle < 360; angle ++ ){
        f=angle*3.142/180;
       glVertex2f( x+r*cos(f),y+r*sin(f));}
    glEnd();


}
void expression(int x,int y,int r,int l,int t)
{

    float m;
    glBegin(GL_POLYGON);
    for( int angle = l; angle < t; angle ++ ){
        m=angle*3.142/180;
       glVertex2f( x+r*cos(m),y+r*sin(m));}
     glEnd();

}

void display()
{

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,1,0);
  ano(150,250,130);
  glColor3f(1,0,0);
  ano(450,250,130);
  glColor3f(0,0,1);
  ano(100,270,35);
  ano(200,270,35);
  glColor3f(0,1,0);
  ano(400,270,35);
  ano(500,270,35);
  glColor3f(0,1,1);
  expression(150,165,50,0,180);
  expression(450,200,50,180,360);
  glFlush();


}

void init(void)
{
	glClearColor(0,0,0,0);
	gluOrtho2D(0,600,0,600);
        glMatrixMode(GL_MODELVIEW);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

}
int main()
{
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("gasket");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

