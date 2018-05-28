#include "stdafx.h"
#include "WinThreadTest.h"


WinThreadTest::WinThreadTest()
{
}

struct FileData
{
	int fileLen;
	int textLen;
	char * filePath;
	char * textPath;
	
	~FileData()
	{
		delete [] filePath;
		delete[] textPath;
	}
};

int WinThreadTest::start(int argc, char * argv[])
{
	std::string path = "text.txt";
	std::string text = "Ta-No-Shi!";
	
	FileData * data = new FileData();
	data->textPath = new char[text.length() * sizeof(char) + 1];
	data->filePath = new char[path.length() * sizeof(char) + 1];
	data->textLen = text.length() + 1;
	data->fileLen = path.length() + 1;

	strcpy_s(data->textPath, data->textLen, text.data());
	strcpy_s(data->filePath, data->fileLen, path.data());

	

	CreateThread(NULL, 0, FileCreate, (void *)data, 0, NULL);

	return 0;
}


WinThreadTest::~WinThreadTest()
{
}

DWORD WINAPI WinThreadTest::FileCreate(void * param)
{
	FileData * data = ((FileData *)param);
	printf("%s\n", data->textPath);
	printf("%s", data->filePath);
	//ÀúÀå... 
	delete data;
	return 0;
}
