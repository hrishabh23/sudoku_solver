#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#define INDEX 9
#include "series.h"

void get_input(int grid[][INDEX]);
bool not_solved(int grid[][INDEX]);
void assign_initial(short &row, short &column, int grid[][INDEX]);
void go_to_previous(short &row, short &column, struct blank_unit_list** current_node);
bool is_valid(short &row, short &column, int grid[][INDEX]);
void go_to_next(short &row, short &column, int grid[][INDEX],struct blank_unit_list** current_node);
void print_grid(int grid[][INDEX]);

#endif
