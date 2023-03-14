#include <iostream>
#include <stddef.h>
#include "form.h"

size_t size = 0;

void *my_malloc(size_t size_of) {
    size += size_of;
    return malloc(size_of);
}

void print_ram(size_t res_size) {
    std::cout << res_size << std::endl;
}

form *create_form(crud crud_operation) {
    struct form *form = (struct form *) my_malloc(sizeof form);
    form->tree = nullptr;
    form->crud_operation = crud_operation;
    return form;
}

list_level *create_level_list(uint8_t negative, uint8_t any, enum parent parent) {
    struct list_level *list_level = (struct list_level *) my_malloc(sizeof list_level);
    list_level->next = nullptr;
    list_level->value = nullptr;
    list_level->place = parent;
    list_level->any = any;
    list_level->negative = negative;
    list_level->filters = nullptr;
    return list_level;
}

list_element *create_element_list(int64_t id) {
    struct list_element *list_element = (struct list_element *) my_malloc(sizeof list_element);
    list_element->next = nullptr;
    list_element->element = id;
    return list_element;
}

filter_list *create_filter_list() {
    struct filter_list *filter_list = (struct filter_list *) my_malloc(sizeof filter_list);
    filter_list->next = nullptr;
    filter_list->value = nullptr;
    return filter_list;
}

filter *create_filter(uint8_t negative) {
    struct filter *filter = (struct filter *) my_malloc(sizeof filter);
    filter->negative = negative;
    filter->comparators = nullptr;
    return filter;
}

comparator_list *create_comparator_list() {
    struct comparator_list *comparator_list = (struct comparator_list *) my_malloc(sizeof comparator_list);
    comparator_list->value = nullptr;
    comparator_list->next = nullptr;
    return comparator_list;
}

comparator *create_comparator(compare compare) {
    struct comparator *comparator = (struct comparator *) my_malloc(sizeof comparator);
    comparator->negative = 0;
    comparator->true_flag = 0;
    comparator->operation = compare;
    comparator->op1 = nullptr;
    comparator->op2 = nullptr;
    return comparator;
}

op *create_operator(uint8_t field, enum field_types type, union types value) {
    struct op *op = (struct op *) my_malloc(sizeof op);
    op->value = value;
    op->type = type;
    op->field = field;
    return op;
}

field *create_field(size_t f_size, char *value) {
    struct field *field = (struct field *) my_malloc(sizeof(struct field));
    field->value = value;
    field->size = f_size;
    return field;
}