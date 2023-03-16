#ifndef LOW_LEVEL_PROGRAMMING2_OP_H
#define LOW_LEVEL_PROGRAMMING2_OP_H

#include "form.h"
#include <cstdint>

struct op {
    uint8_t field;
    field_types type;
    types value{};

    op(uint8_t field, enum field_types type, union types value);
};


#endif //LOW_LEVEL_PROGRAMMING2_OP_H
