#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;

    list = newList();

    Item p1, p2, p3;

    p1 = buildItem("Peppe", "Gay", 22);
    p2 = buildItem("Masta", "Five", 24);
    p3 = buildItem("Ciao", "Troia", 22);

    addFirst(list, p1);
    addLast(list, p2);
    addLast(list, p3);

    printList(list);

    removeItemPos(list, 0);
    removeItemPos(list, 0);
    removeItemPos(list, 0);
    Item p4 = getLast(list);

    putchar('\n');

    if(p4 != NULL)
        printItem(p4);

    freeItem(p1);
    freeItem(p2);
    freeItem(p3);
    freeList(list);

    return 0;
}
