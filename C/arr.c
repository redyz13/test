#include <stdio.h>

typedef struct {
    int *const arr;
    size_t len;
} intarr;

void printArr(intarr arr) {
    for (int i = 0; i < arr.len; i++)
        printf("%d ", arr.arr[i]);
    
    putchar('\n');
}

int main(void) {
    int arr1[] = { 0, 1, 2, 3, 4 };
    intarr a = { arr1, sizeof(arr1) / sizeof(int) };

    printArr(a);

    return 0;
}