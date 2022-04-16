// Give the item a type (TODO)
typedef struct Person *Item;

#define NULLITEM NULL

// Print data of an item to stdout
void printItem(Item it);

// Deallocate an item (to use only if the item is allocated) 
void freeItem(Item it);

// Return 1 if the items are equal 0 if not
int isEqual(Item it1, Item it2);

Item buildItem(char *name, char *surname, int age);
