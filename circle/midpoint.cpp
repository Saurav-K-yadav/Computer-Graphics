
#include <iostream>
#include <GL/glut.h>
using namespace std;
void drawPixel(int x, int y)
{
    glVertex2i(x, y);
    glVertex2i(y, x);
    glVertex2i(-x, y);
    glVertex2i(-y, x);
    glVertex2i(-x, -y);
    glVertex2i(-y, -x);
    glVertex2i(x, -y);
    glVertex2i(y, -x);
}

void BresenhamCircle(int r = 9)
{
    int x = 0, y = r;
    int d = 1 - r;
    while (x <= y)
    {
        drawPixel(x, y);
        if (d < 0)
        {
            x++;
            d = d + 2 * x + 3;
        }
        else
        {
            x++;
            y--;
            d = d + (2 * (x - y)) + 5;
        }
    }
}

void displayMe(void)
{
    BresenhamCircle();
    glFlush();
}

void myinit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    BresenhamCircle(10);
    glEnd();
    glFlush();
    // glClearColor(1.0, 0.0, 1.0, 0);
    // glColor3f(0.0, 0.0, 0.0);
    // gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");
    glClearColor(0.5, 0.5, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

    glutDisplayFunc(myinit);
    glutMainLoop();
    return 0;
}