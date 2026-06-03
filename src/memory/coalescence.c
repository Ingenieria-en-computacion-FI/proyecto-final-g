#include <stdlib.h>
#include "memory_manager.h"

void mm_coalesce(MemoryManager* mm) {
    if (mm == NULL || mm->head == NULL)
        return;

    MemoryBlock* current = mm->head;

    while (current != NULL && current->next != NULL) {

        if (current->free && current->next->free) {
            MemoryBlock* next_block = current->next;

            current->size += next_block->size;
            current->next = next_block->next;

            if (next_block->next != NULL) {
                next_block->next->prev = current;
            }

            free(next_block);
        } else {
            current = current->next;
        }
    }
}