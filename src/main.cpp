#include <iostream>
#include "parser.h"
#include "structure/list_level.h"
#include "out/out.h"

#define MAX_COMMAND_SIZE 1024

using namespace std;

int main(){
    char command[MAX_COMMAND_SIZE], *for_parse;
    enum states current_state;
    cin >> command;
    for_parse = command + 1;
    struct form *form = parse_operation(command[0]);
    struct list_level *cur_level = new list_level(0, 0 ,P_ROOT);
    if (*for_parse == '/'){
        current_state = S_NEXT;
    } else if (*for_parse){
        cur_level->place = P_FREE;
        command[0] = '/';
        for_parse = command;
        current_state = S_NEXT;
    } else {
        for_parse = command;
        current_state = S_ERROR;
    }
    while (for_parse && current_state != S_ERROR) {
        current_state = parse_state(current_state, &for_parse, cur_level);
        if (current_state == S_NEXT && *for_parse) {
            cur_level->next = form->tree;
            form->tree = cur_level;
            cur_level = new struct list_level(0, 0, P_RELATIVE);
        }
    }
    if (cur_level) {
        cur_level->next = form->tree;
        form->tree = cur_level;
    }
    print_result(current_state, for_parse, form);
    return 0;
}