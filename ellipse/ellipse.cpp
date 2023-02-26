
#include <iostream>
#include <GL/glut.h>
using namespace std;
void drawPixel(int x, int y)
{
    glVertex2i(x, y);
    glVertex2i(-x, y);
    glVertex2i(-x, -y);
    glVertex2i(x, -y);
}

void BresenhamCircle(int b = 3, int a = 4)
{
    int x = 0;
    int y = b;
    float d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    float dx = 2 * b * b * x;
    float dy = 2 * a * a * y;

    while (dx < dy)
    {
        drawPixel(x, y);
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * b * b);
            d1 = d1 + dx + (b * b);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d1 = d1 + dx - dy + (b * b);
        }
    }

    while (y >= 0)
    {
        drawPixel(x, y);
        float d2 = ((b * b) * (0.5 + x) * (0.5 + x)) + (a * a * (y - 1) * (y - 1)) - (a * a * b * b);
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * a * a);
            d2 = d2 - dy + (a * a);
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d2 = d2 + dx - dy + (a * a);
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
    glutCreateWindow("ellipse");
    glClearColor(0.5, 0.5, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

    glutDisplayFunc(myinit);
    glutMainLoop();
    return 0;
}