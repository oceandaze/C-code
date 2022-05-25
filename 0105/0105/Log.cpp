#include "stdafx.h"
#include "Log.h"
#include <ctime>
#include <iostream>
using namespace std;


Log::Log()
{
	fopen_s(&fp, "0105.log", "w");
}


Log::~Log()
{
	fclose(fp);
}

void Log::info( const char * fileName, int line, const char * msg)
{
#ifdef _DEBUG
	fileName += strlen(fileName) - 1;
	while (*fileName != '\\') {
		--fileName;
	}
	++fileName;
#endif

	char buffer[128] = { 0 };
	const char *pTime = getTime();
	sprintf_s(buffer, sizeof(buffer),
		"%s INFO %s %s:%d\n",
		pTime, msg, fileName, line);

	cout << buffer;

	fprintf(fp, buffer);
	fflush(fp);
}
const char * Log::getTime() const
{
	time_t _time = time(nullptr);//获取系统时间
	tm _tm;
	localtime_s(&_tm, &_time);

	static char buffer[24];
	sprintf_s(buffer, sizeof(buffer),
		"%d-%02d-%02d %02d:%02d:%02d",
		_tm.tm_year + 1900, _tm.tm_mon + 1, _tm.tm_mday,
		_tm.tm_hour, _tm.tm_min, _tm.tm_sec);
	return buffer;
}