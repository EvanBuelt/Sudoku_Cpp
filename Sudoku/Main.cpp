#include <iostream>
#include "Board.h"
#include "Solver.h"

int main() {
	uint8_t easyInputBoard[9][9] = {{5, 3, 7, 0, 6, 9, 0, 0, 4},
									{0, 0, 0, 0, 7, 0, 0, 6, 0},
									{6, 0, 8, 0, 4, 3, 9, 2, 0},
									{0, 9, 0, 0, 0, 1, 0, 0, 2},
									{0, 0, 1, 0, 0, 5, 0, 0, 3},
									{2, 0, 0, 4, 0, 0, 0, 9, 0},
									{8, 6, 0, 7, 5, 0, 1, 0, 9},
									{0, 0, 0, 8, 0, 0, 4, 0, 0},
									{4, 5, 9, 0, 0, 6, 2, 0, 8}};

	uint8_t mediumInputBoard[9][9] = {{1, 0, 0, 0, 0, 5, 0, 0, 4},
									  {0, 2, 3, 4, 0, 6, 0, 5, 0},
									  {0, 0, 0, 0, 0, 0, 0, 6, 0},
									  {9, 0, 0, 0, 0, 0, 0, 7, 0},
									  {0, 0, 0, 5, 6, 7, 0, 0, 0},
									  {0, 5, 0, 0, 0, 0, 8, 0, 3},
									  {0, 4, 0, 0, 0, 0, 0, 0, 0},
									  {0, 3, 0, 7, 0, 1, 9, 8, 0},
									  {2, 0, 0, 8, 0, 0, 0, 0, 7}};

	Board easyBoard = Board(easyInputBoard);
	Board mediumBoard = Board(mediumInputBoard);

	std::cout << "Initial Easy Board: " << "\n\n";

	for(int row = 0; row < 9; row++) {
		for(int column = 0;column < 9; column++) {
			int displayValue = (int) mediumBoard.getValue(row, column);
			std::cout << displayValue;
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	ElegantSolver easySolver = ElegantSolver(easyBoard);
	ElegantSolver mediumSolver = ElegantSolver(easyBoard);

	easySolver.solve();
	mediumSolver.solve();

	std::cout << "Final Easy Board: " << "\n\n";

	for(int row = 0; row < 9; row++) {
		for(int column = 0;column < 9; column++) {
			int displayValue = (int) mediumBoard.getValue(row, column);
			std::cout << displayValue;
		}
		std::cout << "\n";
	}

	char i;
	std::cin >> i;

	return 1;
}