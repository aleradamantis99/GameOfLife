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
	
	return -1;
}

void Cell::show(std::ostream& os) const
{
	os << represent();
}

void Cell::count_neighbours(const Board& t)
{
	n_neigh = 0;
    for (int i = -1; i<=1; ++i)
    {
        for (int j = -1; j<=1; ++j)
		{
            if (t.is_alive_at(row+i, col+j))
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
    if(not survival(alive_neigh()))
	{
		return 0;
	}
	
	return -1;
}

/******
*CELL2*
******/
int Cell2::update()
{
    if(not survival(alive_neigh()))
	{
		return 0;
	}
	
	return -1;
}

/******
*CELL3*
******/
int Cell3::update()
{
    if(not survival(alive_neigh()))
	{
		return 0;
	}
	
	return -1;
}

