#pragma once
#include <iostream>
class Tablero;

class Cell
{
private:
	size_t n_neigh = 0;
	size_t row, col;
public:
	Cell(size_t, size_t);
	static Cell* create_cell(int tipo, int i, int j);
	virtual bool is_alive() const { return false; }
	virtual int update();
	virtual void show(std::ostream&) const;
	void count_neighbours(const Tablero&);
	
};

struct Cell1: Cell
{
	using Cell::Cell;
	bool is_alive() const override { return true; }
	virtual int update();
	void show(std::ostream&) const override;
};

struct Cell2: Cell
{
	using Cell::Cell;
	bool is_alive() const override { return true; }
	virtual int update();
	void show(std::ostream&) const override;
};

struct Cell3: Cell
{
	using Cell::Cell;
	bool is_alive() const override { return true; }
	virtual int update();
	void show(std::ostream&) const override;
};
