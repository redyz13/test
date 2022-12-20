#include "list.h"
#include <stdbool.h>  // for bool
#include <stdio.h>    // for printf

#define VA_ARGS(...) , ##__VA_ARGS__
#define CALL(obj, method, ...) ((obj).method(&(obj) VA_ARGS(__VA_ARGS__)))

void print(struct Node* node, bool is_float)
{
  if (!node) {
    return;
  }
  is_float ? printf("%f", *(float*)node->data) :
             printf("%d", *(int*)node->data);
  printf("%s", (node->next) ? "->" : "\n");
}

void print_int(struct Node* node)
{
  print(node, false);
}

void print_float(struct Node* node)
{
  print(node, true);
}

int main()
{
  int data_int[6] = { 11, 22, 33, 44, 55, 66 };
  float data_float[6] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f };

  struct List l = /*ListProxy*/List.new();
  l.prepend(&l, &data_int[0], sizeof(data_int[0]));
  l.append(&l, &data_int[1], sizeof(data_int[1]));
  l.append(&l, &data_int[2], sizeof(data_int[2]));
  l.prepend(&l, &data_int[3], sizeof(data_int[3]));
  l.append(&l, &data_int[4], sizeof(data_int[4]));
  l.prepend(&l, &data_int[5], sizeof(data_int[5]));
  l.traverse(&l, print_int);
  l.destroy(&l);

  CALL(l, prepend,  &data_float[0], sizeof(data_float[0]));
  CALL(l, append,   &data_float[1], sizeof(data_float[1]));
  CALL(l, append,   &data_float[2], sizeof(data_float[2]));
  CALL(l, prepend,  &data_float[3], sizeof(data_float[3]));
  CALL(l, append,   &data_float[4], sizeof(data_float[4]));
  CALL(l, prepend,  &data_float[5], sizeof(data_float[5]));
  CALL(l, traverse, print_float);
  CALL(l, destroy);

  return 0;
}