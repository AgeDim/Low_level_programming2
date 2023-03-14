#ifndef LOW_LEVEL_PROGRAMMING2_FORM_H
#define LOW_LEVEL_PROGRAMMING2_FORM_H

#include <cstdint>

enum parent {
    P_ROOT = 0,
    P_FREE,
    P_RELATIVE
};

enum crud {
    CRUD_INSERT = '+',
    CRUD_DELETE = '-',
    CRUD_FIND = '?',
    CRUD_UPDATE = '='
};



enum compare {
    COMPARE_EQUAL = '=',
    COMPARE_LESS = '<',
    COMPARE_GREATER = '>',
    COMPARE_SUBSTR = ':'
};



enum field_types {
    STRING_TYPE = 0,
    INTEGER_TYPE,
    FLOAT_TYPE,
    BOOLEAN_TYPE
};

struct field {
    size_t size;
    char *value;
};

union types {
    struct field *string;
    int64_t integer;
    int64_t boolean;
    double real;
} ;

void *my_malloc(size_t size_of);
void print_ram();

struct op {
        uint8_t field;
        enum field_types type;
        union types value;
};

struct comparator {
    uint8_t negative;
    uint8_t true_flag;
    enum compare operation;
    struct op *op1;
    struct op *op2;
};

struct comparator_list {
    struct comparator_list *next;
    struct comparator *value;
};

struct filter {
    uint8_t negative;
    struct comparator_list *comparators;
};

struct filter_list {
    struct filter_list *next;
    struct filter *value;
};

struct list_element {
    struct list_element *next;
    int64_t element;
};

struct list_level {
    uint8_t negative;
    uint8_t any;
    enum parent place;
    struct list_level *next;
    struct list_element *value;
    struct filter_list *filters;
};

struct form {
    enum crud crud_operation;
    struct list_level *tree;
};

struct form *create_form(enum crud crud_op);

struct list_level *create_level_list(uint8_t negative, uint8_t any, enum parent place);

struct list_element *create_element_list    (int64_t id);

struct filter_list *create_filter_list();

struct filter *create_filter(uint8_t negative);

struct comparator_list *create_comparator_list();

struct comparator *create_comparator();

struct op *create_operator(uint8_t field, enum field_types type, union types value);

struct field *create_field(size_t size, char *value);


#endif //LOW_LEVEL_PROGRAMMING2_FORM_H
