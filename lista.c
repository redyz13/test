#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int x;
    struct Nodo *next;
};

typedef struct Nodo* Nodo;

Nodo creaNodo(int x) {
    Nodo n;

    n = malloc(sizeof(struct Nodo));
    n->x = x;

    return n;
}

int main(void) {
    Nodo head, n2, n3, n4;

    head = creaNodo(7);

    n2 = creaNodo(21);
    head->next = n2;

    n3 = creaNodo(13);
    n2->next = n3;

    n4 = creaNodo(-1);
    n3->next = n4;

    n4->next = NULL;

    while(head != NULL) {
        printf("%d ", head->x);
        head = head->next;
    }

    return 0;
}
