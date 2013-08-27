#ifndef HEADER_CELL
#define HEADER_CELL

enum CellStatus { Alive, Dead, AliveDying, DeadAwakening };

class Cell {
	public:
		Cell();

		CellStatus getStatus() const;

		void awake();
		void kill();
		void refresh();
	protected:
		CellStatus m_status;
};

#endif