#include <stdio.h>

void get_max(int a, int b, int *max);

int main() {
    int x = 5, y = 10, max;

    get_max(x, y, &max);

    printf("Max: %d\n", max);

    return 0;
}

void get_max(int a, int b, int *max) {
    if(a > b) {
        *max = a;
    }
    else {
        *max = b;
    }
}

