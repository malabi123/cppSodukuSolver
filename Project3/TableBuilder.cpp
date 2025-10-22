#include "TableBuilder.h"
#include "SizeNineManager.h"
#include "SizeSixManager.h"
#include "SizeFourManager.h"

Table* TableBuilder::BuildTable(eSize size) {
	Table* t=nullptr;
	switch (size)
	{
	case eSize::SizeFour:
		t = new Table(new SizeFourManager);
		break;
	case eSize::SizeSix:
		t = new Table(new SizeSixManager);
		break;
	case eSize::SizeNine:
		t = new Table(new SizeNineManager);
		break;
	default:
		break;
	}
	return t;
}

