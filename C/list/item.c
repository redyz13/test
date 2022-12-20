#include <stdio.h>
#include "item.h"

// Change the function based on the item type (TODO in case)
void printItem(item it){
    printf("%d", it);
}

/* Change the function based on the item type (TODO in case)
*  You will need this function only if the item is allocated
*/
void freeItem(item it) {
    ;
}

// Change the function based on the item type (TODO in case)
int isEqual(item it1, item it2) {
    return it1 == it2;
}

int eq(item x, item y)
{
    return x == y;
}

void input_item(int *x)
{
    printf("inserisci un numero: ");
    scanf("%d", x);
} 

void output_item(item x)
{
    printf("%d", x);
} 