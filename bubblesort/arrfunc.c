#include <stdio.h>
#include "arrfunc.h"

int get_dim(int min, int max) {
    int x;

    do {
        printf("Insert the array dimension: ");
        scanf("%d", &x);
    } while(x < min || x > max);

    return x;
}

void read_array(int arr[], int lenght) {
    int i;

    for(i = 0; i < lenght; i++) {
        printf("\nInsert number %d of the array: ", i);
        scanf("%d", &arr[i]);
    }
}

void print_array(int arr[], int lenght) {
    int i;

    for(i = 0; i < lenght; i++)
        printf("\nNumber %d of the array = %d\n", i, arr[i]);
}

void bubble_sort(int arr[], int lenght) {
    int i, j, tmp;

    for(i = lenght - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

