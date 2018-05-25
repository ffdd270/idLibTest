#pragma once
#include "Example.h"
class CWelcomeC17 :
	public IExample
{
public:
	CWelcomeC17();
	int start(int argc, char * argv[]) override;
	~CWelcomeC17();
};
