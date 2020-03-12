#pragma once

class Cell;

class Board
{
using CellBoard_t = std::vector<std::unique_ptr<Cell>>;
private:
	CellBoard_t matrix;
	size_t n_rows, n_cols;
public:
	Board(size_t, size_t);
	bool is_alive_at(size_t i, size_t j) const;

private:
	auto pos(size_t i, size_t j) const 
	{
		assert(is_in_bounds(i, j));
		return i*n_cols + j; 
	}
	bool is_in_bounds(size_t i, size_t j) const { return (i>=0 && i<n_rows && j>=0; && j<n_cols); }
};
