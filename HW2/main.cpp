#include <iostream>

using namespace std;

// Fungsi untuk menampilkan matriks
void displayMatrix(int mat[][2], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[2][2], B[2][2], result[2][2], n;

    // Memasukkan elemen-elemen matriks A
    cout << "Masukkan elemen-elemen matriks A:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> A[i][j];
        }
    }

    // Memasukkan elemen-elemen matriks B
    cout << "Masukkan elemen-elemen matriks B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> B[i][j];
        }
    }

    // Menampilkan hasil A + B
    cout << "Hasil A + B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    displayMatrix(result, 2, 2);

    // Menampilkan hasil A - B
    cout << "Hasil A - B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    displayMatrix(result, 2, 2);

    // Menampilkan hasil A * B
    cout << "Hasil A * B:" << endl;
    result[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    result[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    result[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    result[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    displayMatrix(result, 2, 2);

    // Memasukkan nilai n
    cout << "Masukkan nilai n untuk A * n:" << endl;
    cin >> n;

    // Menampilkan hasil A * n
    cout << "Hasil A * n:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] * n;
        }
    }
    displayMatrix(result, 2, 2);

    return 0;
}
