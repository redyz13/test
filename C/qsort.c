#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2) {
    return (*(int *)p1 - *(int *)p2);
}

int main(void) {
    int arr[] = { 5, 6, 7, 1, 2, 3, 0, -5, -1, 8, 7 };
    size_t n = sizeof(arr) / sizeof(*arr);
    
    qsort(arr, n, sizeof(*arr), comparator);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    putchar('\n');

    return 0;
}