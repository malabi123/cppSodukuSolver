#pragma once
#include "Table.h";
enum eSize {
	SizeFour,
	SizeSix,
	SizeNine,
	SizeSixteen
};

static class TableBuilder
{
public:
	static Table* BuildTable(eSize size);
};

