#include "stdafx.h"
#include "ThisPtrSameNew.h"

ThisPtrSameNew::ThisPtrSameNew()
{
}

int ThisPtrSameNew::start(int argc, char * argv[])
{
	
	std::shared_ptr<Testing> obj = std::make_shared<Testing>();

	obj->Test(obj);
	if (obj.get() == obj->TestGetThis())
	{
		cout << "Hello, World(Func Start)" << endl;
	}
	else
	{
		cout << "Diff! (Func Start)" << endl;
	}

	return 0;
}

ThisPtrSameNew::~ThisPtrSameNew()
{
}