#pragma once
#include "Example.h"
class CStyleString :
	public IExample
{
public:
	CStyleString();

	int start(int argc, char * argv[]) override;
	~CStyleString();
};
