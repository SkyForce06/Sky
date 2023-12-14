#include "backsubst.h"

int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r != b->r || x->r != mat->c || x->c != 1) {
        return 2; // Błąd nieprawidłowych rozmiarów macierzy
    }

    for (int i = mat->r - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0) {
            return 1; // Błąd dzielenia przez 0 (element na diagonali = 0)
        }

        x->data[i][0] = b->data[i][0];
        
        for (int j = i + 1; j < mat->r; j++) {
            x->data[i][0] -= mat->data[i][j] * x->data[j][0];
        }

        x->data[i][0] /= mat->data[i][i];
    }

    return 0; // Wsteczne podstawienie zakończone sukcesem
}





