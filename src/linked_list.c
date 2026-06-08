#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct LinkedNode {
    int value;
    struct LinkedNode* next;
} LinkedNode;

struct LinkedList {
    LinkedNode* head;
};

LinkedList* linked_list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    return list;
}

void linked_list_insert_ordered(LinkedList* list, int value) {
    if (list == NULL)
        return;

    LinkedNode* node = malloc(sizeof(LinkedNode));

    if (node == NULL)
        return;

    node->value = value;
    node->next = NULL;

    if (list->head == NULL || value < list->head->value) {
        node->next = list->head;
        list->head = node;
        return;
    }

    LinkedNode* current = list->head;

    while (current->next != NULL && current->next->value < value)
        current = current->next;

    node->next = current->next;
    current->next = node;
}

int linked_list_contains(LinkedList* list, int value) {
    if (list == NULL)
        return 0;

    LinkedNode* current = list->head;

    while (current != NULL) {
        if (current->value == value)
            return 1;

        current = current->next;
    }

    return 0;
}

void linked_list_print(LinkedList* list) {
    if (list == NULL)
        return;

    LinkedNode* current = list->head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void linked_list_destroy(LinkedList* list) {
    if (list == NULL)
        return;

    LinkedNode* current = list->head;

    while (current != NULL) {
        LinkedNode* next = current->next;
        free(current);
        current = next;
    }

    free(list);
}
