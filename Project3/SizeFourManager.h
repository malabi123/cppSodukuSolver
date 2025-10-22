#pragma once
#include "TableSizeManager.h"
class SizeFourManager : public TableSizeManager
{
public:
	SizeFourManager();
	virtual void GroupPosByGroup(int group, int* rowS, int* rowE, int* colS, int* colE) override;
};

