#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "Grid.h"

using namespace std;

int main() {
	srand(time(0));

	Grid g(40, 20);

	char keepGoing('y');

	while(keepGoing == 'y') {
		int evolutions(0);

		cout << "Evolutions ?" << endl;
		cin >> evolutions;

		g.firstGen();
		g.displayGrid();

		cout << endl << endl << endl << endl;	

		for(int i(1); i < evolutions; i++) {
			g.play();
			g.displayGrid();

			Sleep(200);
		
			cout << endl << endl << endl << endl;		
		}

		cout << "Try with a new generation ? (y/n)" << endl;
		cin >> keepGoing;
	}

	system("PAUSE");
	return 0;
}