#include "Cell.h"
#include <iostream>

using namespace std;

Cell::Cell() {
	m_status = CellStatus::Dead;
}

CellStatus Cell::getStatus() const {
	return m_status;
}

/**
 * @desc Faire vivre la cellule lors de la prochaine g�n�ration
 */
void Cell::awake() {
	m_status = CellStatus::DeadAwakening;
}

/**
 * @desc Tuer la cellule lors de la prochaine gen
 */
void Cell::kill() {
	m_status = CellStatus::AliveDying;
}

/**
 * @desc Met � jour la cellule (appel � chaque nouvelle g�n�ration)
 */
void Cell::refresh() {
	if(m_status == CellStatus::AliveDying)
		m_status = CellStatus::Dead;
	else if(m_status == CellStatus::DeadAwakening) 
		m_status = CellStatus::Alive;
}