#pragma once
class idCommon
{
public:
	idCommon();

	void Init();
	void Warning(const char * str, ...);
	void VPrintf(const char * fmt, const char * argPtr);
	void FatalError(const char * str, ...);
	void Error(const char * str, ...);
	~idCommon();

private:

};
