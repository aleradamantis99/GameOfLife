#include "board.hpp"
#include <iostream>
int main()
{
	Board t(3, 4);
	
	t.replace_cell(2, 1, 1);
	t.replace_cell(1, 0, 1);
	t.replace_cell(1, 1, 3);
    t.replace_cell(3, 2, 2);
    t.replace_cell(3, 2, 3);
    t.replace_cell(2, 1, 0);

	t.show(std::cout);
	std::cout << '\n';
	for (int i=0; i<5; ++i)
	{
		t.round();
		t.show(std::cout);
		std::cout << '\n';
	}
	return 0;
}
