#include "Grid.h"
#include <iostream>

using namespace std;

Grid::Grid(int width, int height) : m_width(width), m_height(height) {
	// Conversion du vector en vector multi-dimmensionnel
	grid.resize(m_width);

	for(int i(0); i < m_width; i++) {
		grid[i].resize(m_height);
	}

	// Génération de la grille
	generateGrid();
}

Grid::~Grid() {
	// Désallocation...
	for(int i(0); i < m_height; i++) {
		for(int j(0); j < m_width; j++) {
			delete grid[j][i];
			grid[j][i] = 0;
		}
	}
}

/**
 * @desc Génération de la grille
 * @private
 */
void Grid::generateGrid() {
	for(int i(0); i < m_height; i++) {
		for(int j(0); j < m_width; j++) {
			grid[j][i] = new Cell;
		}
	}
}

/**
 * @desc Création de la première génération (probabilité 1/2)
 */
void Grid::firstGen() {
	for(int i(0); i < m_height; i++) {
		for(int j(0); j < m_width; j++) {
			if(rand() % 2 == 0) {
				grid[j][i]->awake();
			} else {
				grid[j][i]->kill();
			}
		}
	}
}

/**
 * @desc Gestion de la prochaine génération
 */
void Grid::play() {
	for(int i(0); i < m_height; i++) {
		for(int j(0); j < m_width; j++) {
			// Cellule morte
			if(grid[j][i]->getStatus() == Dead) {
				int alive = nbNeighboursAlive(j, i);

				if(alive == 3)
					grid[j][i]->awake();
			} else if(grid[j][i]->getStatus() == Alive) {
				//Cellule vivante
				int alive = nbNeighboursAlive(j, i);

				if(alive < 2 || alive > 3)
					grid[j][i]->kill();
			}
		}
	}	
}

/**
 * @desc Affichage de la grille
 */
void Grid::displayGrid() {
	for(int i(0); i < m_height; i++) {
		for(int j(0); j < m_width; j++) {
			grid[j][i]->refresh();

			if(grid[j][i]->getStatus() == Alive) {
				cout << "O";
			} else {
				cout << "=";
			}
		}

		cout << endl;
	}	
}

/**
 * @desc Récupération du nombre de cellules voisines à partir de la position j, i
 * @private
 */
int Grid::nbNeighboursAlive(int j, int i) {
	int a(0);

	a += posAlive(j - 1, i - 1); //Top left
	a += posAlive(j, i - 1); //Top
	a += posAlive(j + 1, i - 1); //Top right
	a += posAlive(j - 1, i); //Left
	a += posAlive(j + 1, i); //Right
	a += posAlive(j - 1, i + 1); //Bottom left
	a += posAlive(j, i + 1); //Bottom
	a += posAlive(j + 1, i + 1); //Bottom right

	return a;
}

/**
 * @desc Vérifie si la cellule est vivante tout en gérant les dimensions de la grille (bords, ect...)
 * @private
 */
int Grid::posAlive(int x, int y) {
	return (x >= 0 && y >= 0 && x <= m_width - 1 && y <= m_height - 1 && grid[x][y]->getStatus() == Alive ? 1 : 0);
}