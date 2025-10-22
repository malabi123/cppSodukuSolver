#pragma once
class TableSizeManager
{
private:
	int m_Size;
	int m_GroupH;
	int m_GroupW;;

protected:
	TableSizeManager(int s, int h, int w);

public:
	int RowSize();
	int ColSize();
	int GetGroupH();
	int GetGroupW();
	void GroupPosByPos(int row, int col, int* rowS, int* rowE, int* colS, int* colE);
	void GroupPosByGroup(int group, int* rowS, int* rowE, int* colS, int* colE);
};

