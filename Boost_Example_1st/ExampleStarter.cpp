#include "stdafx.h"
#include "ThisPtrSameNew.h"
#include "TrashValue.h"
#include "TestIdLib.h"
#include "CWelcomeC17.h"
#include "IsTypeIdSame.h"
#include <cstdio>


int main(int argc, char * argv[])
{
	IExample * test = new CWelcomeC17();

	//test -> this
	unsigned char ch = -1;
	test->start(argc, argv);
	system("pause");
}