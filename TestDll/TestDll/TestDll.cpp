// TestDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "TestDll.h"

DLL_EXPORT int Add(int a, int b)
{
	return a+b;
}

DLL_EXPORT int Minus(int a, int b)
{
	return a-b;
}
