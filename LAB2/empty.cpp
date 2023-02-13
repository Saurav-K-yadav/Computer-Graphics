// Create a empty window

#include <iostream>
#include <GL/glut.h>
using namespace std;
void displayMe(void)
{
    // glClearColor should be used before glClear
    // glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Black
    // glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//white
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // colored
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Empty screen");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}