#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Sudoku\Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
class Cell {
	// Size of data in Cell is 3 Bytes.
public:
	uint8_t value;
	uint16_t possible_values;

	Cell();
	Cell(uint8_t);

	void setValue(uint8_t);
	uint8_t getValue();

	bool isPossibleValue(uint8_t);
	uint8_t numberPossibleValues();
	void getPossibleValues(uint8_t*);
	void setPossibleValue(uint8_t);
	void clearPossibleValue(uint8_t);
*/
namespace SudokuTests
{
	TEST_CLASS(CellTests)
	{
	public:
		// Test getValue method
		TEST_METHOD(Unit_Test_Cell_getValue_With_Blank_Constructor)
		{
			// Verifies possible values given a constructor with no arguments, which should to default to a value of 0.
			Cell blankCell = Cell();
			uint8_t expectedValue = 0;

			Assert::AreEqual(expectedValue, blankCell.getValue());
		}
		TEST_METHOD(Unit_Test_Cell_getValue_With_Non_Zero_Value)
		{
			// Verifies possible values given a constructor with no arguments, which should to default to a value of 0.
			Cell blankCell = Cell(4);
			uint8_t expectedValue = 4;

			Assert::AreEqual(expectedValue, blankCell.getValue());
		}
		TEST_METHOD(Unit_Test_Cell_getValue_With_Out_Of_Range_Value)
		{
			// Verifies possible values given a constructor with no arguments, which should to default to a value of 0.
			Cell blankCell = Cell(10);
			uint8_t expectedValue = 0;

			Assert::AreEqual(expectedValue, blankCell.getValue());
		}

		// Test isPossibleValue method
		TEST_METHOD(Unit_Test_Cell_isPossibleValue_With_Blank_Constructor)
		{
			// Verifies possible values given a constructor with no arguments, which should to default to a value of 0.
			Cell blankCell = Cell();

			Assert::IsFalse(blankCell.isPossibleValue(0));
			Assert::IsTrue(blankCell.isPossibleValue(1));
			Assert::IsTrue(blankCell.isPossibleValue(4));
			Assert::IsTrue(blankCell.isPossibleValue(9));
			Assert::IsFalse(blankCell.isPossibleValue(10));
		}
		TEST_METHOD(Unit_Test_Cell_isPossibleValue_With_Zero_Value_Constructor)
		{
			// Verifies possible values given a cell value of 0. 
			Cell zeroCell = Cell(0);

			Assert::IsFalse(zeroCell.isPossibleValue(0));
			Assert::IsTrue(zeroCell.isPossibleValue(1));
			Assert::IsTrue(zeroCell.isPossibleValue(4));
			Assert::IsTrue(zeroCell.isPossibleValue(9));
			Assert::IsFalse(zeroCell.isPossibleValue(10));
		}
		TEST_METHOD(Unit_Test_Cell_isPossibleValue_With_Non_Zero_Value_Constructor)
		{
			// Verifies possible values are set to false if a non-zero value is given in the constructor.
			Cell valueCell = Cell(5);

			Assert::IsFalse(valueCell.isPossibleValue(0));
			Assert::IsFalse(valueCell.isPossibleValue(1));
			Assert::IsFalse(valueCell.isPossibleValue(5));
			Assert::IsFalse(valueCell.isPossibleValue(9));
			Assert::IsFalse(valueCell.isPossibleValue(10));
		}

		// Test numberPossibleValues method
		TEST_METHOD(Unit_Test_Cell_numberPossibleValues_With_Value_Of_Zero) 
		{
			// Verify number of possible values is 9 if cell is instantiated with a value of zero
			Cell blankCell = Cell();
			uint8_t expectedValue = 9;

			Assert::AreEqual(expectedValue, blankCell.numberPossibleValues());
		}
		TEST_METHOD(Unit_Test_Cell_numberPossibleValues_With_Non_Zero_Value) 
		{
			// Verify number of possible values is 0 if cell is instantiated with a non-zero value
			Cell blankCell = Cell(6);
			uint8_t expectedValue = 0;

			Assert::AreEqual(expectedValue, blankCell.numberPossibleValues());
		}

		// Test getPossibleValuesArray
		TEST_METHOD(Unit_Test_Cell_getPossibleValuesArray_With_Value_Of_Zero)
		{
			// Verify list of possible values is 1 through 9 if cell is instantiated with a value of zero
			Cell blankCell = Cell();

			uint8_t cellArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t testArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], testArray[i]);
			}
		}
		TEST_METHOD(Unit_Test_Cell_getPossibleValuesArray_With_Non_Zero_Value)
		{
			// Verify there are no possible values if a cell is instantiated with a non-zero value
			Cell valueCell = Cell(2);

			uint8_t cellArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t testArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

			valueCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], testArray[i]);
			}
		}

		// Test setPossibleValue and clearPossibleValue
		TEST_METHOD(Integration_Test_Cell_PossibleValue_With_Value_Of_Zero)
		{
			// Verify list of possible values is 1 through 9 if cell is instantiated with a value of zero
			Cell blankCell = Cell();

			uint8_t cellArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t initialTestArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
			uint8_t clearedTestArray[9] = {1, 4, 5, 6, 8, 0, 0, 0, 0};
			uint8_t setTestArray[9] = {1, 3, 4, 5, 6, 8, 9, 0, 0};
			uint8_t clearedArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

			// Verify all values are possible upon initialization
			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], initialTestArray[i]);
			}

			Assert::IsTrue(blankCell.clearPossibleValue(2));
			Assert::IsTrue(blankCell.clearPossibleValue(3));
			Assert::IsTrue(blankCell.clearPossibleValue(7));
			Assert::IsTrue(blankCell.clearPossibleValue(9));

			Assert::IsFalse(blankCell.clearPossibleValue(2));
			
			// Verify removed possibles values were actually removed
			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], clearedTestArray[i]);
			}
			
			Assert::IsTrue(blankCell.setPossibleValue(3));
			Assert::IsTrue(blankCell.setPossibleValue(9));

			
			// Verify added possible values were added back
			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], setTestArray[i]);
			}

			blankCell.setValue(5);

			// Verify possible values are cleared after setting a value
			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], clearedArray[i]);
			}

			Assert::IsFalse(blankCell.clearPossibleValue(2));
			Assert::IsFalse(blankCell.clearPossibleValue(3));
			Assert::IsFalse(blankCell.clearPossibleValue(7));
			Assert::IsFalse(blankCell.clearPossibleValue(9));

			// Verify possible values are cleared after setting a value and clearing several possible values
			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], clearedArray[i]);
			}
		}
		TEST_METHOD(Integration_Test_Cell_PossibleValue_With_Non_Zero_Value)
		{
			// Verify list of possible values is 1 through 9 if cell is instantiated with a value of zero
			Cell valueCell = Cell(4);

			uint8_t cellArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t initialTestArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t clearedTestArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t setTestArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

			// Verify initial possible values are all 0
			valueCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], initialTestArray[i]);
			}

			Assert::IsFalse(valueCell.clearPossibleValue(2));
			Assert::IsFalse(valueCell.clearPossibleValue(3));
			Assert::IsFalse(valueCell.clearPossibleValue(7));
			Assert::IsFalse(valueCell.clearPossibleValue(9));

			// Verify possible values are still 0 after clearing several values
			valueCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], clearedTestArray[i]);
			}

			Assert::IsFalse(valueCell.setPossibleValue(3));
			Assert::IsFalse(valueCell.setPossibleValue(9));

			// Verify possible values are still 0 after setting several values
			valueCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], setTestArray[i]);
			}
		}
	
		// Test setValue, getPossibleValuesArray, and getValue
		TEST_METHOD(Integration_Test_Cell_setValue_With_Value_Of_Zero)
		{
			// Verify list of possible values is 1 through 9 if cell is instantiated with a value of zero
			Cell blankCell = Cell();
			uint8_t newValue = 4;

			uint8_t cellArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t initialTestArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
			uint8_t clearedTestArray[9] = {1, 4, 5, 6, 8, 0, 0, 0, 0};
			uint8_t setValueNonZeroTestArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t setValueZeroTestArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], initialTestArray[i]);
			}

			blankCell.clearPossibleValue(2);
			blankCell.clearPossibleValue(3);
			blankCell.clearPossibleValue(7);
			blankCell.clearPossibleValue(9);

			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], clearedTestArray[i]);
			}
			
			newValue = 4;
			blankCell.setValue(newValue);

			Assert::AreEqual(newValue, blankCell.getValue());

			
			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], setValueNonZeroTestArray[i]);
			}

			newValue = 0;
			blankCell.setValue(newValue);

			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], setValueZeroTestArray[i]);
			}
			
			blankCell.clearPossibleValue(2);
			blankCell.clearPossibleValue(3);
			blankCell.clearPossibleValue(7);
			blankCell.clearPossibleValue(9);

			blankCell.getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], clearedTestArray[i]);
			}
		}
	};

	TEST_CLASS(BoardTests)
	{
	public:
		// Test getValue method
		TEST_METHOD(Unit_Test_Board_getValue_With_Blank_Constructor)
		{
			// Verifies possible values given a constructor with no arguments, which should to default to a value of 0.
			Board blankBoard = Board();
			uint8_t expectedValue = 0;

			for(uint8_t i = 0; i < 9; i++) {
				for(uint8_t j = 0; j < 9 ; j++) {
					Assert::AreEqual(expectedValue, blankBoard.getValue(i, j));
				}
			}
		}
		TEST_METHOD(Unit_Test_Board_getValue_With_ValidBoard_Constructor)
		{
			uint8_t inputBoard[9][9] = { {0, 2, 3, 0, 6, 4, 1, 0, 0},
										 {0, 0, 0, 3, 0, 0, 0, 4, 0},
										 {1, 0, 4, 0, 2, 9, 7, 0, 5},
										 {0, 4, 6, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 7, 0},
										 {0, 5, 0, 0, 7, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 9},
										 {0, 0, 0, 4, 0, 0, 0, 0, 0},
										 {7, 0, 0, 0, 0, 0, 0, 0, 0} };

			Board validBoard = Board(inputBoard);

			uint8_t expectedValue = 2;
			Assert::AreEqual(expectedValue, validBoard.getValue(0, 1));

			expectedValue = 1;
			Assert::AreEqual(expectedValue, validBoard.getValue(2, 0));

			expectedValue = 0;
			Assert::AreEqual(expectedValue, validBoard.getValue(3, 4));

			for(uint8_t i = 0; i < 9; i++) {
				for(uint8_t j = 0; j < 9 ; j++) {
					Assert::AreEqual(inputBoard[i][j], validBoard.getValue(i, j));
				}
			}
		}

		// Test setValue method
		TEST_METHOD(Integration_Test_Board_setValue_With_Blank_Constructor)
		{
			// Verifies possible values given a constructor with no arguments, which should to default to a value of 0.
			Board blankBoard = Board();
			uint8_t expectedValue = 0;

			uint8_t cellArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t testBlankArray[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			uint8_t testFullArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
			uint8_t testRow3Column3Array[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

			// Verify board is initally blank
			for(uint8_t i = 0; i < 9; i++) {
				for(uint8_t j = 0; j < 9 ; j++) {
					Assert::AreEqual(expectedValue, blankBoard.getValue(i, j));
				}
			}
			
			// Set values at several locations
			blankBoard.setValue(4, 5, 4);
			blankBoard.setValue(2, 8, 3);
			blankBoard.setValue(9, 4, 4);
			
			// Verify row 5, colum 4 was set to 4
			expectedValue = 4;
			Assert::AreEqual(expectedValue, blankBoard.getValue(5, 4));
			
			// Verify row 8, column 3 was set to 2
			expectedValue = 2;
			Assert::AreEqual(expectedValue, blankBoard.getValue(8, 3));

			// Verify row 4, column 4 was set to 9
			expectedValue = 9;
			Assert::AreEqual(expectedValue, blankBoard.getValue(4, 4));
			
			// Get possible values at row 5, column 4
			blankBoard.board[5][4].getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], testBlankArray[i]);
			}
			
			// Get possible values at row 9, column 3
			blankBoard.board[8][3].getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], testBlankArray[i]);
			}

			// Get possible values at row 4, column 4
			blankBoard.board[4][4].getPossibleValuesArray(cellArray);

			for(int i = 0; i < 9; i++) {
				Assert::AreEqual(cellArray[i], testBlankArray[i]);
			}
		}
	};
}