#include "SolverSupport.h"

SolverSupport solverSupport = SolverSupport();

// Structs to hold info for support class

NumberLocationCount::NumberLocationCount() {
	for(uint8_t i = 0; i < WIDTH; i++) {
		location[i].row = 0;
		location[i].column = 0;
	}
	count = 0;
}
ValueLocationCount::ValueLocationCount() {
	for(uint8_t i = 0; i < WIDTH; i++) {
		location[i].row = 0;
		location[i].column = 0;
	}
	value = 0;
	count = 0;
}

// Constructor

SolverSupport::SolverSupport(Board &inputBoard) {
	board = inputBoard;
}
SolverSupport::SolverSupport() {

}

// Private functions to help with public functions

void SolverSupport::clearNumberCount() { 
	for(uint8_t numberIndex = 0; numberIndex < 9; numberIndex++) {
		numberCount[numberIndex].count = 0;
		for(uint8_t locationIndex = 0; locationIndex < 9; locationIndex++) {
			numberCount[numberIndex].location[locationIndex].row = 0;
			numberCount[numberIndex].location[locationIndex].column = 0;
		}
	}
}
void SolverSupport::clearValueCount() { 
	for(uint8_t numberIndex = 0; numberIndex < 9; numberIndex++) {
		valueCount[numberIndex].count = 0;
		valueCount[numberIndex].value = 0;
		for(uint8_t locationIndex = 0; locationIndex < 9; locationIndex++) {
			valueCount[numberIndex].location[locationIndex].row = 0;
			valueCount[numberIndex].location[locationIndex].column = 0;
		}
	}
}
void SolverSupport::processPossibleValuesToNumberCount(uint8_t row, uint8_t column) {
	// Get all possible values at location
	uint8_t value = 0;
	uint8_t locationIndex = 0;
	board.board[row][column].getPossibleValuesArray(possibleValues);

	//Iterate over every possible value at the selected location
	for(uint8_t i = 0; i < 9; i++) {
		if(possibleValues[i] != 0) {
			value = possibleValues[i];
			locationIndex = numberCount[value - 1].count;
			numberCount[value - 1].count += 1;
			numberCount[value - 1].location[locationIndex].row = row;
			numberCount[value - 1].location[locationIndex].column = column;
		}
	}
}

// Public functions to help solve sudoku board

void SolverSupport::setBoard(Board &inputBoard) {
	board = inputBoard;
}
void SolverSupport::getNumberCountHidden(uint8_t rowMin, uint8_t rowMax,  uint8_t columnMin, uint8_t columnMax) {

	clearNumberCount();

	// Iterate over every row and column requested
	for(uint8_t row = rowMin; row <= rowMax; row++) {
		for(uint8_t column = columnMin; column <= columnMax; column++) {
			processPossibleValuesToNumberCount(row, column);
		}
	}
}
void SolverSupport::getNumberCountNaked(uint8_t possibleValuesMin, uint8_t possibleValuesMax, uint8_t rowMin, uint8_t rowMax,  uint8_t columnMin, uint8_t columnMax) {
	
	clearNumberCount();

	// Iterate over every row and column requested
	for(uint8_t row = rowMin; row <= rowMax; row++) {
		for(uint8_t column = columnMin; column <= columnMax; column++) {

			uint8_t numberPossibleValues = board.board[row][column].numberPossibleValues();

			if((numberPossibleValues >= possibleValuesMin) && (numberPossibleValues <= possibleValuesMax)) {
				processPossibleValuesToNumberCount(row, column);
			}
		}
	}
}
void SolverSupport::processNumberCountIntoValueCount(uint8_t countMin, uint8_t countMax) {
	clearValueCount();

	uint8_t index = 0;

	for(uint8_t value = 1; value <= 9; value++) {
		if((numberCount[value - 1].count >= countMin) && (numberCount[value - 1].count <= countMax)) {
			valueCount[index].value = value;
			valueCount[index].count = numberCount[value].count;
			for(uint8_t i = 0; i < 9; i++) {
				valueCount[index].location[i] = numberCount[value - 1].location[i];
			}
			index++;
		}
	}
}