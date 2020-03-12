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

struct Condition
{
	std::function<bool(size_t)> surv;
	std::function<bool(size_t)> born;
};



std::array<Condition, 3> conditions = 
{
	Condition
	{
		[](size_t n) { return eqor(n, 2, 3); },
		[](size_t n) { return n == 3; }
	},
	Condition
	{						  
		[](size_t n) { return eqor(n, 2, 4, 5); },
		[](size_t n) { return eqor(n, 3, 6, 8); }
	},
	Condition
	{
		[](size_t n) { return eqor(n, 2, 3); },
		[](size_t n) { return eqor(n, 3, 6); }
	}
};

int Cell::update()
{
	if (conditions[0].born(n_neigh)) // 3/23
	{
		return 1;
	}
	
	if (conditions[1].born(n_neigh)) // 368/245
	{
		return 2;
	}
	
	if (conditions[1].born(n_neigh)) // 36/23
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
