#pragma once
#include "Example.h"
class WinThreadTest :
	public IExample
{
public:
	WinThreadTest();
	int start(int argc, char * argv[]);
	~WinThreadTest();
private:
	static DWORD WINAPI FileCreate(void *);
};

