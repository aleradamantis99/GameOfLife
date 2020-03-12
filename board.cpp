#include "cell.hpp"
#include "board.hpp"

Board(size_t r, size_t c): 
	n_rows(r),
	n_cols(c),
	matrix(r*c)
{
	for (int i=0; i<n_rows; ++i)
	{
		for (int j=0; j<n_cols; ++j)
		{
			matrix[pos(i, j)] = std::make_unique<Cell>(i, j);
		}
	}
}
bool Board::is_alive_at(size_t i, size_t j) const 
{
	return (is_in_bounds(i,j))? matrix[pos(i, j)] : false;
}

