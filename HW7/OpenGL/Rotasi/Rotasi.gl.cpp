#include <GL/glut.h>
#include <cmath>

float angle = 30.0f; // Sudut rotasi dalam derajat

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void rotatePoint(float& x, float& y, float angle, float pivotX, float pivotY) {
    // Konversi sudut dari derajat ke radian
    float radian = angle * (M_PI / 180.0);

    // Translasi pusat rotasi ke titik awal
    x -= pivotX;
    y -= pivotY;

    // Rotasi terhadap pusat rotasi
    float rotatedX = x * cos(radian) - y * sin(radian);
    float rotatedY = x * sin(radian) + y * cos(radian);

    // Translasi kembali ke posisi awal
    x = rotatedX + pivotX;
    y = rotatedY + pivotY;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah

    float x1 = 4.0f, y1 = 6.0f, x2 = 9.0f, y2 = 11.0f;

    // Garis awal sebelum rotasi
    drawLine(x1, y1, x2, y2);

    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru

    // Rotasi titik-titik garis sebelum menggambar garis setelah rotasi
    rotatePoint(x1, y1, angle, 3.0f, 3.0f);
    rotatePoint(x2, y2, angle, 3.0f, 3.0f);

    // Garis setelah rotasi
    drawLine(x1, y1, x2, y2);

    glutSwapBuffers();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 10.0, 0.0, 10.0); // Window coordinates
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Rotasi Garis");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

