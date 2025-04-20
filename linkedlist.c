#include "linkedlist.h"
#include <stdlib.h>

void initList(LinkedList* list) {
  list->head = NULL;
}

void addItem(LinkedList* list, void* value) {
  ListNode* newNode = malloc(sizeof(ListNode));
  newNode->value = value;
  newNode->next = NULL;

  // If we're at the head, just append and return
  if(list->head == NULL) {
    list->head = newNode;
    return;
  }

  ListNode* cur = list->head;
  while(cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = newNode;

}

void deleteItem(LinkedList* list, int index) {
  int i = 0;
  ListNode* cur = list->head;
  ListNode* prev = NULL;

  if(cur == NULL) {
    // Nothing to delete
    return;
  } else if (index == 0) {
    // We need to delete the head.
    list->head = list->head->next;
    free(cur);
    return;
  }

  while(i != index && cur != NULL) {
    prev = cur;
    cur = cur->next;
    i++;
  }

  if (cur == NULL) return; // index out of bounds

  if (i == index) {
    // We found the node to remove
    prev->next = cur->next;
    free(cur->value);
    free(cur);
  }
}

void deleteByValue(LinkedList* list, void* value, int (*cmp)(void*, void*)) {
  ListNode* cur = list->head;
  ListNode* prev = NULL;

  if(cur == NULL) {
    // Nothing to delete
    return;
  } else if ( cmp(list->head->value, value) == 0 ) {
    list->head = list->head->next;
    free(cur);
    return;
  }

  while(cur) {
    if( cmp(cur->value, value) == 0) {
      // Need to delete this node
      prev->next = cur->next;
      free(cur->value);
      free(cur);
      return;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
}

