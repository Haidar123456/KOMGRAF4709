#include <iostream>
#include <cmath>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2) {
    int deltaX, deltaY, steps;
    float xIncrement, yIncrement, currentX, currentY;

    deltaX = x2 - x1;
    deltaY = y2 - y1;

    if (abs(deltaX) > abs(deltaY)) {
        steps = abs(deltaX);
    } else {
        steps = abs(deltaY);
    }

    xIncrement = static_cast<float>(deltaX) / steps;
    yIncrement = static_cast<float>(deltaY) / steps;

    currentX = x1;
    currentY = y1;

    cout << "Titik koordinat garis :" << endl;

    for (int i = 0; i <= steps; i++) {
        cout << "(" << round(currentX) << ", " << round(currentY) << ")" << endl;
        currentX += xIncrement;
        currentY += yIncrement;
    }
}

int main() {
    int xStart, yStart, xEnd, yEnd;

    cout << "Masukkan titik koordinat awal (x1 y1): ";
    cin >> xStart >> yStart;
    cout << "Masukkan titik koordinat akhir (x2 y2): ";
    cin >> xEnd >> yEnd;

    drawLine(xStart, yStart, xEnd, yEnd);

    return 0;
}
