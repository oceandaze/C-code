// TestCallDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <TestDll.h>
/*#include <windows.h>*/
using namespace std;

// typedef int(*FUNADD)(int a, int b);
// typedef int(*FUNMINUS)(int a, int b);
int main()
{

	cout << Add(10,22) << endl;
	cout << Minus(33, 11) << endl;
	system("pause");
// 	HMODULE hModule = LoadLibrary(_T("D:\\TestDll\\TestDll.dll"));
// 	FUNADD add = (FUNADD)GetProcAddress(hModule, "Add");
// 	FUNMINUS minus = (FUNMINUS)GetProcAddress(hModule, "Minus");
// 	cout << add(11, 22) << endl;
// 	cout << minus(22, 6) << endl;
// 	FreeLibrary(hModule);
    return 0;
}

