#include "scheduler.h"

Scheduler* scheduler_create_sjf() {
   
    return scheduler_create_fifo();
}
