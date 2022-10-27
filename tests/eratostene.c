#include <stdio.h>

void eratostene(int *arr, size_t size) {
    int c;

    for (int i = 0; i <= size / 2; i++) {
        c = 2;

        while (arr[i] * c <= size + 1) {
            arr[arr[i] * c - 2] = -1;
            c++;
        }
    }
}

int main(void) {
    int arr[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                  12, 13, 14, 15, 16, 17, 18, 19,
                  20, 21, 22, 23, 24, 25, 26, 27, 
                  28, 29, 30, 31, 32, 33, 34, 35, 
                  36, 37, 38, 39, 40, 41, 42, 43
                };
    size_t size = sizeof(arr) / sizeof(*arr);

    eratostene(arr, size);

    for (int i = 0; i < size; i++)
        if (arr[i] != -1)
            printf("%d ", arr[i]);

    putchar('\n');

    return 0;
}
