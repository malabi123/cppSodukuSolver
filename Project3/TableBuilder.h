#pragma once
#include "Table.h";
enum eSize {
	SizeFour,
	SizeSix,
	SizeNine,
};

static class TableBuilder
{
public:
	static Table* BuildTable(eSize size);
};

