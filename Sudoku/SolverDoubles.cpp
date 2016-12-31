#include <stdint.h>
#include "SolverSupport.h"
#include "SolverDoubles.h"
#include "Board.h"

bool removeNakedDoubles(Board &board) {
	bool removed = false;
	removed |= removeNakedDoubleRow(board);
	removed |= removeNakedDoubleColumn(board);
	removed |= removeNakedDoubleBox(board);

	return removed;
}
bool removeHiddenDoubles(Board &board) {
	bool removed = false;

	removed |= removeHiddenDoubleRow(board);
	removed |= removeHiddenDoubleColumn(board);
	removed |= removeHiddenDoubleBox(board);

	return removed;
}
bool removePointingDoubles(Board &board) {
	bool removed = false;

	removed |= removePointingDoubleRow(board);
	removed |= removePointingDoubleColumn(board);
	removed |= removePointingDoubleBox(board);

	return removed;
}

bool removeNakedDoubleRow(Board &board) {
	bool removed = false;

	for(uint8_t row = 0; row < 9; row++) {
		solverSupport.getNumberCountNaked(2, 2, row, row, 0, 8);
		solverSupport.processNumberCountIntoValueCount(2, 9);
	}
	return removed;
}
bool removeNakedDoubleColumn(Board &board) {
	bool removed = false;

	for(uint8_t column = 0; column < 9; column++) {
		solverSupport.getNumberCountNaked(2, 2, 0, 8, column, column);
		solverSupport.processNumberCountIntoValueCount(2, 9);
	}
	return removed;
}
bool removeNakedDoubleBox(Board &board) {
	bool removed = false;

	uint8_t rowMin = 0;
	uint8_t rowMax = 0;
	uint8_t columnMin = 0;
	uint8_t columnMax = 0;

	for(uint8_t row = 0; row < 3; row++) {
		for(uint8_t column = 0; column < 3; column++) {

			uint8_t rowMin = row * 3;
			uint8_t rowMax = rowMin + 2;
			uint8_t columnMin = column * 3;
			uint8_t columnMax = columnMin + 2;

			solverSupport.getNumberCountNaked(2, 2, rowMin, rowMax, columnMin, columnMax);
			solverSupport.processNumberCountIntoValueCount(2, 9);
		}
	}
	return removed;
}

bool removeHiddenDoubleRow(Board &board) {
	bool removed = false;

	for(uint8_t row = 0; row < 9; row++) {
		solverSupport.getNumberCountHidden(row, row, 0, 8);
		solverSupport.processNumberCountIntoValueCount(2, 2);
	}
	return removed;
}
bool removeHiddenDoubleColumn(Board &board) {
	bool removed = false;

	for(uint8_t column = 0; column < 9; column++) {
		solverSupport.getNumberCountHidden(0, 8, column, column);
		solverSupport.processNumberCountIntoValueCount(2, 2);
	}
	return removed;
}
bool removeHiddenDoubleBox(Board &board) {
	bool removed = false;

	uint8_t rowMin = 0;
	uint8_t rowMax = 0;
	uint8_t columnMin = 0;
	uint8_t columnMax = 0;

	for(uint8_t row = 0; row < 3; row++) {
		for(uint8_t column = 0; column < 3; column++) {

			uint8_t rowMin = row * 3;
			uint8_t rowMax = rowMin + 2;
			uint8_t columnMin = column * 3;
			uint8_t columnMax = columnMin + 2;

			solverSupport.getNumberCountHidden(rowMin, rowMax, columnMin, columnMax);
			solverSupport.processNumberCountIntoValueCount(2, 2);
		}
	}
	return removed;
}

bool removePointingDoubleRow(Board &board) {
	return false;
}
bool removePointingDoubleColumn(Board &board) {
	return false;
}
bool removePointingDoubleBox(Board &board) {
	return false;
}

