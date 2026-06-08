#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DoublyLinkedList DoublyLinkedList;

DoublyLinkedList* dll_create();
void dll_push_back(DoublyLinkedList* list, int value);
int dll_pop_front(DoublyLinkedList* list);
int dll_is_empty(DoublyLinkedList* list);
void dll_destroy(DoublyLinkedList* list);

#endif
