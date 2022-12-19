#include <stdio.h>
#include <stdlib.h>
#include "Entity.h"
#include "Element.h"

void f1(void) {
    Entity e;

    initEntity(&e);
    e.x = 30;

    printf("%d\n", e.GetX(&e));

    Entity *y = malloc(sizeof(Entity));
    initEntity(y);

    y->PrintName(y);
    y->SetX(y, 127);

    printf("%d\n", y->GetX(y));
    printf("%d\n", e.GetX(&e));
}

void f2(void) {
    Element e;

    initElement(&e);
    e.x = 90;

    printf("%d\n", e.GetX(&e));
    e.SetX(&e, 70);
    printf("%d\n", e.GetX(&e));
}

int main(void) {
    f1();
    f2();

    return 0;
}