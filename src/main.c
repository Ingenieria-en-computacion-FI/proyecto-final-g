#include <stdio.h>

#include "stack.h"
#include "queue.h"
#include "circular_queue.h"
#include "scheduler.h"
#include "memory_manager.h"
#include "linked_list.h"
#include "doubly_linked_list.h"
#include "algorithms.h"

int main() {
    printf("=== Mini OS Project ===\n\n");

    printf("1. Prueba de Stack\n");
    Stack* stack = stack_create();
    stack_push(stack, 10);
    stack_push(stack, 20);
    printf("Pop: %d\n", stack_pop(stack));
    printf("Pop: %d\n\n", stack_pop(stack));
    stack_destroy(stack);

    printf("2. Prueba de Queue FIFO\n");
    Queue* queue = queue_create();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n\n", dequeue(queue));
    queue_destroy(queue);

    printf("3. Prueba de Circular Queue\n");
    CircularQueue* cq = cq_create(3);
    cq_enqueue(cq, 1);
    cq_enqueue(cq, 2);
    cq_enqueue(cq, 3);
    printf("CQ Dequeue: %d\n", cq_dequeue(cq));
    cq_enqueue(cq, 4);
    printf("CQ Dequeue: %d\n", cq_dequeue(cq));
    printf("CQ Dequeue: %d\n", cq_dequeue(cq));
    printf("CQ Dequeue: %d\n\n", cq_dequeue(cq));
    cq_destroy(cq);

    printf("4. Prueba de Scheduler FIFO\n");
    Scheduler* scheduler = scheduler_create_fifo();
    scheduler_add_process(scheduler, 1, 5);
    scheduler_add_process(scheduler, 2, 3);
    printf("Siguiente proceso FIFO: %d\n", scheduler_next(scheduler));
    printf("Siguiente proceso FIFO: %d\n\n", scheduler_next(scheduler));
    scheduler_destroy(scheduler);

    printf("5. Prueba de Round Robin\n");
    RoundRobinScheduler* rr = rr_create(5, 2);
    rr_add_process(rr, 1, 5);
    rr_add_process(rr, 2, 3);
    rr_add_process(rr, 3, 4);

    while (!rr_is_finished(rr))
        rr_next(rr);

    rr_destroy(rr);

    printf("\n6. Prueba de Memory Manager\n");
    MemoryManager* mm = mm_create(1024);
    int p1 = mm_allocate_first_fit(mm, 100);
    int p2 = mm_allocate_best_fit(mm, 200);
    int p3 = mm_allocate_worst_fit(mm, 50);

    printf("First Fit asigno bloque: %d\n", p1);
    printf("Best Fit asigno bloque: %d\n", p2);
    printf("Worst Fit asigno bloque: %d\n", p3);

    mm_free(mm, p1);
    mm_compact(mm);
    mm_destroy(mm);

    printf("\n7. Prueba de listas\n");
    LinkedList* list = linked_list_create();
    linked_list_insert_ordered(list, 3);
    linked_list_insert_ordered(list, 1);
    linked_list_insert_ordered(list, 2);
    printf("Lista ligada ordenada: ");
    linked_list_print(list);
    linked_list_destroy(list);

    DoublyLinkedList* dll = dll_create();
    dll_push_back(dll, 10);
    dll_push_back(dll, 20);
    printf("Lista doble pop front: %d\n", dll_pop_front(dll));
    dll_destroy(dll);

    printf("\n8. Prueba de algoritmos\n");
    int values[] = {1, 5, 3, 9, 2};
    printf("Busqueda fuerza bruta de 3: indice %d\n", brute_force_search(values, 5, 3));
    printf("Greedy valor maximo: %d\n", greedy_max_value(values, 5));
    printf("Backtracking subset sum 9: %d\n", backtracking_subset_sum(values, 5, 9));
    printf("Divide y venceras suma: %d\n", divide_conquer_sum(values, 0, 4));
    printf("DP topdown Fibonacci(8): %d\n", dp_fibonacci_topdown(8));
    printf("DP bottomup Fibonacci(8): %d\n", dp_fibonacci_bottomup(8));
    printf("Incremental suma: %d\n", incremental_sum(values, 5));

    printf("\nSimulacion finalizada correctamente.\n");

    return 0;
}

