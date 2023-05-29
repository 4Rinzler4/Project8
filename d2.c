#include <stdio.h>
#include <stdlib.h>
#include <time.h>//підключення бібілотек
// Функція для введення елементів масиву
void inputArray(int *arr, int n) {
    printf("Введіть %d елементів масиву:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
// Функція для виведення елементів масиву
void printArray(int *arr, int n) {
    printf("Елементи масиву: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Функція для обчислення кількості від'ємних елементів масиву
int countNegative(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    if (count == 0) {
        return -1; // Повертаємо -1, якщо немає від'ємних елементів
    }
    return count;
}
// Функція для обчислення суми елементів масиву, розташованих після мінімального елемента
int sumAfterMin(int *arr, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    int sum = 0;
    for (int i = minIndex + 1; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    int n;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);
    int *array = (int*)malloc(n * sizeof(int)); // Виділення пам'яті під масив
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел
    // Заповнення масиву випадковими числами в діапазоні [-100, 100]
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 201 - 100;
    }
    printArray(array, n); // Виклик функції для виведення елементів масиву
    int negativeCount = countNegative(array, n); // Виклик функції для обчислення кількості від'ємних елементів
    if (negativeCount == -1) {
        printf("В масиві немає від'ємних елементів.\n");
    } else {
        printf("Кількість від'ємних елементів: %d\n", negativeCount);//виведення результату
    }
    int sumAfterMinimum = sumAfterMin(array, n); // Виклик функції для обчислення суми елементів після мінімального                                                                                                                                                              
    printf("Сума елементів після мінімального: %d\n", sumAfterMinimum);//виведення результату
    free(array); // Звільнення пам'яті
    return 0;//кінеь програми
}
