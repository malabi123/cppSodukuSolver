#include "SizeSixManager.h"
SizeSixManager::SizeSixManager() : TableSizeManager(6, 2, 3) {
}

void SizeSixManager::GroupPosByGroup(int group, int* rowS, int* rowE, int* colS, int* colE) {
	if (group < 2)
	{
		*rowS = 0;
		*rowE = 2;
	}
	else if (group < 4)
	{
		*rowS = 2;
		*rowE = 4;
	}
	else
	{
		*rowS = 4;
		*rowE = 6;
	}
	if (group % 2 == 0)
	{
		*colS = 0;
		*colE = 3;
	}
	else
	{
		*colS = 3;
		*colE = 6;
	}
}
