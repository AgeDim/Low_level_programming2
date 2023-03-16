#ifndef LOW_LEVEL_PROGRAMMING2_LIST_LEVEL_H
#define LOW_LEVEL_PROGRAMMING2_LIST_LEVEL_H

#include <cstdint>
#include "form.h"
#include "list_element.h"
#include "filter_list.h"

struct list_level {
    uint8_t negative;
    uint8_t any;
    parent place;
    list_level *next = nullptr;
    list_element value = list_element(0);
    filter_list *filters = nullptr;

    list_level(uint8_t negative, uint8_t any, parent parent);
};

#endif //LOW_LEVEL_PROGRAMMING2_LIST_LEVEL_H
