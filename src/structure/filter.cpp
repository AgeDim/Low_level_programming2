#include "filter.h"

filter::filter(uint8_t negative) {
    this->negative = negative;
    this->comparators = nullptr;
}
