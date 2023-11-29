#include <GL/glut.h>

float translateX = 3.0f;
float translateY = 3.0f;

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah

    // Garis awal sebelum translasi
    drawLine(1.0f, 3.0f, 6.0f, 8.0f);

    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru

    // Garis setelah translasi
    drawLine(1.0f + translateX, 3.0f + translateY, 6.0f + translateX, 8.0f + translateY);

    glutSwapBuffers();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 15.0, 0.0, 15.0); // Window coordinates
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Translasi Garis");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

