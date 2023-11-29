#include <GL/glut.h>

float translateX = 2.0f;
float translateY = 2.0f;
float scaleX = 0.5f;
float scaleY = 0.5f;

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah

    // Garis awal sebelum translasi dan scaling
    drawLine(1.0f, 3.0f, 6.0f, 8.0f);

    glTranslatef(translateX, translateY, 0.0f); // Translasi
    glScalef(scaleX, scaleY, 1.0f); // Scaling
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru

    // Garis setelah translasi dan scaling
    drawLine(1.0f, 3.0f, 6.0f, 8.0f);

    glLoadIdentity(); // Reset matriks transformasi
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
    glutCreateWindow("OpenGL Translasi dan Scaling");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

