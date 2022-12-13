#include <stdio.h>

struct Vect2 {
    int x, y;
};

void swap(struct Vect2 *v1, struct Vect2 *v2, size_t size) {
    int *arr1 = (int *) v1;
    int *arr2 = (int *) v2;

    for (int i = 0; i < size; i++) {
        arr1[i] ^= arr2[i];
        arr2[i] ^= arr1[i];
        arr1[i] ^= arr2[i];
    }
}

int main(void) {
    struct Vect2 v1 =  { 5, 5 };
    struct Vect2 v2 =  { 9, 7 };

    size_t vect2_size = sizeof(struct Vect2) / sizeof(int);

    swap(&v1, &v2, vect2_size);

    printf("v1 (%d, %d), v2 (%d, %d)\n", v1.x, v1.y, v2.x, v2.y);

    return 0;
}
