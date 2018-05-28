#pragma once
#include "Example.h"
class idFirstTest :
	public IExample
{
public:
	idFirstTest();

	int start(int argc, char *argv[]) override;

	~idFirstTest();
private:
	void ArrayPrint(idTempArray<int> &tempArray, idArray<int, 4> &array);
	void ArrayInit(idTempArray<int> &tempArray, idArray<int, 4> &array);
	void TreeTest(idBTree<char *, WCHAR *, 4> &tree);
};
