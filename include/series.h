#ifndef SERIES_H
#define SERIES_H

struct blank_unit_list
{
	short row;
	short column;
	struct blank_unit_list* previous;
};

#endif
