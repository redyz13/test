#include <stdio.h>
#include <stdlib.h>

#define max(x, y) x > y ? x : y

int func(int *a, int l, int r, int x) {
    if (l > r)
        return 0;
    if (l == r) {
        return a[l] == x ? l : 0;
    }

    int c = (l + r) / 2;

    if (a[c] <= x)
        return max(c, func(a, c + 1, r, x));
    else
        return func(a, l, c - 1, x);
}

int main(void) {
    int arr[] = { 1, 2, 2, 3, 3, 3, 4, 5, 7, 7 };

    printf("%d\n", func(arr, 0, sizeof(arr)/sizeof(*arr) - 1, 2));

    return 0;
}