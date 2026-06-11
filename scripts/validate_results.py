from pathlib import Path

required = [
    "include/stack.h",
    "include/queue.h",
    "include/circular_queue.h",
    "include/scheduler.h",
    "include/memory_manager.h",
    "src/main.c",
    "src/stack.c",
    "src/queue.c",
    "src/circular_queue.c",
    "src/scheduler/fifo.c",
    "src/scheduler/round_robin.c",
    "src/memory/first_fit.c",
    "src/memory/coalescence.c",
]

missing = [path for path in required if not Path(path).exists()]

if missing:
    print("Archivos faltantes:")
    for path in missing:
        print("-", path)
else:
    print("Validacion correcta: archivos principales encontrados.")
