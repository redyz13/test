#ifndef LIST_H
#define LIST_H

#include <stddef.h> // for size_t

struct Node {
  void* data; // Any data type can be stored in this node
  struct Node* next;
};

typedef void (*Callback)(struct Node* node);
struct List {
  struct Node* head;
  struct Node* cursor;

  void (* const destroy)(struct List* self);
  void (* const append)(struct List* self, void* data, size_t size);
  void (* const prepend)(struct List* self, void* data, size_t size);
  void (* const traverse)(struct List* self, Callback func);
};

extern const struct ListClass {
  struct List (*new)();
} /*ListProxy*/ List;

#endif // LIST_H