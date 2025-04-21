#include "hashmap.h"
#include <string.h>

void initHashMap(HashMap* map, int (*cmp)(void*, void*)) {
  map->buckets = malloc(sizeof(HashNode*) * INIT_CAPACITY);
  memset(map->buckets, 0, sizeof(HashNode*) * INIT_CAPACITY);
  map->size = 0;
  map->capacity = INIT_CAPACITY;
  map->comparefn = cmp;
}

size_t hash(HashMap* map, void* key_ptr) {
  return (size_t) key_ptr % map->capacity;
}

void putValue(HashMap* map, void* key, void* value) {
  size_t index = hash(map, key);

  HashNode* node_to_add = malloc(sizeof(HashNode));
  node_to_add->key = key;
  node_to_add->value = value;
  node_to_add->next = NULL;

  if(map->buckets[index] == NULL) {
    map->buckets[index] = node_to_add;
  } else {
    HashNode* cur = map->buckets[index];
    while(cur->next) {
      cur = cur->next;
    }
    cur->next = node_to_add;
  }
  map->size++;
  // TODO: If size >= capacity, we need to bump the capacity.
}

void* getValue(HashMap* map, void* key) { 
  size_t index = hash(map, key);
  
  if (map->buckets[index] == NULL) {
    return NULL;
  } else {
    HashNode* cur = map->buckets[index];
    while(cur) {
      while(map->comparefn(cur->key, key) != 0) {
        cur = cur->next;
      }
      return cur->value;
    }
    return NULL;
  }
}
