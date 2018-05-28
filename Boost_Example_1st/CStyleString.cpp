#include "stdafx.h"
#include "CStyleString.h"

CStyleString::CStyleString()
{
}

int CStyleString::start(int argc, char * argv[])
{
	char * testString = "Is It Okay? " "Really?";
	printf(testString);

	return 0;
}

CStyleString::~CStyleString()
{
}