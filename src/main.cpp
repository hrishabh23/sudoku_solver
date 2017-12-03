#include<iostream>
#include"bruteforce.h"
#include"series.h"

#define INDEX 9

int main()
{
	int grid[INDEX][INDEX];
	short x, y, z=0;
	struct blank_unit_list *current_node, *temp;
	get_input(grid);
	assign_initial(x, y, grid);
	current_node = new struct blank_unit_list;
	current_node->row=x;
	current_node->column=y;
	current_node->previous=NULL;
	
	while(not_solved(grid))
	{
		z=0;
		if(grid[x][y]==9)
		{
			grid[x][y]=0;
			go_to_previous(x, y, &current_node);
			continue;
		}
			grid[x][y]++;
			
		if(is_valid(x, y, grid))
		{
			go_to_next(x, y, grid, &current_node);
		
		}
		//std::cin>>z;
		/*temp=current_node;
		while(temp->previous!=NULL)
			{
				std::cout<<temp->row<<", "<<temp->column<<std::endl;
				temp=temp->previous;
			}
			std::cout<<temp->row<<", "<<temp->column<<std::endl<<std::endl;*/
	}
	
	print_grid(grid);
	return 0;
}
