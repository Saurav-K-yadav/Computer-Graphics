// Create a empty window

#include <iostream>
#include <GL/glut.h>
using namespace std;

void line(int x, int y)
{
    glBegin(GL_POINTS);
    glColor3f(0.5, 1, 0.5);
    glVertex2f(x, y);
    glEnd();
}

void draw()
{
    int x1;
    int y1;
    int x2;
    int y2;
    cout << "Enter x1" << endl;
    cin >> x1;
    cout << "Enter y1" << endl;
    cin >> y1;
    cout << "Enter x2" << endl;
    cin >> x2;
    cout << "Enter y2" << endl;
    cin >> y2;
    line(x1, y1);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dx2 = 2 * dx;
    int dy2 = 2 * dy;
    int pk = dy2 - dx;
    float x = float(x1);
    float y = float(y1);

    while (x < x2)
    {
        x++;
        if (pk < 0)
            pk = pk + dy2;
        else
        {
            pk = pk + dy2 - dx2;
            y++;
        }
        line(x, y);
    }
}

void displayMe(void)
{
    draw();
    glFlush();
}

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1000, 400);
    glutCreateWindow("Bresenham Algorithm");
    myinit();
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}