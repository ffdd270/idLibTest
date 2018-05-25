#pragma once
#include "Example.h"

class idTestThread;

class TestIdLib :
	public IExample
{
public:
	TestIdLib();

	virtual int start(int argc, char * argv[]) override;


	~TestIdLib();
private:
	void TestQuicksort();
	void TestMath();
	void TestTree();
	void TestThread();

	idTestThread * thread;
};

