#include <stdio.h>
#include "list.h"

/* item getMiddleFromList(list l, int counter, int increment) {
    if (emptyList(l)) return NULLITEM;

    if (getItem(l, increment) == NULLITEM)
        return getItem(l, counter);
    else
        getMiddleFromList(l, counter + 1, increment + 2);
} */

item getMiddleFromList(list l, int increment) {
    if (emptyList(l)) return NULLITEM;

    if (getItem(l, increment) == NULLITEM)
        return getFirst(l);
    else
        getMiddleFromList(tailList(l), increment + 1);
}

int main(void) {
    list l;

    l = newList();

    l = consList(10, l);
    l = consList(20, l);
    l = consList(30, l);
    l = consList(40, l);
    l = consList(50, l);

    l = reverseList(l);
    outputList(l);

    item x = getMiddleFromList(l, 1);
    printf("\nMiddle item: %d\n", x);

    return 0;
}