#include <cstddef>
#include <iostream>
#include "out.h"
#include "structure/form.h"
#include "structure/list_level.h"
#include "structure/op.h"
#include "structure/field.h"
#include "structure/filter_list.h"
#include "structure/comparator_list.h"

using namespace std;

static void print_string(struct field *string) {
    for (size_t iter = 0; iter < string->size; iter++) {
        printf("%c", string->value[iter]);
    }
}

static void print_operator(struct op *op, uint8_t number) {
    printf("----OPERATOR %d: ", number);
    switch (op->type){
        case STRING_TYPE:print_string(op->value.string); break;
        case INTEGER_TYPE: printf("%lld", op->value.integer); break;
        case FLOAT_TYPE: printf("%f", op->value.real); break;
        default: printf("UNKNOWN TYPE"); break;
    }
    if (op->field){ printf(" (IS FIELD)");}
    printf("\n");
}

static void print_filter(struct filter_list *list) {
    printf("-FILTERS\n");
    size_t level = 1;
    if (!list) return;
    struct comparator_list *comp_list;
    struct filter *filt_list;
    while (list) {
        printf("--FILTER: %zu\n", level++);
        printf("--IS NEGATIVE: %d\n", list->value->negative);
        size_t comp_level = 1;
        filt_list = list->value;
        comp_list = filt_list->comparators;
        if (comp_list) {
            printf("---COMPARATORS---\n");
            while (comp_list) {
                printf("----COMPARATOR: %zu\n", comp_level++);
                printf("----IS NEGATIVE: %d\n", comp_list->value->negative);
                if (comp_list->value->true_flag) {
                    printf("----COMPARATOR IS TRUE\n");
                } else {
                    print_operator(comp_list->value->op1, 1);
                    printf("----OPERATION: %c\n", comp_list->value->operation);
                    print_operator(comp_list->value->op2, 2);
                }
                printf("----END OF COMPARATOR\n");
                comp_list = comp_list->next;
            }
            printf("---END OF COMPARATORS\n");
        }
        printf("--END OF FILTER\n");
        list = list->next;
    }
    printf("-END OF FILTERS\n");
}

static void print_form(struct form *form) {
    if (!form) return;
    printf("--------------------------------\n");
    printf("OPERATION: %c\n", form->crud_operation);
    printf("--------------------------------\n");
    size_t level = 1;
    struct list_level *list = form->tree;
    while (list) {
        printf("LEVEL: %zu\n", level++);
        switch (list->place) {
            case P_FREE: printf("FREE RELATION\n"); break;
            case P_ROOT: printf("ROOT RELATION\n"); break;
            case P_RELATIVE: printf("CHILD RELATION\n"); break;
            default: printf("UNKNOWN RELATION\n"); break;
        }
        printf("IS NEGATIVE: %d\n", list->negative);
        if (list->any) {
            printf("ANY ID: *\n");
        } else {
            printf("ID: %lld\n", list->value.element);
        }
        print_filter(list->filters);
        printf("--------------------------------\n");
        list = list->next;
    }
}

static void print_error() {
    cout << "Syntax error!" << endl;
}

static void print_wtf_happened() {
    cout << "Unsupported exception!" << endl;
}

void print_result(enum states final_state, char *res_string, struct form *form) {
    if (final_state == S_ERROR && !*res_string) {
        print_form(form);
    } else if (final_state == S_ERROR) {
        print_error();
    } else {
        print_wtf_happened();
    }
}
