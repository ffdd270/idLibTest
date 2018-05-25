#include "stdafx.h"
#include "IsTypeIdSame.h"

using namespace std;

auto DoSomething(int arr[4])
{
	cout << "int arr[4]의 타입은 : " << typeid(arr).name() << std::endl;
	return typeid(arr).hash_code();
}

IsTypeIdSame::IsTypeIdSame()
{
}

int IsTypeIdSame::start(int argc, char * argv[])
{
	int arr[4];
	int compare[4];

	auto hashCode = DoSomething(arr);

	if (typeid(arr).hash_code() == typeid(compare).hash_code())
	{
		printf("arr == compare \n");
	}
	if (typeid(arr).hash_code() == hashCode)
	{
		printf("arr == int arr[4]\n");
	}


	cout << "arr의 타입은 : " << typeid(arr).name() << std::endl;
	cout << "compare의 타입은 : " << typeid(compare).name() << std::endl;

	return 0;
}


IsTypeIdSame::~IsTypeIdSame()
{
}
