#pragma once
#include "TableSizeManager.h"
class SizeNineManager : public TableSizeManager
{
public:
	SizeNineManager();
	virtual void GroupPosByGroup(int group, int* rowS, int* rowE, int* colS, int* colE) override;
};

