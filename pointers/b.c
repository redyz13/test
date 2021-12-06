#include <stdio.h>

int *get_max(int *x, int y);

int main() {
    int x = 15, y = 10;
    int *max;

    max = get_max(&x, y);

    printf("Max: %d\n", *max);
    printf("X: %d\n", x);

    return 0;
}

int *get_max(int *x, int y) {
    int *max;
    int ciao = 5;

    if(*x > y) {
        max = x;
    }
    else {
        max = &y;
    }

    max = &ciao;
    printf("%p\n", max);
    printf("%p\n", &ciao);
    (*x)++;

    return max;
}
