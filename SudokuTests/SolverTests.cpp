#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Sudoku\Board.h"
#include "..\Sudoku\SolverSupport.h"
#include "..\Sudoku\SolverSingles.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const int BOARD_WIDTH = 9;
const int BOARD_HEIGHT = 9;

namespace SudokuTests
{
	TEST_CLASS(SolverTests)
	{
	public:
		
		TEST_METHOD(Unit_Test_Solver_Support_GetHiddenNumberCount)
		{
			
			// Setup board
			uint8_t inputBoard[9][9] = { {0, 2, 3, 0, 6, 4, 1, 0, 0},
										 {0, 0, 0, 3, 0, 0, 0, 4, 0},
										 {1, 0, 4, 0, 2, 9, 7, 0, 5},
										 {0, 4, 6, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 7, 0},
										 {0, 5, 0, 0, 7, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 9},
										 {0, 0, 0, 4, 0, 0, 0, 0, 0},
										 {7, 0, 0, 0, 0, 0, 0, 0, 0} };
		
			// Setup board class to be used by support solver
			Board board = Board(inputBoard);

			// Setup support solver class
			SolverSupport support = SolverSupport(board);

			// Setup arrays that we expect Number Location Count array to be, one for row, one for column, and one for box
			NumberLocationCount numberCountTestRow[9] = {NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount() };
			NumberLocationCount numberCountTestCol[9] = {NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount() };
			NumberLocationCount numberCountTestBox[9] = {NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount() };
			
			initializeHiddenNumberCountRow(numberCountTestRow);
			initializeHiddenNumberCountColumn(numberCountTestCol);

			support.getNumberCountHidden(0, 0, 0, 8);

			for(int value = 1; value <= 9; value++) {
				Assert::AreEqual(numberCountTestRow[value - 1].count, support.numberCount[value - 1].count);
				for(int i = 0; i < 9; i++) {
					uint8_t expected_row = numberCountTestRow[value - 1].location[i].row;
					uint8_t expected_col = numberCountTestRow[value - 1].location[i].column;
					uint8_t actual_row = support.numberCount[value - 1].location[i].row;
					uint8_t actual_col = support.numberCount[value - 1].location[i].column;

					Assert::AreEqual(expected_row, actual_row);
					Assert::AreEqual(expected_col, actual_col);
				}
			}
			
			support.getNumberCountHidden(0, 8, 0, 0);

			for(int value = 1; value <= 9; value++) {
				Assert::AreEqual(numberCountTestCol[value - 1].count, support.numberCount[value - 1].count);
				for(int i = 0; i < 9; i++) {
					uint8_t expected_row = numberCountTestCol[value - 1].location[i].row;
					uint8_t expected_col = numberCountTestCol[value - 1].location[i].column;
					uint8_t actual_row = support.numberCount[value - 1].location[i].row;
					uint8_t actual_col = support.numberCount[value - 1].location[i].column;

					Assert::AreEqual(expected_row, actual_row);
					Assert::AreEqual(expected_col, actual_col);
				}
			}
		}

		void initializeHiddenNumberCountRow(NumberLocationCount *numberCountTestRow) {

			numberCountTestRow[1 - 1].count = 0;

			numberCountTestRow[2 - 1].count = 0;

			numberCountTestRow[3 - 1].count = 0;

			numberCountTestRow[4 - 1].count = 0;

			numberCountTestRow[5 - 1].count = 2;
			numberCountTestRow[5 - 1].location[0].row = 0;
			numberCountTestRow[5 - 1].location[0].column = 0;
			numberCountTestRow[5 - 1].location[1].row = 0;
			numberCountTestRow[5 - 1].location[1].column = 3;

			numberCountTestRow[6 - 1].count = 0;

			numberCountTestRow[7 - 1].count = 1;
			numberCountTestRow[7 - 1].location[0].row = 0;
			numberCountTestRow[7 - 1].location[0].column = 3;

			numberCountTestRow[8 - 1].count = 4;
			numberCountTestRow[8 - 1].location[0].row = 0;
			numberCountTestRow[8 - 1].location[0].column = 0;
			numberCountTestRow[8 - 1].location[1].row = 0;
			numberCountTestRow[8 - 1].location[1].column = 3;
			numberCountTestRow[8 - 1].location[2].row = 0;
			numberCountTestRow[8 - 1].location[2].column = 7;
			numberCountTestRow[8 - 1].location[3].row = 0;
			numberCountTestRow[8 - 1].location[3].column = 8;

			numberCountTestRow[9 - 1].count = 2;
			numberCountTestRow[9 - 1].location[0].row = 0;
			numberCountTestRow[9 - 1].location[0].column = 0;
			numberCountTestRow[9 - 1].location[1].row = 0;
			numberCountTestRow[9 - 1].location[1].column = 7;
		}
		void initializeHiddenNumberCountColumn(NumberLocationCount *numberCountTestColumn) {

			numberCountTestColumn[1 - 1].count = 0;

			numberCountTestColumn[2 - 1].count = 5;
			numberCountTestColumn[2 - 1].location[0].row = 3;
			numberCountTestColumn[2 - 1].location[0].column = 0;
			numberCountTestColumn[2 - 1].location[1].row = 4;
			numberCountTestColumn[2 - 1].location[1].column = 0;
			numberCountTestColumn[2 - 1].location[2].row = 5;
			numberCountTestColumn[2 - 1].location[2].column = 0;
			numberCountTestColumn[2 - 1].location[3].row = 6;
			numberCountTestColumn[2 - 1].location[3].column = 0;
			numberCountTestColumn[2 - 1].location[4].row = 7;
			numberCountTestColumn[2 - 1].location[4].column = 0;
			
			numberCountTestColumn[3 - 1].count = 5;
			numberCountTestColumn[3 - 1].location[0].row = 3;
			numberCountTestColumn[3 - 1].location[0].column = 0;
			numberCountTestColumn[3 - 1].location[1].row = 4;
			numberCountTestColumn[3 - 1].location[1].column = 0;
			numberCountTestColumn[3 - 1].location[2].row = 5;
			numberCountTestColumn[3 - 1].location[2].column = 0;
			numberCountTestColumn[3 - 1].location[3].row = 6;
			numberCountTestColumn[3 - 1].location[3].column = 0;
			numberCountTestColumn[3 - 1].location[4].row = 7;
			numberCountTestColumn[3 - 1].location[4].column = 0;

			numberCountTestColumn[4 - 1].count = 1;
			numberCountTestColumn[4 - 1].location[0].row = 6;
			numberCountTestColumn[4 - 1].location[0].column = 0;

			numberCountTestColumn[5 - 1].count = 4;
			numberCountTestColumn[5 - 1].location[0].row = 0;
			numberCountTestColumn[5 - 1].location[0].column = 0;
			numberCountTestColumn[5 - 1].location[1].row = 1;
			numberCountTestColumn[5 - 1].location[1].column = 0;
			numberCountTestColumn[5 - 1].location[2].row = 6;
			numberCountTestColumn[5 - 1].location[2].column = 0;
			numberCountTestColumn[5 - 1].location[3].row = 7;
			numberCountTestColumn[5 - 1].location[3].column = 0;

			numberCountTestColumn[6 - 1].count = 3;
			numberCountTestColumn[6 - 1].location[0].row = 1;
			numberCountTestColumn[6 - 1].location[0].column = 0;
			numberCountTestColumn[6 - 1].location[1].row = 6;
			numberCountTestColumn[6 - 1].location[1].column = 0;
			numberCountTestColumn[6 - 1].location[2].row = 7;
			numberCountTestColumn[6 - 1].location[2].column = 0;

			numberCountTestColumn[7 - 1].count = 0;

			numberCountTestColumn[8 - 1].count = 7;
			numberCountTestColumn[8 - 1].location[0].row = 0;
			numberCountTestColumn[8 - 1].location[0].column = 0;
			numberCountTestColumn[8 - 1].location[1].row = 1;
			numberCountTestColumn[8 - 1].location[1].column = 0;
			numberCountTestColumn[8 - 1].location[2].row = 3;
			numberCountTestColumn[8 - 1].location[2].column = 0;
			numberCountTestColumn[8 - 1].location[3].row = 4;
			numberCountTestColumn[8 - 1].location[3].column = 0;
			numberCountTestColumn[8 - 1].location[4].row = 5;
			numberCountTestColumn[8 - 1].location[4].column = 0;
			numberCountTestColumn[8 - 1].location[5].row = 6;
			numberCountTestColumn[8 - 1].location[5].column = 0;
			numberCountTestColumn[8 - 1].location[6].row = 7;
			numberCountTestColumn[8 - 1].location[6].column = 0;

			numberCountTestColumn[9 - 1].count = 6;
			numberCountTestColumn[9 - 1].location[0].row = 0;
			numberCountTestColumn[9 - 1].location[0].column = 0;
			numberCountTestColumn[9 - 1].location[1].row = 1;
			numberCountTestColumn[9 - 1].location[1].column = 0;
			numberCountTestColumn[9 - 1].location[2].row = 3;
			numberCountTestColumn[9 - 1].location[2].column = 0;
			numberCountTestColumn[9 - 1].location[3].row = 4;
			numberCountTestColumn[9 - 1].location[3].column = 0;
			numberCountTestColumn[9 - 1].location[4].row = 5;
			numberCountTestColumn[9 - 1].location[4].column = 0;
			numberCountTestColumn[9 - 1].location[5].row = 7;
			numberCountTestColumn[9 - 1].location[5].column = 0;
		}

		TEST_METHOD(Unit_Test_Solver_Support_GetNakedNumberCount) 
		{// 1 3 4 6 9
			
			// Setup board
			uint8_t inputBoard[9][9] = { {2, 0, 3, 0, 6, 4, 1, 0, 0},
										 {0, 5, 7, 0, 8, 1, 0, 3, 4}, // 6 9
										 {0, 0, 0, 4, 3, 0, 6, 0, 0}, // 1 9
										 {5, 0, 0, 0, 0, 0, 0, 5, 0}, 
										 {7, 0, 0, 0, 0, 0, 0, 0, 8}, 
										 {8, 0, 0, 0, 0, 0, 0, 7, 0},
										 {0, 0, 0, 0, 1, 6, 9, 0, 0}, // 3 4
										 {0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1 3 4 6 9
										 {0, 0, 0, 0, 1, 4, 3, 0, 0} };// 6 9

			// Setup board class to be used by support solver
			Board board = Board(inputBoard);

			// Setup support solver class
			SolverSupport support = SolverSupport(board);

			// Setup arrays that we expect Number Location Count array to be, one for row, one for column, and one for box
			NumberLocationCount numberCountTestRow[9] = {NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount() };
			NumberLocationCount numberCountTestCol[9] = {NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount() };
			NumberLocationCount numberCountTestBox[9] = {NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount(),
														 NumberLocationCount(), NumberLocationCount(), NumberLocationCount() };
			
			initializeNakedNumberCountRow(numberCountTestRow);
			initializeNakedNumberCountColumn(numberCountTestCol);

			support.getNumberCountNaked(2, 2, 0, 0, 0, 8);

			for(int value = 1; value <= 9; value++) {
				Assert::AreEqual(numberCountTestRow[value - 1].count, support.numberCount[value - 1].count);
				for(int i = 0; i < 9; i++) {
					uint8_t expected_row = numberCountTestRow[value - 1].location[i].row;
					uint8_t expected_col = numberCountTestRow[value - 1].location[i].column;
					uint8_t actual_row = support.numberCount[value - 1].location[i].row;
					uint8_t actual_col = support.numberCount[value - 1].location[i].column;

					Assert::AreEqual(expected_row, actual_row);
					Assert::AreEqual(expected_col, actual_col);
				}
			}
			
			support.getNumberCountNaked(2, 2, 0, 8, 0, 0);

			for(int value = 1; value <= 9; value++) {
				Assert::AreEqual(numberCountTestCol[value - 1].count, support.numberCount[value - 1].count);
				for(int i = 0; i < 9; i++) {
					uint8_t expected_row = numberCountTestCol[value - 1].location[i].row;
					uint8_t expected_col = numberCountTestCol[value - 1].location[i].column;
					uint8_t actual_row = support.numberCount[value - 1].location[i].row;
					uint8_t actual_col = support.numberCount[value - 1].location[i].column;

					Assert::AreEqual(expected_row, actual_row);
					Assert::AreEqual(expected_col, actual_col);
				}
			}
		}

		void initializeNakedNumberCountRow(NumberLocationCount *numberCountTestRow) {

			numberCountTestRow[1 - 1].count = 0;

			numberCountTestRow[2 - 1].count = 0;

			numberCountTestRow[3 - 1].count = 0;

			numberCountTestRow[4 - 1].count = 0;

			numberCountTestRow[5 - 1].count = 0;

			numberCountTestRow[6 - 1].count = 0;

			numberCountTestRow[7 - 1].count = 0;

			numberCountTestRow[8 - 1].count = 2;
			numberCountTestRow[8 - 1].location[0].row = 0;
			numberCountTestRow[8 - 1].location[0].column = 1;
			numberCountTestRow[8 - 1].location[1].row = 0;
			numberCountTestRow[8 - 1].location[1].column = 7;

			numberCountTestRow[9 - 1].count = 2;
			numberCountTestRow[9 - 1].location[0].row = 0;
			numberCountTestRow[9 - 1].location[0].column = 1;
			numberCountTestRow[9 - 1].location[1].row = 0;
			numberCountTestRow[9 - 1].location[1].column = 7;
		}
		void initializeNakedNumberCountColumn(NumberLocationCount *numberCountTestColumn) {

			numberCountTestColumn[1 - 1].count = 1;
			numberCountTestColumn[1 - 1].location[0].row = 2;
			numberCountTestColumn[1 - 1].location[0].column = 0;

			numberCountTestColumn[2 - 1].count = 0;
			
			numberCountTestColumn[3 - 1].count = 1;
			numberCountTestColumn[3 - 1].location[0].row = 6;
			numberCountTestColumn[3 - 1].location[0].column = 0;

			numberCountTestColumn[4 - 1].count = 1;
			numberCountTestColumn[4 - 1].location[0].row = 6;
			numberCountTestColumn[4 - 1].location[0].column = 0;

			numberCountTestColumn[5 - 1].count = 0;

			numberCountTestColumn[6 - 1].count = 2;
			numberCountTestColumn[6 - 1].location[0].row = 1;
			numberCountTestColumn[6 - 1].location[0].column = 0;
			numberCountTestColumn[6 - 1].location[1].row = 8;
			numberCountTestColumn[6 - 1].location[1].column = 0;

			numberCountTestColumn[7 - 1].count = 0;

			numberCountTestColumn[8 - 1].count = 0;

			numberCountTestColumn[9 - 1].count = 3;
			numberCountTestColumn[9 - 1].location[0].row = 1;
			numberCountTestColumn[9 - 1].location[0].column = 0;
			numberCountTestColumn[9 - 1].location[1].row = 2;
			numberCountTestColumn[9 - 1].location[1].column = 0;
			numberCountTestColumn[9 - 1].location[2].row = 8;
			numberCountTestColumn[9 - 1].location[2].column = 0;
		}

	};

	TEST_CLASS(SolverSingleTests) 
	{
	public:

		TEST_METHOD(Unit_Test_Solver_Single_ProcessHiddenSingle) {

			for(int i = 0; i < ELEMENTS; i++) {
				solverSupport.numberCount[i].count = 0;
				for(int j = 0;j < ELEMENTS; j++) {
					solverSupport.numberCount[i].location[j].row = 0;
					solverSupport.numberCount[i].location[j].column = 0;
				}
			}

			// Setup board
			uint8_t inputBoard[9][9] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0} };

			uint8_t solvedBoard[9][9] = { {1, 2, 3, 0, 0, 0, 0, 0, 0},
										  {4, 5, 6, 0, 0, 0, 0, 0, 0},
										  {7, 8, 9, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0} };

			// Setup board class to be used by support solver
			Board board = Board(inputBoard);
			solverSupport.setBoard(board);

			// Setup number count appropriately
			for(int i = 0; i < ELEMENTS; i++) {
				solverSupport.numberCount[i].count = 1;
				solverSupport.numberCount[i].location[0].row = (i / 3);
				solverSupport.numberCount[i].location[0].column = (i % 3);
			}

			Assert::IsTrue(processHiddenSingle(board));

			for(int i = 0; i < ELEMENTS; i++) {
				for(int j = 0; j < ELEMENTS; j++) {
					Assert::AreEqual(solvedBoard[i][j], board.getValue(i, j));
				}
			}

			solverSupport.getNumberCountHidden(0, 2, 0, 2);

			Assert::IsFalse(processHiddenSingle(board));

			for(int i = 0; i < ELEMENTS; i++) {
				for(int j = 0; j < ELEMENTS; j++) {
					Assert::AreEqual(solvedBoard[i][j], board.getValue(i, j));
				}
			}

			Assert::IsFalse(processHiddenSingle(board));
		}

		TEST_METHOD(Unit_Test_Solver_Single_RemoveNakedSingles) {
			
			// Setup board
			uint8_t inputBoard[9][9] = { {0, 2, 3, 0, 0, 0, 0, 0, 0},
										 {4, 5, 6, 0, 0, 0, 0, 0, 0},
										 {7, 8, 9, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 1, 0, 3, 0, 0, 0},
										 {0, 0, 0, 4, 5, 6, 0, 0, 0},
										 {0, 0, 0, 7, 8, 9, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 1, 2, 3},
										 {0, 0, 0, 0, 0, 0, 4, 5, 0},
										 {0, 0, 0, 0, 0, 0, 7, 8, 9} };

			uint8_t solvedBoard[9][9] = { {1, 2, 3, 0, 0, 0, 0, 0, 0},
										  {4, 5, 6, 0, 0, 0, 0, 0, 0},
										  {7, 8, 9, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 1, 2, 3, 0, 0, 0},
										  {0, 0, 0, 4, 5, 6, 0, 0, 0},
										  {0, 0, 0, 7, 8, 9, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 1, 2, 3},
										  {0, 0, 0, 0, 0, 0, 4, 5, 6},
										  {0, 0, 0, 0, 0, 0, 7, 8, 9} };

			// Setup board class to be used by support solver
			Board board = Board(inputBoard);

			Assert::IsTrue(removeNakedSingles(board));

			for(int i = 0; i < ELEMENTS; i++) {
				for(int j = 0; j < ELEMENTS; j++) {
					Assert::AreEqual(solvedBoard[i][j], board.getValue(i, j));
				}
			}

			Assert::IsFalse(removeNakedSingles(board));

			for(int i = 0; i < ELEMENTS; i++) {
				for(int j = 0; j < ELEMENTS; j++) {
					Assert::AreEqual(solvedBoard[i][j], board.getValue(i, j));
				}
			}

			Assert::IsFalse(removeNakedSingles(board));
		}

		TEST_METHOD(Unit_Test_Solver_Single_RemoveHiddenSingleRow) {
			
			// Setup board
			uint8_t inputBoard[9][9] = { {0, 2, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 1, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 1, 0, 0},
										 {0, 0, 1, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0} };

			uint8_t solvedBoard[9][9] = { {1, 2, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 1, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 1, 0, 0},
										  {0, 0, 1, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0} };

			// Setup board class to be used by support solver
			Board board = Board(inputBoard);
			solverSupport.setBoard(board);

			Assert::IsTrue(removeHiddenSingleRow(board));

			for(int i = 0; i < ELEMENTS; i++) {
				for(int j = 0; j < ELEMENTS; j++) {
					Assert::AreEqual(solvedBoard[i][j], board.getValue(i, j));
				}
			}
			
			Assert::IsFalse(removeHiddenSingleRow(board));

			for(int i = 0; i < ELEMENTS; i++) {
				for(int j = 0; j < ELEMENTS; j++) {
					Assert::AreEqual(solvedBoard[i][j], board.getValue(i, j));
				}
			}

			Assert::IsFalse(removeHiddenSingleRow(board));
		}

		TEST_METHOD(Unit_Test_Solver_Single_RemoveHiddenSingleColumn) {
			
			// Setup board
			uint8_t inputBoard[9][9] = { {0, 2, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 1, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 1, 0, 0},
										 {0, 0, 1, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 1, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0} };

			uint8_t solvedBoard[9][9] = { {1, 2, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 1, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 1, 0, 0},
										  {0, 0, 1, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 1, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0} };

			// Setup board class to be used by support solver
			Board board = Board(inputBoard);
			solverSupport.setBoard(board);

			Assert::IsTrue(removeHiddenSingleColumn(board));

			for(int i = 0; i < ELEMENTS; i++) {
				for(int j = 0; j < ELEMENTS; j++) {
					Assert::AreEqual(solvedBoard[i][j], board.getValue(i, j));
				}
			}
			
			Assert::IsFalse(removeHiddenSingleColumn(board));

			for(int i = 0; i < ELEMENTS; i++) {
				for(int j = 0; j < ELEMENTS; j++) {
					Assert::AreEqual(solvedBoard[i][j], board.getValue(i, j));
				}
			}

			Assert::IsFalse(removeHiddenSingleColumn(board));
		}
	};
}