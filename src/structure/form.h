#ifndef LOW_LEVEL_PROGRAMMING2_FORM_H
#define LOW_LEVEL_PROGRAMMING2_FORM_H

#include <cstdint>
#include "field.h"

enum parent {
    P_ROOT = 0,
    P_FREE,
    P_RELATIVE
};

enum crud {
    CRUD_INSERT = '+',
    CRUD_DELETE = '-',
    CRUD_FIND = '?',
    CRUD_UPDATE = '=',
};



enum compare {
    COMPARE_EQUAL = '=',
    COMPARE_LESS = '<',
    COMPARE_GREATER = '>',
    COMPARE_SUBSTR = ':',
    COMPARE_NOT_EQUAL = '!='
};



enum field_types {
    STRING_TYPE = 0,
    INTEGER_TYPE,
    FLOAT_TYPE,
    BOOLEAN_TYPE
};

union types {
    field *string;
    int64_t integer;
    int64_t boolean;
    double real;
};

struct form {
    enum crud crud_operation;
    struct list_level *tree;

    explicit form(crud crud_operation);
};
#endif //LOW_LEVEL_PROGRAMMING2_FORM_H
