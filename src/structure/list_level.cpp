#include "list_level.h"

list_level::list_level(uint8_t negative, uint8_t any, parent parent) {
    this->place = parent;
    this->any = any;
    this->negative = negative;
}
