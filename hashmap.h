#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>
#include <stdlib.h>

#define INIT_CAPACITY 4

typedef struct HashNode {
  void* key;
  void* value;
  struct HashNode* next;
} HashNode;

typedef struct HashMap {
  HashNode** buckets;
  size_t size;
  size_t capacity;
  int (*comparefn)(void*, void*);
} HashMap;

void initHashMap(HashMap* map, int (*cmp)(void*, void*));
void putValue(HashMap* map, void* key, void* value);
void* getValue(HashMap* map, void* key);
void removeKey(HashMap* map, void* key);

#endif
