#ifndef LOW_LEVEL_PROGRAMMING2_FILTER_H
#define LOW_LEVEL_PROGRAMMING2_FILTER_H


#include <cstdint>
#include "comparator_list.h"

struct filter {
    uint8_t negative;
    comparator_list *comparators;

    explicit filter(uint8_t negative);
};

#endif //LOW_LEVEL_PROGRAMMING2_FILTER_H
