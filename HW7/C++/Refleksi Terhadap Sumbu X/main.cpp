#include <iostream>
#include <array>

// Definisi matriks refleksi terhadap sumbu X
std::array<std::array<int, 3>, 3> reflectionMatrix = {{{1, 0, 0}, {0, -1, 0}, {0, 0, 1}}};

// Fungsi untuk melakukan refleksi terhadap matriks refleksi
std::pair<int, int> reflectOverMatrix(std::pair<int, int> point, std::array<std::array<int, 3>, 3>& matrix) {
    int x = point.first;
    int y = point.second;
    int w = 1; // Koordinat homogen, dengan w=1

    int result_x = x * matrix[0][0] + y * matrix[0][1] + w * matrix[0][2];
    int result_y = x * matrix[1][0] + y * matrix[1][1] + w * matrix[1][2];
    int result_w = x * matrix[2][0] + y * matrix[2][1] + w * matrix[2][2];

    // Normalisasi hasil ke koordinat homogen
    if (result_w != 0) {
        result_x /= result_w;
        result_y /= result_w;
    }

    return std::make_pair(result_x, result_y);
}

int main() {
    // Titik P1 dan P2
    std::pair<int, int> P1 = std::make_pair(1, 3);
    std::pair<int, int> P2 = std::make_pair(6, 8);

    // Refleksi titik P1 terhadap sumbu X menggunakan matriks 3x3
    std::pair<int, int> reflected_P1 = reflectOverMatrix(P1, reflectionMatrix);

    // Refleksi titik P2 terhadap sumbu X menggunakan matriks 3x3
    std::pair<int, int> reflected_P2 = reflectOverMatrix(P2, reflectionMatrix);

    // Menampilkan hasil refleksi
    std::cout << "Titik P1: (" << P1.first << ", " << P1.second << ")\n";
    std::cout << "Titik P1 setelah refleksi: (" << reflected_P1.first << ", " << reflected_P1.second << ")\n";
    std::cout << "Titik P2: (" << P2.first << ", " << P2.second << ")\n";
    std::cout << "Titik P2 setelah refleksi: (" << reflected_P2.first << ", " << reflected_P2.second << ")\n";

    return 0;
}
