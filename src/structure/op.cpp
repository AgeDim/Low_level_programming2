#include "op.h"

op::op(uint8_t field, enum field_types type, union types value) {
    this->field = field;
    this->type = type;
    this->value = value;
}
