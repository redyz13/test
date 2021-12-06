#include <stdio.h>
#include "arrfunc.h"
#define NMAX 30

int main() {
    int arr[NMAX], lenght;

    lenght = get_dim(0, 100);
    read_array(arr, lenght);
    bubble_sort(arr, lenght);

    printf("\nSorted array:\n");

    print_array(arr, lenght);

    return 0;
}
