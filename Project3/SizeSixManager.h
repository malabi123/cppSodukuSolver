#pragma once
#include "TableSizeManager.h"
class SizeSixManager : public TableSizeManager
{
public:
	SizeSixManager();
	virtual void GroupPosByGroup(int group, int* rowS, int* rowE, int* colS, int* colE) override;
};


