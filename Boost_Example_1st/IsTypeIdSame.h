#pragma once
#include "Example.h"
class IsTypeIdSame :
	public IExample
{
public:
	IsTypeIdSame();
	int start(int argc, char * argv[]) override;
	~IsTypeIdSame();
};

