#ifndef LOW_LEVEL_PROGRAMMING2_LIST_ELEMENT_H
#define LOW_LEVEL_PROGRAMMING2_LIST_ELEMENT_H

#include <cstdint>

struct list_element {
    list_element *next;
    int64_t element;

    explicit list_element(int64_t id);
};

#endif //LOW_LEVEL_PROGRAMMING2_LIST_ELEMENT_H
