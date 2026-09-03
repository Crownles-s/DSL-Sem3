#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **mat, int r, int c) {
    printf("Enter elements:\n", r, c);
    int i, j;
    for (i=0; i<r; i++) {
        for (j=0; j<c; j++) {
            scanf("%d", *(mat+i)+j);
        }
    }
}
void displayMatrix(int **mat, int r, int c) {
    int i, j;
    for (i=0; i<r; i++) {
        for (j=0; j<c; j++) {
            printf("%d\t", *(*(mat+i)+j));
        }
        printf("\n");
    }
}

int **multiplyMatrix(int **A, int r1, int c1, int **B, int r2, int c2) {
    if (c1!=r2) {
        printf("Not possible\n");
        return NULL;
    }

    int **C = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        *(C + i) = (int *)malloc(c2 * sizeof(int));
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(*(C + i) + j) = 0;
            for (int k = 0; k < c1; k++) {
                *(*(C + i) + j) += (*(*(A + i) + k)) * (*(*(B + k) + j));
            }
        }
    }
    return C;
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter size of A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter size of B: ");
    scanf("%d %d", &r2, &c2);

    int **A = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        *(A + i) = (int *)malloc(c1 * sizeof(int));
    }

    int **B = (int **)malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++) {
        *(B + i) = (int *)malloc(c2 * sizeof(int));
    }

    readMatrix(A, r1, c1);
    readMatrix(B, r2, c2);

    printf("\nMatrix A:\n");
    displayMatrix(A, r1, c1);
    printf("\nMatrix B:\n");
    displayMatrix(B, r2, c2);

    int **C = multiplyMatrix(A, r1, c1, B, r2, c2);
    if (C != NULL) {
        printf("\nProduct:\n");
        displayMatrix(C, r1, c2);
    }
}

