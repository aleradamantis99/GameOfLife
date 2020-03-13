#pragma once
#include <vector>
#include <memory>
#include <cassert>
class Cell;

class Board
{
private:
	using CellBoard_t = std::vector<std::unique_ptr<Cell>>;
	size_t n_rows, n_cols;
	CellBoard_t matrix;
	
	auto pos(size_t i, size_t j) const 
	{
		assert(is_in_bounds(i, j));
		return i*n_cols + j; 
	}
	bool is_in_bounds(size_t i, size_t j) const { return (i>=0 && i<n_rows && j>=0 && j<n_cols); }
	
public:
	Board(size_t, size_t);
	bool is_alive_at(size_t i, size_t j) const;
	const Cell* cell_at(size_t i, size_t j) const;
	void round();
	void replace_cell(int new_state, size_t i, size_t j);
	void show(std::ostream&) const;
	~Board(); //Needed in order to use unique_ptr
	
};
