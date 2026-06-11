#include <stdlib.h>

int parse_int(const char* text) {
    if (text == 0)
        return 0;

    return atoi(text);
}