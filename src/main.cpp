#include<iostream>
#include<cstdio>
#include"bruteforce.h"
#include"series.h"

#define INDEX 9

int main()
{
	int grid[INDEX][INDEX];
	short x, y, flag=0;
	struct blank_unit_list *current_node;
	while(!get_input(grid));
	assign_initial(x, y, grid);
	current_node = new struct blank_unit_list;
	current_node->row=x;
	current_node->column=y;
	current_node->previous=NULL;
	
	while(1)
	{
		if(grid[x][y]==9)
		{
			grid[x][y]=0;
			if(!go_to_previous(x, y, &current_node))
			{
				break;
			}
			continue;
		}
		
		grid[x][y]++;
				
		if(solved(grid, x, y))
		{
			if(flag>10)
			{
				std::cout<<"There are more than 10 Solutions for this puzzles. Hence, the process is going to be stopped!"<<std::endl;
				return 0;
			}
			if(flag==1)
			{
				std::cout<<"There are multiple solutions for the puzzle."<<std::endl;
				std::cout<<"Press <return> to continue...";
				getchar();
			}
			print_grid(grid);
			flag++;
			
		}

			
		if(is_valid(x, y, grid))
		{
			go_to_next(x, y, grid, &current_node);
		
		}
	}
	return 0;
}
