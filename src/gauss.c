#include "gauss.h"

int eliminate(Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r != b->r) {
        return 2; // Błąd nieprawidłowych rozmiarów macierzy
    }

    for (int k = 0; k < mat->r - 1; k++) {
        // Wybór elementu głównego
        int minRow = k;
        for (int i = k + 1; i < mat->r; i++) {
            if (fabs(mat->data[i][k]) < fabs(mat->data[minRow][k])) {
                minRow = i;
            }
        }

        for (int j = k; j < mat->r; j++) {
            double temp = mat->data[k][j];
            mat->data[k][j] = mat->data[minRow][j];
            mat->data[minRow][j] = temp;
        }

        double temp = b->data[k][0];
        b->data[k][0] = b->data[minRow][0];
        b->data[minRow][0] = temp;

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