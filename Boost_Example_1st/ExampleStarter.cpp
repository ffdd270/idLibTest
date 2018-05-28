#include "stdafx.h"
#include "ThisPtrSameNew.h"
#include "TrashValue.h"
#include "TestIdLib.h"
#include "CWelcomeC17.h"
#include "IsTypeIdSame.h"
#include "idFirstTest.h"
#include "CStyleString.h"
#include "WinThreadTest.h"
#include <cstdio>

int main(int argc, char * argv[])
{
	IExample * test = new WinThreadTest();

	//test -> this
	unsigned char ch = -1;
	test->start(argc, argv);
	system("pause");
}