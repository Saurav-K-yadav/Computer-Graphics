
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

void BresenhamCircle(int r=10000)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawPixel(x, y);
    while (x <= y)
    {
        if (d <= 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
        drawPixel(x, y);
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
    glutInitWindowSize(5000, 5000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glutDisplayFunc(myinit);
    glutMainLoop();
    return 0;
}