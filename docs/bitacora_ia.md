# Bitácora IA

## Prompt utilizado
Se proporcionó a la IA el repositorio del proyecto Mini OS Project, incluyendo los archivos de encabezado, pruebas unitarias, scripts de Python y archivos fuente incompletos. Se solicitó apoyo para analizar la estructura del proyecto, identificar los módulos faltantes y proponer implementaciones para las estructuras de datos y el administrador de memoria.

## Respuesta IA
La IA realizó un análisis del proyecto y determinó que el repositorio entregado contenía implementaciones incompletas y módulos faltantes. Se identificaron como componentes principales:

Pila (Stack)
Cola (Queue)
Cola Circular (Circular Queue)
Scheduler FIFO
Scheduler Round Robin
Administrador de memoria
Algoritmo First Fit
Coalescencia de bloques libres

La IA explicó la lógica requerida para cada estructura de datos y propuso implementaciones para:

Stack
stack_create()
stack_push()
stack_pop()
stack_peek()
stack_is_empty()
stack_destroy()
Memory Manager
mm_create()
mm_allocate_first_fit()
mm_free()
mm_coalesce()
mm_destroy()

Además, se explicó el funcionamiento del algoritmo First Fit y la unión de bloques libres mediante coalescencia.

## Errores encontrados
El repositorio contiene archivos fuente incompletos con comentarios de "IMPLEMENTAR".
Algunos módulos referenciados por las pruebas unitarias no aparecen completos dentro del material proporcionado.
Se detectó una posible inconsistencia en la prueba de memoria al reutilizar identificadores de bloques liberados.
La estructura inicial del repositorio generó confusión respecto a la ubicación real de algunos archivos.

## Correcciones realizadas
Se revisó la estructura real del proyecto.
Se identificaron las funciones pendientes de implementación.
Se implementó la estructura de datos Queue siguiendo el comportamiento FIFO.
Se implementó la estructura Circular Queue para soportar la ejecución cíclica de procesos.
Se implementó el algoritmo de planificación FIFO.
Se implementó el algoritmo de asignación de memoria First Fit.
Se implementó la coalescencia de bloques libres para reducir la fragmentación externa.
Se verificó la integración entre los módulos implementados y las pruebas proporcionadas.
## Validaciones realizadas
Revisión de los casos de prueba de Stack.
Revisión de los casos de prueba de Queue.
Revisión de los casos de prueba de Circular Queue.
Revisión de los casos de prueba de Scheduler FIFO.
Revisión de los casos de prueba de Memory Manager.
Verificación conceptual del comportamiento LIFO para Stack.
Verificación conceptual del comportamiento FIFO para Queue.
Verificación del funcionamiento de Circular Queue mediante inserción y extracción circular.
Verificación conceptual del algoritmo First Fit.
Verificación conceptual de la coalescencia de bloques libres.
Comprobación de la reutilización de espacios libres tras liberar memoria.