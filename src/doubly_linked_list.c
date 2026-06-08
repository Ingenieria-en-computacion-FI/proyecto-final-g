#include <stdlib.h>
#include "doubly_linked_list.h"

typedef struct DoublyNode {
    int value;
    struct DoublyNode* next;
    struct DoublyNode* prev;
} DoublyNode;

struct DoublyLinkedList {
    DoublyNode* head;
    DoublyNode* tail;
};

DoublyLinkedList* dll_create() {
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;

    return list;
}

void dll_push_back(DoublyLinkedList* list, int value) {
    if (list == NULL)
        return;

    DoublyNode* node = malloc(sizeof(DoublyNode));

    if (node == NULL)
        return;

    node->value = value;
    node->next = NULL;
    node->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = node;
    else
        list->head = node;

    list->tail = node;
}

int dll_pop_front(DoublyLinkedList* list) {
    if (list == NULL || list->head == NULL)
        return -1;

    DoublyNode* node = list->head;
    int value = node->value;

    list->head = node->next;

    if (list->head != NULL)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(node);

    return value;
}

int dll_is_empty(DoublyLinkedList* list) {
    return list == NULL || list->head == NULL;
}

void dll_destroy(DoublyLinkedList* list) {
    if (list == NULL)
        return;

    while (!dll_is_empty(list))
        dll_pop_front(list);

    free(list);
}
