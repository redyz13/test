#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"

#define BUFSIZE 50

struct Person {
    char *name;
    char *surname;
    int age;
};

// Change the function based on the item type (TODO in case)
void printItem(Item it){
    printf("\n%s\n%s\n%d\n", it->name, it->surname, it->age);
}

/* Change the function based on the item type (TODO in case)
*  You will need this function only if the item is allocated
*/
void freeItem(Item it) {
    free(it->name);
    free(it->surname);
    free(it);
}

// Change the function based on the item type (TODO in case)
int isEqual(Item it1, Item it2) {
    if(it1 == NULL || it2 == NULL) return 0;

    if(strcmp(it1->name, it2->name)) return 0;
    if(strcmp(it1->surname, it2->surname)) return 0;

    return it1->age == it2->age;
}

Item buildItem(char *name, char *surname, int age) {
    Item it;

    it = malloc(sizeof(struct Person));
    if(it == NULL) return NULL;

    it->name = malloc((strlen(name) + 1) % (BUFSIZE + 1));
    it->surname = malloc((strlen(surname) + 1) % (BUFSIZE + 1));

    strcpy(it->name, name);
    strcpy(it->surname, surname);

    if(it->name == NULL || it->surname == NULL) return NULL;

    it->age = age;

    return it;
}
