#pragma once
#include "Example.h"
class TrashValue :
	public IExample
{
public:
	TrashValue();

	int start(int argc, char * argv[]) override;

	~TrashValue();
};
