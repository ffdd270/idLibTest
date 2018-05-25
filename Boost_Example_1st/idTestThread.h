#pragma once

class idTestThread : public idSysThread
{
public:
	idTestThread();

	int Run() override
	{
		num = 0;
		for (int i = 0; i < 1000000; i++)
		{
			num++;
		}
		return num;
	}

	~idTestThread();
	
	int num;
};

