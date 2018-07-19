#include "stdafx.h"
#include "ThisPtrSameNew.h"
#include "TrashValue.h"
#include "TestIdLib.h"
#include "CWelcomeC17.h"
#include "IsTypeIdSame.h"
#include "idFirstTest.h"
#include "CStyleString.h"
#include "WinThreadTest.h"
#include "EuclideanAlgorithm.h"
#include "AlgorithmTest.h"
#include <cstdio>
#include <fstream>

int main(int argc, char * argv[])
{
	IExample * test = new AlgorithmTest();

	//test -> this
	unsigned char ch = -1;
	test->start(argc, argv);
	system("pause");
}

