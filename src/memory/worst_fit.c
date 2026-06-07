#include <stdlib.h>
#include "memory_manager.h"

int mm_allocate_worst_fit(
    MemoryManager* mm,
    int size
) {
    if (mm == NULL || size <= 0)
        return -1;

    MemoryBlock* current = mm->head;
    MemoryBlock* worst = NULL;

    while (current != NULL) {
        if (current->free && current->size >= size) {
            if (worst == NULL || current->size > worst->size)
                worst = current;
        }

        current = current->next;
    }

    if (worst == NULL)
        return -1;

    if (worst->size > size) {
        MemoryBlock* new_block = malloc(sizeof(MemoryBlock));

        if (new_block == NULL)
            return -1;

        new_block->start = worst->start + size;
        new_block->size = worst->size - size;
        new_block->free = 1;
        new_block->pid = -1;
        new_block->next = worst->next;
        new_block->prev = worst;

        if (worst->next != NULL)
            worst->next->prev = new_block;

        worst->next = new_block;
    }

    worst->size = size;
    worst->free = 0;
    worst->pid = worst->start;

    return worst->pid;
}
