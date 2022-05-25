// CreateDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "CreateDll.h"
#include <ctime>

DLL_EXPORT const char * getVersion()
{
	char *p = new char[20];
	strcpy_s(p, 20, "Version 2.13");
	return p;
}

DLL_EXPORT int Add(int a, int b)
{
	return a+b;
}
DLL_EXPORT void getTime(char * &buffer)
{
	time_t now_time = time(nullptr);
	tm t_tm;
	localtime_s(&t_tm, &now_time);
	buffer =new char[64];
	asctime_s(buffer,64, &t_tm);
}
