#pragma once
#include <iostream>
class Board;

template <typename... Args>
constexpr bool eqor(size_t n, Args... args)
{
	return ((n==static_cast<size_t>(args)) || ...);
} //eqor(x, 1, 2, 3...) -> (x==1) || (x==2) || (x==3) || ...

class Cell
{

private:
	size_t n_neigh = 0;
	size_t row, col;
public:
	Cell(size_t, size_t);
	static Cell* create_cell(int tipo, size_t i, size_t j);
	virtual bool is_alive() const { return false; }
	size_t alive_neigh() const { return n_neigh; }
	virtual int update();
	virtual void show(std::ostream&) const;
	void count_neighbours(const Board&);
	
};

struct Cell1: Cell
{
	using Cell::Cell;
	
	static bool survival(size_t n) { return eqor(n, 2, 3); }
	static bool born(size_t n) { return eqor(n, 3); }
	
	bool is_alive() const override { return true; }
	int update() override;
	void show(std::ostream&) const override;
};

struct Cell2: Cell
{
	using Cell::Cell;
	
	static bool survival(size_t n) { return eqor(n, 2, 4, 5); }
	static bool born(size_t n) { return eqor(n, 3, 6, 8); }
	
	bool is_alive() const override { return true; }
	int update() override;
	void show(std::ostream&) const override;
};

struct Cell3: Cell
{
	using Cell::Cell;
	
	static bool survival(size_t n) { return eqor(n, 2, 3); }
	static bool born(size_t n) { return eqor(n, 3, 6); }
	
	bool is_alive() const override { return true; }
	int update() override;
	void show(std::ostream&) const override;
};
