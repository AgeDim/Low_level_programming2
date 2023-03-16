#ifndef LOW_LEVEL_PROGRAMMING2_FIELD_H
#define LOW_LEVEL_PROGRAMMING2_FIELD_H

#include <cstddef>

struct field {
    size_t size;
    char *value;

    field(size_t size, char *value);
};

#endif
