#pragma once
#include "Square.h"
#include "TableSizeManager.h"

class Table
{
private:
	
	bool *m_Temp;
	TableSizeManager* m_SizeManager;
	Square **m_Board;
	int m_toFill;
	
	
	void checkRow(int row);
	void checkCol(int col);
	void checkGroup(int group);
	void updateLeftNumbersOnTempByRow(int row);
	void updateLeftNumbersOnTempByCol(int col);
	void updateLeftNumbersOnTempByGroup(int rowS, int rowE, int colS, int colE);
	void resetTemp();
	void UpdateRowNumTaken(int row, int num);
	void UpdateColNumTaken(int col, int num);
	void UpdateGroupNumTaken(int row, int col, int num);
public:

	Table(TableSizeManager* sizeManager);
	~Table();
	void PrintTable();
	void SetValueInSquare(int row, int col, int value);
	void SetValueInSquareOneDigitSize(int value);
	void SetValueInSquareTwoDigitSize(int value);
	void SetValuesInSquares(int* arr, int size);
	void SquareUpdateParentItFilled(int row, int col, int num);
	void solve();
};