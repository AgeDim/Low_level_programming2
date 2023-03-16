#include "list_element.h"

list_element::list_element(int64_t id) {
    this->next = nullptr;
    this->element = id;
}
