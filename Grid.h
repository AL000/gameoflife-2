#ifndef HEADER_GRID
#define HEADER_GRID

#include "Cell.h"
#include <vector>

class Grid {
	public:
		Grid(int width, int height);
		~Grid();

		void firstGen();
		void play();

		void displayGrid();

	private:
		void generateGrid();
		int nbNeighboursAlive(int j, int i);
		int posAlive(int x, int y);

		int m_width;
		int m_height;
		std::vector<std::vector<Cell*>> grid;
};

#endif