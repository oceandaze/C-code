// TestDll.cpp : ���� DLL Ӧ�ó���ĵ���������
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
