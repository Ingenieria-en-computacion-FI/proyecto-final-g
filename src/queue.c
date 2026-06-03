#include <stdlib.h>
#include "../include/queue.h"

struct Node {
    int value;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

Queue* queue_create() {
    Queue* queue = malloc(sizeof(Queue));

    if (queue == NULL)
        return NULL;

    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void enqueue(Queue* queue, int value) {
    if (queue == NULL)
        return;

    struct Node* node = malloc(sizeof(struct Node));

    if (node == NULL)
        return;

    node->value = value;
    node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

int dequeue(Queue* queue) {
    if (queue == NULL || queue->front == NULL)
        return -1;

    struct Node* temp = queue->front;
    int value = temp->value;

    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return value;
}

int queue_is_empty(Queue* queue) {
    return queue == NULL || queue->front == NULL;
}

void queue_destroy(Queue* queue) {
    if (queue == NULL)
        return;

    while (!queue_is_empty(queue)) {
        dequeue(queue);
    }

    free(queue);
}