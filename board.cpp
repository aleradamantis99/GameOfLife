#include "cell.hpp"
#include "board.hpp"

Board::Board(size_t r, size_t c): 
	n_rows(r),
	n_cols(c),
	matrix(r*c)
{
	for (size_t i=0; i<n_rows; ++i)
	{
		for (size_t j=0; j<n_cols; ++j)
		{
			matrix[pos(i, j)] = std::make_unique<Cell>(i, j);
		}
	}
}
bool Board::is_alive_at(size_t i, size_t j) const 
{
	return (is_in_bounds(i,j))? matrix[pos(i, j)]->is_alive() : false;
}

const Cell* Board::cell_at(size_t i, size_t j) const
{
	return matrix[pos(i, j)].get();
}

void Board::round()
{
	for (auto& c: matrix)
	{
		c->count_neighbours(*this);
	}
	
	for (auto& c: matrix)
	{
		auto new_state = c->update();
		if (new_state >= 0)
		{
			replace_cell(new_state, c->row_pos(), c->col_pos());
		}
	}
}

void Board::replace_cell(int new_state, size_t i, size_t j)
{
	matrix[pos(i, j)].reset(Cell::create_cell(new_state, i, j));
}

void Board::show(std::ostream& os) const
{
	for (size_t i=0; i<n_rows; ++i)
	{
		for (size_t j=0; j<n_cols; ++j)
		{
			os << '|';
			cell_at(i, j)->show(os);
			os << '|';
		}
		os << '\n';
	}
}

void Board::show(sf::RenderWindow& win) const
{
	for (size_t i=0; i<n_rows; ++i)
	{
		for (size_t j=0; j<n_cols; ++j)
		{
			cell_at(i, j)->show(win);
		}
	}
}

Board::~Board() {}

