#include <stdlib.h>
#include "memory_manager.h"

int mm_allocate_best_fit(
    MemoryManager* mm,
    int size
) {
    if (mm == NULL || size <= 0)
        return -1;

    MemoryBlock* current = mm->head;
    MemoryBlock* best = NULL;

    while (current != NULL) {
        if (current->free && current->size >= size) {
            if (best == NULL || current->size < best->size)
                best = current;
        }

        current = current->next;
    }

    if (best == NULL)
        return -1;

    if (best->size > size) {
        MemoryBlock* new_block = malloc(sizeof(MemoryBlock));

        if (new_block == NULL)
            return -1;

        new_block->start = best->start + size;
        new_block->size = best->size - size;
        new_block->free = 1;
        new_block->pid = -1;
        new_block->next = best->next;
        new_block->prev = best;

        if (best->next != NULL)
            best->next->prev = new_block;

        best->next = new_block;
    }

    best->size = size;
    best->free = 0;
    best->pid = best->start;

    return best->pid;
}
