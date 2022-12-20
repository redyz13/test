#include <stdio.h>

void swap(void *x, void *y, size_t elsize) {
    char tmp;
    char *a = x, *b = y;

    // Copy byte by byte
    while (elsize--) {
        tmp = *a;
        *a++ = *b;
        *b++ = tmp;
    }
}

void reverse(void *arr, const size_t elsize, unsigned start, unsigned end) {
    if (start >= end) return;

    swap(&(((char *)arr)[start * elsize]), &(((char *)arr)[end * elsize]), elsize);
    reverse(arr, elsize, start + 1, end - 1);
}

// Testing
int main(void) {
    int arr1[] = { 1, 2, 3, 4, 5 };
    char arr2[] = { 'a', 'b', 'c', 'd', 'e' };
    float arr3[] = { 5.7f, 3.2f, 4.6f, 8.2f, 9.22f };

    unsigned size = sizeof(arr1) / sizeof(arr1[0]);

    reverse(arr1, sizeof(int), 0, size - 1);
    reverse(arr2, sizeof(char), 0, size - 1);
    reverse(arr3, sizeof(float), 0, size - 1);

    for (int i = 0; i < size; i++)
        printf("%d ", arr1[i]);

    putchar('\n');

    for (int i = 0; i < size; i++)
        printf("%c ", arr2[i]);

    putchar('\n');

    for (int i = 0; i < size; i++)
        printf("%.3f ", arr3[i]);

    putchar('\n');

    return 0;
}
