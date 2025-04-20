#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct ListNode {
  void* value;
  struct ListNode* next; 
} ListNode; 

typedef struct LinkedList {
  struct ListNode* head;
} LinkedList;

void initList(LinkedList* list);
void addItem(LinkedList* list, void* value);
void deleteItem(LinkedList* list, int index);
void deleteByValue(LinkedList* list, void* value, int (*cmp)(void*, void*));

#endif
