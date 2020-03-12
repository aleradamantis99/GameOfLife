#include "cell.hpp"
#include "board.hpp"

#include <functional>
/**********
*BASE CELL*
***********/

Cell* Cell::create_cell(int tipo, size_t i, size_t j)
{
	switch (tipo)
	{
	case 1:
		return new Cell1(i, j);
	case 2:
		return new Cell2(i, j);
	case 3:
		return new Cell3(i, j);
	default:
		return new Cell(i, j);
	}
}

Cell::Cell(size_t i, size_t j): row(i), col(j) {}

int Cell::update()
{
	if (Cell1::born(alive_neigh()))
	{
		return 1;
	}
	
	if (Cell2::born(alive_neigh()))
	{
		return 2;
	}
	
	if (Cell3::born(alive_neigh()))
	{
		return 3;
	}
	
	return 0;
}

void Cell::show(std::ostream& os) const
{
	os << ' ';
}

void Cell::count_neighbours(const Board& t)
{
	n_neigh = 0;
	for (size_t i = row-1; i<=row+1; ++i)
	{
		for (size_t j = col-1; j<=col+1; ++j)
		{
			if (t.is_alive_at(i, j))
			{
				++n_neigh;
			}
		}
	}
	
	if (is_alive())
	{
		--n_neigh;
	}
}

/******
*CELL1*
******/
int Cell1::update()
{
	if(survival(alive_neigh()))
	{
		return 0;
	}
	
	return 1;
}

void Cell1::show(std::ostream& os) const
{
	os << '1';
}

/******
*CELL2*
******/
int Cell2::update()
{
	if(survival(alive_neigh()))
	{
		return 0;
	}
	
	return 2;
}

void Cell2::show(std::ostream& os) const
{
	os << '2';
}

/******
*CELL3*
******/
int Cell3::update()
{
	if(survival(alive_neigh()))
	{
		return 0;
	}
	
	return 3;
}

void Cell3::show(std::ostream& os) const
{
	os << '3';
}
