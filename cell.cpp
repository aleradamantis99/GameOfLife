#include "cell.hpp"
#include "tablero.hpp"

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

void Cell::count_neighbours(const Tablero& t)
{

}
