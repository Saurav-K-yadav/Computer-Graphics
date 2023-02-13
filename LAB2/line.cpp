// Draw green colored line

#include <iostream>
#include <GL/glut.h>
using namespace std;
void displayMe(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // glPointSize(10); // Width
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Green Line");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}