#include "stdafx.h"
#include "CWelcomeC17.h"
#include <fstream>
#include <future>


CWelcomeC17::CWelcomeC17()
{
}




auto CoFunc(int n) ->std::experimental::generator<uint64>
{
	std::cout << "The Answer All Universe, Life, and Everything.";

	uint64 f1 = 0;
	uint64 f2 = 1;

	for (int i = 0; i < n; ++i) {
		co_yield f1;

		uint64 f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	co_return;
}

std::future<void> DrawPoint() {

	co_return; 
}

auto LoadTextFile(std::string fileName )->std::future<std::string>
{
	std::string returnValue;
	std::ofstream file{fileName};
	co_await std::async([&]() {
		while (file.is_open());

		while (file.eof())
		{
			file << returnValue;
		}
		return returnValue;
	});
	co_return returnValue;
}

int CWelcomeC17::start(int argc, char * argv[])
{
	uint64 temp;
	//std::variant. 다양한 값을 받을 수 있다.
	std::variant<int, std::string> i;

	auto string = LoadTextFile("bigbigbig.txt");

	//std:: 코-루틴.
	for (uint64 num : CoFunc(1000000))
	{
		//std::cout << num << std::endl;
	}


	while (!string.valid())
	{

	}
	return 0;
}

CWelcomeC17::~CWelcomeC17()
{
}