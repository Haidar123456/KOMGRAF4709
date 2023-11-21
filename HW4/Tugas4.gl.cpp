#include <GL/glut.h>
#include <iostream>

int xa = 3, ya = 6, xb = 8, yb = 5;

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine(int xa, int ya, int xb, int yb) {
    int dx = abs(xb - xa);
    int dy = abs(yb - ya);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int x, y;

    if (xa > xb) {
        x = xb;
        y = yb;
        xb = xa;
    } else {
        x = xa;
        y = ya;
    }

    setPixel(x, y);

    while (x < xb) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            if ((xb - xa) * (yb - ya) > 0) {
                y++;
            } else {
                y--;
            }
            p += twoDyMinusDx;
        }
        setPixel(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    bresenhamLine(xa, ya, xb, yb);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 20, 0, 20);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

