// Create a point of given width

#include <iostream>
#include <GL/glut.h>
using namespace std;
void displayMe(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10); // Width
    glColor3f(0.2, 0.9, 0.7);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Point");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}