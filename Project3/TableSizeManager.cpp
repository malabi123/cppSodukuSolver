#include "TableSizeManager.h"
int TableSizeManager::RowSize() {
	return m_Size;
}
int TableSizeManager::ColSize() {
	return m_Size;
}
TableSizeManager::TableSizeManager(int s, int h, int w) {
	m_GroupH = h;
	m_GroupW = w;
	m_Size = s;
}
int TableSizeManager::GetGroupH() {
	return m_GroupH;
}
int TableSizeManager::GetGroupW() {
	return m_GroupW;
}
void TableSizeManager::GroupPosByPos(int row, int col, int* rowS, int* rowE, int* colS, int* colE) {
	*colS = (col / GetGroupW()) * GetGroupW();
	*colE = *colS + GetGroupW();
	*rowS = (row / GetGroupH()) * GetGroupH();
	*rowE = *rowS + GetGroupH();
}
void TableSizeManager::GroupPosByGroup(int group, int* rowS, int* rowE, int* colS, int* colE) {
	*rowS = (group / GetGroupH()) * (GetGroupH());
	*rowE = *rowS + GetGroupH();
	*colS = group % (ColSize() / GetGroupW()) * (GetGroupW());
	*colE = *colS + GetGroupW();
}