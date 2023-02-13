// Draw a Rectangle on black background
#include <iostream>
#include <GL/glut.h>
using namespace std;
void displayMe(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rectangle");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}