#include "board.hpp"
#include "cell.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
int main(int argc, char* argv[])
{
	bool stepped = argc > 1;
	Cell::radius = 2.f;
	unsigned width = 1000, height = 600;
	size_t cols = height/(2*Cell::radius), rows = width/(2*Cell::radius);
	Board t(rows, cols);
	//Cell::radius = std::min(width/rows, height/cols)/2;
	srand(time(nullptr));
	
	auto num_cells = rows*cols;
	std::array<double, 3> probs { 0.01, 0.3, 0.3 };
	auto num_cells_alive = num_cells*(probs[0]+probs[1]+probs[3]);
	std::vector<int> v(num_cells, 0);
	int current_index = 0;
	for (int i=0; i<=2; ++i)
	{
		for (int j=0; j<num_cells*probs[i]; ++j)
		{
			v.at(current_index++) = i+1;
		}
	}
	std::default_random_engine eng{std::random_device {}()};
	std::shuffle (v.begin(), v.end(), eng);
	for (size_t i=0; i<rows; ++i)
	{
		for (size_t j=0; j<cols; ++j)
		{
			
			t.replace_cell(v[i*cols+j], i, j);
		}
	}
	/*
	for (size_t i=0; i<rows; ++i)
	{
		for (size_t j=0; j<cols; ++j)
		{
			int chosen = rand()%6;
			
			chosen = chosen <= 3? chosen:0;
			t.replace_cell(chosen, i, j);
		}
	}*/
	/*
	t.replace_cell(2, 1, 1);
	t.replace_cell(1, 0, 1);
	t.replace_cell(1, 1, 3);
    t.replace_cell(3, 2, 2);
    t.replace_cell(3, 2, 3);
    t.replace_cell(2, 1, 0);
	*/
	
	//t.show(std::cout);
	std::cout << '\n';
	
	sf::RenderWindow window(sf::VideoMode(width, height), "Game Of Life");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed)
            {
            	if (event.key.code == sf::Keyboard::Space)
            	{
            		if (stepped)
            		{
            			t.round();
            		}
            	}
            	else //if (event.key.code == sf::Keyboard::Escape)
            	{
            		window.close();
            	}
            }
        }
        
        window.clear();
        if (not stepped)
        {
        	t.round();
        }
	   	t.show(window);
		window.display();
    }

    return 0;
	/*for (int i=0; i<5; ++i)
	{
		t.round();
		t.show(std::cout);
		std::cout << '\n';
	}
	return 0;*/
}
