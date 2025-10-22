#include "SizeFourManager.h"
SizeFourManager::SizeFourManager() : TableSizeManager(4, 2, 2) {
}

void SizeFourManager::GroupPosByGroup(int group, int* rowS, int* rowE, int* colS, int* colE) {
	if (group < 2)
	{
		*rowS = 0;
		*rowE = 2;
	}
	else
	{
		*rowS = 2;
		*rowE = 4;
	}
	if (group % 2 == 0)
	{
		*colS = 0;
		*colE = 2;
	}
	else
	{
		*colS = 2;
		*colE = 4;
	}
}

