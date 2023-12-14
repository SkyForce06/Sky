#include "backsubst.h"

int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r != b->r || b->c != 1) {
        return 2; // błąd nieprawidłowych rozmiarów macierzy
    }

    int n = mat->r;
    int i, j;

    for (i = n - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0.0) {
            return 1; // błąd dzielenia przez 0 (element na diagonali = 0)
        }

        x->data[i][0] = b->data[i][0] / mat->data[i][i];

        for (j = i + 1; j < n; j++) {
            x->data[i][0] -= mat->data[i][j] * x->data[j][0];
        }
    }

    return 0; // wsteczne podstawienie zakończone sukcesem
}




