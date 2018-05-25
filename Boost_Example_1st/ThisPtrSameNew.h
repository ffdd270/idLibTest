#pragma once
#include "Example.h"
#include <iostream>
#include <memory>

using namespace std;

class Testing
{
public:
	void Test(std::shared_ptr<Testing> obj)
	{
		if (this == obj.get())
		{
			cout << "Hello, World!(Func Test)" << endl;
		}
		else
		{
			cout << "Diff!(Func Test)" << endl;
		}
	}

	Testing * TestGetThis()
	{
		return this;
	}
};

class ThisPtrSameNew :public IExample
{
public:
	ThisPtrSameNew();
	virtual int start(int argc, char * argv[]) override;
	~ThisPtrSameNew();
};
