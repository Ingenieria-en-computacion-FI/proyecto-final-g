#include <stdlib.h>
#include "memory_manager.h"

static int next_pid = 0;

MemoryManager* mm_create(int total_memory)
{
    MemoryManager* mm =
        malloc(sizeof(MemoryManager));

    mm->total_memory = total_memory;

    mm->head =
        malloc(sizeof(MemoryBlock));

    mm->head->start = 0;
    mm->head->size = total_memory;
    mm->head->free = 1;
    mm->head->pid = -1;
    mm->head->next = NULL;
    mm->head->prev = NULL;

    return mm;
}

int mm_allocate_first_fit(
    MemoryManager* mm,
    int size
)
{
    MemoryBlock* current = mm->head;

    while(current != NULL)
    {
        if(current->free &&
           current->size >= size)
        {
            if(current->size > size)
            {
                MemoryBlock* new_block =
                    malloc(sizeof(MemoryBlock));

                new_block->start =
                    current->start + size;

                new_block->size =
                    current->size - size;

                new_block->free = 1;
                new_block->pid = -1;

                new_block->next =
                    current->next;

                new_block->prev =
                    current;

                if(current->next)
                    current->next->prev =
                        new_block;

                current->next =
                    new_block;
            }

            current->size = size;
            current->free = 0;
            current->pid = next_pid++;

            return current->pid;
        }

        current = current->next;
    }

    return -1;
}

void mm_free(
    MemoryManager* mm,
    int pid
)
{
    MemoryBlock* current =
        mm->head;

    while(current)
    {
        if(current->pid == pid)
        {
            current->free = 1;
            current->pid = -1;

            mm_coalesce(mm);

            return;
        }

        current = current->next;
    }
}

void mm_coalesce(
    MemoryManager* mm
)
{
    MemoryBlock* current =
        mm->head;

    while(current &&
          current->next)
    {
        if(current->free &&
           current->next->free)
        {
            MemoryBlock* next =
                current->next;

            current->size += next->size;

            current->next =
                next->next;

            if(next->next)
                next->next->prev =
                    current;

            free(next);
        }
        else
        {
            current = current->next;
        }
    }
}

void mm_destroy(
    MemoryManager* mm
)
{
    MemoryBlock* current =
        mm->head;

    while(current)
    {
        MemoryBlock* next =
            current->next;

        free(current);

        current = next;
    }

    free(mm);
}