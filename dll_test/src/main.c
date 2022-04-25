#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;

    list = newList();

    for(int i = 0; i <= 100000; i++) {
        addLast(list, i);
    }

    int x = get(list, 90000);
    int y = get(list, 40000);

    printf("%d", x);
    printf("\n%d", y);

    freeList(list);

    return 0;
}
