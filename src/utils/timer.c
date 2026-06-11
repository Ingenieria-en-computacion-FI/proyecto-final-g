#include <time.h>

double timer_now() {
    return (double) clock() / CLOCKS_PER_SEC;
}
