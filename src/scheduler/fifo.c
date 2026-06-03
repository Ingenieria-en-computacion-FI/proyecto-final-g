#include <stdlib.h>
#include "scheduler.h"
#include "queue.h"

struct Scheduler {
    Queue* queue;
};

Scheduler* scheduler_create_fifo() {
    Scheduler* scheduler = malloc(sizeof(Scheduler));

    scheduler->queue = queue_create();

    return scheduler;
}

void scheduler_add_process(
    Scheduler* scheduler,
    int pid,
    int burst_time
) {
    (void) burst_time;

    enqueue(scheduler->queue, pid);
}

int scheduler_next(Scheduler* scheduler) {
    return dequeue(scheduler->queue);
}

void scheduler_destroy(Scheduler* scheduler) {
    queue_destroy(scheduler->queue);
    free(scheduler);
}