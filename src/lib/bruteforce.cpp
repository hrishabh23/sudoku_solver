#include <iostream>
#include<fstream>
#include "series.h"

#define INDEX 9

void get_input(int grid[][INDEX])
{
	int row[INDEX], row_index = 0, column_index = 0, select=0;
	std::cout<<"Press 1 to Enter the Sudoku puzzle manually:"<<std::endl;
	std::cout<<"Press 2 to Enter the Sudoku puzzle stored in .txt file"<<std::endl;
	std::cin>>select;
	
	switch(select)
	{
		case 2:
		{
			std::ifstream puzzle_file;
			puzzle_file.open("puzzle.txt");
			
			for(row_index=0 ; row_index < INDEX ; row_index++)
			{
				puzzle_file>>row[row_index];
			}		
			puzzle_file.close();
		}
			
		case 1:
			if(select==1)
				for(row_index = 0 ; row_index < INDEX ; row_index++)
				{
					std::cin >> row[row_index];
				}
	
			for(row_index = 0 ; row_index < INDEX ; row_index++)
			{
				for(column_index = INDEX-1 ; column_index >= 0 ; column_index--)
				{
					grid[row_index][column_index] = row[row_index]%10;
					row[row_index] /= 10;
				}
			}
			break;
	}
}

void assign_initial(short &row, short &column, int grid[][INDEX])
{
	short row_index, column_index;
	for(row_index = 0 ; row_index < INDEX ; row_index++)
		for(column_index = 0 ; column_index < INDEX ; column_index++)
		{
			if(!grid[row_index][column_index])
			{
				row = row_index;
				column = column_index;
				return;
			}
		}
}

void go_to_previous(short &row, short &column, struct blank_unit_list** current_node)
{
	//std::cout<<"Went previous"<<std::endl;
	//struct blank_unit_list* temp = current_node;
	(*current_node) = (*current_node)->previous;
	//delete temp;
	row = (*current_node)->row;
	column = (*current_node)->column;
	//std::cout<<row<<", "<<column<<std::endl;
}

bool is_valid(short &row, short &column, int grid[][INDEX])
{
	short row_index, column_index;
	short block_row_index = 3*(row/3), block_column_index = 3*(column/3);
	
	//Checking for filled number in respective column
	for(row_index = 0 ; row_index < INDEX ; row_index++)
	{
		if(grid[row_index][column]==grid[row][column]&&row_index!=row) return false;
	}
	
	//Checking for filled number in respective row
	for(column_index = 0 ; column_index < INDEX ; column_index++)
	{
		if(grid[row][column_index]==grid[row][column]&&column_index!=column) return false;
	}
	
	//Checking for filled number in respective block
	for(block_row_index = 3*(row/3) ; block_row_index <= 3*(row/3)+2 ; block_row_index++)
		for(block_column_index = 3*(column/3) ; block_column_index <= 3*(column/3)+2 ; block_column_index++)
		{
			if(grid[block_row_index][block_column_index]==grid[row][column]&&block_row_index!=row) return false;
		}
		
	return true;
}

bool not_solved(int grid[][INDEX])
{
	int row_index, column_index;
	short eight=8;
	
	for(row_index = 0 ; row_index < INDEX ; row_index++)
	{
		for(column_index = 0 ; column_index < INDEX ; column_index++)
		{
			if(!grid[row_index][column_index]) return true;
		}
	}
	if(is_valid(eight, eight, grid))
	return false;
	return true;
}


void go_to_next(short &row, short &column, int grid[][INDEX], struct blank_unit_list** current_node)
{
	short row_index = (column!=8)?row:row+1, column_index;
	for(column_index = (column!=8)?(column + 1):0 ; row_index < INDEX; column_index++)
	{
		if(column_index==9)
		{
			column_index=0;
			row_index++;
		}
		if(row_index==9) return;
		
		if(!grid[row_index][column_index])
		{
			row = row_index;
			column = column_index;
			
			struct blank_unit_list* next_node = new struct blank_unit_list;
			next_node->row = row;
			next_node->column = column;
			next_node->previous = (*current_node);
			(*current_node) = next_node;
			return;
		}
	}
}

void print_grid(int grid[][INDEX])
{
	int row_index, column_index;
	std::cout<<"The Solution:"<<std::endl;
	std::cout<<"-------------------------"<<std::endl;
	for (row_index = 0 ; row_index < INDEX ; row_index++)
	{
		if (row_index%3 ==0 && row_index!=0) std::cout<<"--------+-------+--------"<<std::endl;
		std::cout<<"| ";
		for(column_index = 0 ; column_index < INDEX ; column_index++)
		{
			std::cout << grid[row_index][column_index]<<" ";
			if(column_index%3 == 2) std::cout<<"| ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"-------------------------"<<std::endl;
}
