// Give the item a type (TODO)
typedef int item;

#define NULLITEM 0

// Print data of an item to stdout
void printItem(item it);

// Deallocate an item (to use only if the item is allocated) 
void freeItem(item it);

// Return 1 if the items are equal 0 if not
int isEqual(item it1, item it2);

int eq(item x, item y); //controlla se due item sono uguali
void input_item(item *x); //inserisce un item 
void output_item(item x); //mostra in output l'item x