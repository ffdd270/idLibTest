#include "stdafx.h"
#include "TestIdLib.h"
#include "idlib\Lib.h"
#include "idTestThread.h"
TestIdLib::TestIdLib()
{
}

int TestIdLib::start(int argc, char * argv[])
{
	thread = new idTestThread();

	TestQuicksort();
	TestMath();
	TestThread();


	bool is = thread->IsRunning();

	while (!thread->IsRunning());
	
	std::cout << std::endl << thread->num << std::endl;

	TestTree();

	return 0;
}


TestIdLib::~TestIdLib()
{
	delete thread;
}

void TestIdLib::TestQuicksort()
{
	idArray<int, 30000> toSortArray;
	idHashTable<int> tables;
	idArray<int, 30000> usedIndex;
	int endIndex = 0; 
	
	
	for (int i = 0; i < toSortArray.Num(); i++)
	{
		toSortArray[i] = i;
	}

	srand(GetTickCount());

	for (int i = 0; i < toSortArray.Num(); i++)
	{
		int secondIndex = rand() % 30000;
		int firstIndex = rand() % 30000;
		int temp;
		temp = toSortArray[firstIndex];
		toSortArray[firstIndex] = toSortArray[secondIndex];
		toSortArray[secondIndex] = temp;
	}



	idSort_QuickDefault<int> qSort;
	qSort.Sort(toSortArray.Ptr(), toSortArray.Num());

	for (auto i : toSortArray)
	{
		std::cout << i << " ";
	}


}

void TestIdLib::TestMath()
{
	idVec2 pos;
	idVec6 what;
	

	pos.x = 10;
	pos.y = 20;

	
}

void TestIdLib::TestTree()
{
	int arr[10] = { 0, 1,2,3,4,5,6,7,8,9 };
	idBTree<int, char *, 4> tree;
	
	tree.Init();



	tree.Add(&arr[0], "Zero");
	tree.Add(&arr[1], "One");
	tree.Add(&arr[2], "Two");
	tree.Add(&arr[3], "Three");
	tree.Add(&arr[4], "Four");
	tree.Add(&arr[5], "Five");
	tree.Add(&arr[6], "Six");
	tree.Add(&arr[7], "Seven");
	tree.Add(&arr[8], "Eight");
	tree.Add(&arr[9], "Nine");
	
	
	auto value = tree.Find("Ten");
	std::cout << *value;
}

void TestIdLib::TestThread()
{
	thread->StartThread("Killing In The Name Of", core_t::CORE_ANY);
	thread->IsWorkDone();
}
