#include "stdafx.h"
#include "idFirstTest.h"


idFirstTest::idFirstTest()
{
}



int idFirstTest::start(int argc, char * argv[])
{
	//Input Num Of Element
	int numOfTempArray;
	std::cout << "Please Input Num Of Element for Temp Array \n";
	std::cin >> numOfTempArray;

	//idTempArray = Set Num Of Element in Runtime. delete will Automatic. 
	//idArray = Set Num Of Element in Compile Time. 
	//idBTree = Binary Tree.
	idTempArray<int> tempArray(numOfTempArray);
	idArray<int, 4> array;
	idBTree<char *, WCHAR *, 4> tree;
	

	ArrayInit(tempArray, array);
	ArrayPrint(tempArray, array);
	TreeTest(tree);

	return 0;
}

void idFirstTest::TreeTest(idBTree<char *, WCHAR *, 4> &tree)
{
	char * english[] = {
		"Hello.",
		"Nice to Meet you.",
		"All your base are belong to us. ",
		"C++ Best.",
		"English."
	};

	WCHAR * korean[] = {
		L"안녕하세요.",
		L"만나서 반갑습니다.",
		L"모든 너 기지 다 내꺼다요.",
		L"C++ 최고!",
		L"한국어. "
	};

	tree.Init();

	int index = 0;

	for (auto & koreanString : korean)
	{
		tree.Add(&english[index], koreanString);
		index++;
	}

	for (auto & koreanString : korean)
	{
		std::cout << "Key : " << koreanString << " ";
		std::cout << "Value : " << *tree.Find(koreanString) << std::endl;
	}

	std::cout << "Error Checking. Wrong Key : " << tree.Find(L"오류다.") <<std::endl;
}

void idFirstTest::ArrayPrint(idTempArray<int> &tempArray, idArray<int, 4> &array)
{
	std::cout << "Temp Array Size : " << tempArray.Num() << " Temp Array Element : \n";

	//구간 지정 루프는 Begin과 End 메서드가 있어야 돌아간다. 
	//id는 그런 거 없으므로 직접 만들었다. 
	for (int & i : tempArray)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::cout << "Array Size :  " << array.Num() << " Array Element : \n";

	for (int & i : array)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;
}

void idFirstTest::ArrayInit(idTempArray<int> &tempArray, idArray<int, 4> &array)
{

	for (int i = 0; i < tempArray.Num(); i++)
	{
		tempArray[i] = rand() % tempArray.Num();
	}

	for (int i = 0; i < array.Num(); i++)
	{
		array[i] = rand() % array.Num();
	}
}


idFirstTest::~idFirstTest()
{
}
