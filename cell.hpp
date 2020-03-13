#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
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
	static float radius;
	Cell(size_t, size_t);
	static Cell* create_cell(int tipo, size_t i, size_t j);
	virtual bool is_alive() const { return false; }
	auto alive_neigh() const { return n_neigh; }
	virtual int update();
	virtual void show(std::ostream&) const;
	virtual void show(sf::RenderWindow&) const;
	void count_neighbours(const Board&);
	
	virtual char represent() const { return ' '; }
	virtual sf::Color color() const { return sf::Color::Black; }
	
	auto row_pos() const { return row; }
	auto col_pos() const { return col; }
};



struct Cell1: Cell
{
	using Cell::Cell;
	
	static bool survival(size_t n) { return eqor(n, 2, 3); }
	static bool born(size_t n) { return eqor(n, 3); }
	
	char represent() const override { return '1'; }
	sf::Color color() const override { return sf::Color::Green; }
	
	bool is_alive() const override { return true; }
	int update() override;
};

struct Cell2: Cell
{
	using Cell::Cell;
	
	static bool survival(size_t n) { return eqor(n, 2, 4, 5); }
	static bool born(size_t n) { return eqor(n, 3, 6, 8); }
	
	char represent() const override { return '2'; }
	sf::Color color() const override { return sf::Color::Red; }
		
	bool is_alive() const override { return true; }
	int update() override;
};
struct Cell3: Cell
{
	using Cell::Cell;
		
	static bool survival(size_t n) { return eqor(n, 2, 3); }
	static bool born(size_t n) { return eqor(n, 3, 6); }

	char represent() const override { return '3'; }
	sf::Color color() const override { return sf::Color::Blue; }
	
	bool is_alive() const override { return true; }
	int update() override;
};
