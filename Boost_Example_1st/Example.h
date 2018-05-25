#pragma once

class IExample
{
public:
	IExample() {}
	virtual int start(int argc, char *argv[]) = 0;
	void Find(IExample * ptr)
	{
		if (ptr == this)
		{
		}
	}
	~IExample() {}
};
