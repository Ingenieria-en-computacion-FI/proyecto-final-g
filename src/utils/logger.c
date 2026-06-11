#include <stdio.h>

void log_message(const char* message) {
    if (message != 0)
        printf("[LOG] %s\n", message);
}
