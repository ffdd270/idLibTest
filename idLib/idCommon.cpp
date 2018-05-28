#include "precompiled.h"
#include "idCommon.h"

idCommon::idCommon()
{
}

void idCommon::Init()
{

}

void idCommon::Warning(const char * str, ...)
{
	va_list list;
	char text[MAX_STRING_CHARS];

	va_start(list, str);
	idStr::vsnPrintf(text, sizeof(text), str, list);
	va_end(list);

}

void idCommon::VPrintf(const char * fmt, const char * argPtr)
{
}

void idCommon::FatalError(const char * str, ...)
{
}

void idCommon::Error(const char * str, ...)
{
}

idCommon::~idCommon()
{
}