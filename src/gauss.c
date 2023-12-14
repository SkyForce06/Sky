#include "gauss.h"

int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->rows;

    for (int k = 0; k < n - 1; k++) {
        // Eliminacja współczynników poniżej diagonali
        for (int i = k + 1; i < n; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];
            b->data[i][0] -= factor * b->data[k][0];
            for (int j = k; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
        }
    }

    // Sprawdź, czy macierz jest osobliwa
    for (int i = 0; i < n; i++) {
        if (mat->data[i][i] == 0.0) {
            return 1; // Macierz osobliwa
        }
    }

    return 0; // Eliminacja zakończona sukcesem
}