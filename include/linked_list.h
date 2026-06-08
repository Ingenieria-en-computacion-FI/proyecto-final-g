#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList LinkedList;

LinkedList* linked_list_create();
void linked_list_insert_ordered(LinkedList* list, int value);
int linked_list_contains(LinkedList* list, int value);
void linked_list_print(LinkedList* list);
void linked_list_destroy(LinkedList* list);

#endif
