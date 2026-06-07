#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct Scheduler Scheduler;

Scheduler* scheduler_create_fifo();

void scheduler_add_process(
    Scheduler* scheduler,
    int pid,
    int burst_time
);

int scheduler_next(
    Scheduler* scheduler
);

void scheduler_destroy(
    Scheduler* scheduler
);
typedef struct RoundRobinScheduler RoundRobinScheduler;

RoundRobinScheduler* rr_create(
    int capacity,
    int quantum
);

void rr_add_process(
    RoundRobinScheduler* scheduler,
    int pid,
    int burst_time
);

int rr_next(
    RoundRobinScheduler* scheduler
);

int rr_is_finished(
    RoundRobinScheduler* scheduler
);

void rr_destroy(
    RoundRobinScheduler* scheduler
);

Scheduler* scheduler_create_sjf();

#endif
