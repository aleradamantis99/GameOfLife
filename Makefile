SFML = -lsfml-graphics -lsfml-window -lsfml-system
all:
	g++ -O3 -Wall -pedantic --std=c++17 *.cpp -o GOL $(SFML)
