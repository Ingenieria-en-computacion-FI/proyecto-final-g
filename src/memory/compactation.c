#include "memory_manager.h"

void mm_compact(
    MemoryManager* mm
) {
    
    if (mm == 0)
        return;

    mm_coalesce(mm);
}
