#include "cell.hpp"
#include "board.hpp"

/**********
*BASE CELL*
***********/

Cell::Cell(size_t i, size_t j): row(i), col(j) {}

int Cell::update()
{
	if (true/*Condicion nacimiento 1*/)
	{
		return 1;
	}
	
	if (true/*Condicion nacimiento 2*/)
	{
		return 2;
	}
	
	if (true/*Condicion nacimiento 3*/)
	{
		return 2;
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
	if(true /*superv*/)
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
	if(true /*superv*/)
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
	if(true /*superv*/)
	{
		return 0;
	}
	
	return 3;
}

void Cell3::show(std::ostream& os) const
{
	os << '3';
}
