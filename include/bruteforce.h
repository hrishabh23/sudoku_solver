#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#define INDEX 9
#include "series.h"

bool get_input(int grid[][INDEX]);
bool solved(int grid[][INDEX], short row, short column);
void assign_initial(short &row, short &column, int grid[][INDEX]);
bool go_to_previous(short &row, short &column, struct blank_unit_list** current_node, short flag);
bool is_valid(short row, short column, int grid[][INDEX]);
bool go_to_next(short &row, short &column, int grid[][INDEX],struct blank_unit_list** current_node);
void print_grid(int grid[][INDEX]);

#endif
