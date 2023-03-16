#include <cstddef>
#include <iostream>
#include "out.h"
#include "../structure/form.h"
#include "../structure/list_level.h"

using namespace std;

static void print_string(struct field *string) {
    for (size_t iter = 0; iter < string->size; iter++) {
        printf("%c", string->value[iter]);
    }
}

static void print_operator(struct op *op, uint8_t number) {
    printf("----OPERATOR %d: ", number);
    switch (op->type) {
        case STRING_TYPE:
            print_string(op->value.string);
            break;
        case INTEGER_TYPE:
            printf("%lld", op->value.integer);
            break;
        case FLOAT_TYPE:
            printf("%f", op->value.real);
            break;
        default:
            printf("UNKNOWN TYPE");
            break;
    }
    if (op->field) { printf(" (IS FIELD)"); }
    printf("\n");
}

static void print_filter(struct filter_list *list) {
    printf("-FILTERS\n");
    size_t level = 1;
    if (!list) return;
    struct comparator_list *comp_list;
    struct filter *filt_list;
    while (list) {
        cout << "--FILTER: " << level++ << endl;
        printf("--IS NEGATIVE: %d\n", list->value->negative);
        size_t comp_level = 1;
        filt_list = list->value;
        comp_list = filt_list->comparators;
        if (comp_list) {
            cout << "---COMPARATORS---" << endl;
            while (comp_list) {
                printf("----COMPARATOR: %zu\n", comp_level++);
                printf("----IS NEGATIVE: %d\n", comp_list->value->negative);
                if (comp_list->value->true_flag) {
                    cout << "----COMPARATOR IS TRUE " << endl;
                } else {
                    print_operator(comp_list->value->op1, 1);
                    printf("----OPERATION: %c\n", comp_list->value->operation);
                    print_operator(comp_list->value->op2, 2);
                }
                cout << "----END OF COMPARATOR " << endl;
                comp_list = comp_list->next;
            }
            cout << "---END OF COMPARATORS" << endl;
        }
        cout << "--END OF FILTER" << endl;
        list = list->next;
    }
    cout << "-END OF FILTERS" << endl;
}

static void print_form(struct form *form) {
    if (!form) return;
    cout << "--------------------------------" << endl;
    printf("OPERATION: %c\n", form->crud_operation);
    cout << "--------------------------------" << endl;
    size_t level = 1;
    struct list_level *list = form->tree;
    while (list) {
        cout << "LEVEL: " << level++ << endl;
        switch (list->place) {
            case P_FREE:
                cout << "FREE RELATION" << endl;
                break;
            case P_ROOT:
                cout << "ROOT RELATION" << endl;
                break;
            case P_RELATIVE:
                cout << "CHILD RELATION" << endl;
                break;
            default:
                cout << "UNKNOWN RELATION" << endl;
                break;
        }
        printf("IS NEGATIVE: %d\n", list->negative);
        if (list->any) {
            cout << "ANY ID: *" << endl;
        } else {
            cout << "ID: " << list->value.element << endl;
        }
        print_filter(list->filters);
        cout << "--------------------------------" << endl;
        list = list->next;
    }
}

static void print_error() {
    cout << "Syntax error!" << endl;
}

static void print_unsupp() {
    cout << "Unsupported exception!" << endl;
}

void print_result(enum states final_state, char *res_string, struct form *form) {
    if (final_state == S_ERROR && !*res_string) {
        print_form(form);
    } else if (final_state == S_ERROR) {
        print_error();
    } else {
        print_unsupp();
    }
}
