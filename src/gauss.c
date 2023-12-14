#include "gauss.h"

int eliminate(Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r != b->r) {
        return 2; // Błąd nieprawidłowych rozmiarów macierzy
    }

    for (int k = 0; k < mat->r - 1; k++) {
        for (int i = k + 1; i < mat->r; i++) {
            if (mat->data[k][k] == 0) {
                return 1; // Błąd dzielenia przez 0 (element na diagonali = 0)
            }

            double factor = mat->data[i][k] / mat->data[k][k];

            for (int j = k; j < mat->r; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }

            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0; // Eliminacja zakończona sukcesem
}

