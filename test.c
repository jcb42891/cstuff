#include <stdio.h>
#include "other.h"
#include "linkedlist.h"
#include <stdlib.h>
#include "hashmap.h"
#include <string.h>

void printList(LinkedList* list);

int compareStrings(void* a, void* b) {
  return strcmp((const char*)a, (const char*)b);
}

int compareInts(void* a, void* b) {
  int first = *(int *)a;
  int second = *(int *)b;

  return first != second;
}

void hashmap_test() { 
  HashMap* map; 
  initHashMap(map, compareStrings);
  
  int* val1 = malloc(sizeof(int));
  *val1 = 5;

  int* val2 = malloc(sizeof(int));
  *val2 = 10;

  putValue(map, "testKey1", val1);
  putValue(map, "testKey2", val2);

  printf("Key: %s, Value: %d", "testKey1", *(int*)getValue(map, "testKey1"));
  printf("Key: %s, Value: %d", "testKey2", *(int*)getValue(map, "testKey2"));
}

void linked_list_test() {
  LinkedList list;
  initList(&list);
  int* val1 = malloc(sizeof(int));
  int* val2 = malloc(sizeof(int));
  int* val3 = malloc(sizeof(int));
  int* val4 = malloc(sizeof(int));
  int* val5 = malloc(sizeof(int));
  int* val6 = malloc(sizeof(int));
  int* val7= malloc(sizeof(int));

  *val1 = 5;
  *val2 = 10;
  *val3 = 9;
  *val4 = 12;
  *val5 = 89;
  *val6 = 213;
  *val7 = 51;

  addItem(&list, val1);
  addItem(&list, val2);
  addItem(&list, val3);
  addItem(&list, val4);
  addItem(&list, val5);
  addItem(&list, val6);
  addItem(&list, val7);

  printList(&list);
  printf("------------------------\n");

  deleteItem(&list, 3);
  printList(&list);

  
  printf("------------------------\n");
  deleteByValue(&list, val5, compareInts);
  printList(&list);
}

int main() {
  //linked_list_test();

  printf("ENTERED");
  hashmap_test();
}

void printList(LinkedList* list) {
  ListNode* cur = list->head;

  while(cur) {
    printf("%d\n", *(int*)cur->value);
    cur = cur->next;
  }
}
