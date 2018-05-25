#include "stdafx.h"
#include "TrashValue.h"
#include <cstdio>

TrashValue::TrashValue()
{
}

int TrashValue::start(int argc, char * argv[])
{
	int c;
	int cTrashChecking = c;
	try
	{
		std::cout << c;

		if (cTrashChecking == c)
		{
			std::string excption = "Trash Value Found. is This right?";
			throw excption;
		}
	}
	catch (std::string e)
	{
		std::cout << e;

		c = 100;
		assert(c != cTrashChecking && e.c_str());
	}
	catch (...)
	{
		std::cout << std::endl << "Oh, Something Worng~!";
		return -1;
	}

	return 0;
}

TrashValue::~TrashValue()
{
}