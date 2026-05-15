#include "compare.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>


void compare(int* out, const char* a, const char* b) {
    for (size_t i = 0; i < strlen(a); i++) {
        out[i] = a[i] - b[i];
    }
}
