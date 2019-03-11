#include<windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include<stdlib.h>



void triangle()
{
    glBegin(GL_POLYGON);
    glVertex2i(210,450);
    glVertex2i(200,300);
    glVertex2i(300,200);
    glVertex2i(100,200);
    glEnd();

    }

void text()
{
    glColor3i(0,0,1);
    char menu[100];
    strcpy(menu,"PRASANNA");
    int len;
    len=strlen(menu);
    glRasterPos2i(145,255);
    for (int i=0;i<len;i++)
    {

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,menu[i]);

    }




}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    triangle();
    text();
    glFlush();
}

void init(void)
{
	glClearColor(0,0,0,0);
	gluOrtho2D(-160,600,-160,600);
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

