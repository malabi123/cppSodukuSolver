#include "SizeNineManager.h"
SizeNineManager::SizeNineManager(): TableSizeManager( 9, 3, 3) {
}

void SizeNineManager::GroupPosByGroup(int group, int* rowS, int* rowE, int* colS, int* colE) {
	if (group < 3)
	{
		*rowS = 0;
		*rowE = 3;
	}
	else if (group < 6)
	{
		*rowS = 3;
		*rowE = 6;
	}
	else
	{
		*rowS = 6;
		*rowE = 9;
	}
	if (group % 3 == 0)
	{
		*colS = 0;
		*colE = 3;
	}
	else if (group % 3 == 1)
	{
		*colS = 3;
		*colE = 6;
	}
	else
	{
		*colS = 6;
		*colE = 9;
	}
}
