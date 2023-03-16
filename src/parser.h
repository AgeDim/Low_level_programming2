#ifndef LOW_LEVEL_PROGRAMMING2_PARSER_H
#define LOW_LEVEL_PROGRAMMING2_PARSER_H

#include "structure/state.h"
#include "structure/form.h"

form *parse_operation(char op_char);

states parse_state(enum states cur_state, char **string, struct list_level *level);

#endif //LOW_LEVEL_PROGRAMMING2_PARSER_H
