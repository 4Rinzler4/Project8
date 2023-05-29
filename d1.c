#include <stdio.h>//підключення бібліотеки
void printMatrix(int *matrix, int n, int p) {
    int i, j;
    for (j = 0; j < p; j++) {
        if (j % 2 == 0) {
            for (i = 0; i < n; i++) {
                printf("%d ", *(matrix + i * p + j));
            }
        } else {
            for (i = n - 1; i >= 0; i--) {
                printf("%d ", *(matrix + i * p + j));
            }
        }
        printf("\n");
    }
}
int main() {
    int n, p;
    printf("Введіть розмір матриці (n x p): ");
    scanf("%d %d", &n, &p);
    int matrix[n][p];
    int *matrixPtr = &matrix[0][0];
    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", (matrixPtr + i * p + j));//введення даних
        }
    }
    printf("Матриця:\n");
    printMatrix(matrixPtr, n, p);//виведення результатів
    return 0;//кінець програми
}
