// TestCallDll无配置环境测试.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;

typedef int(*FUNADD)(int a, int b);
typedef int(*FUNMINUS)(int a, int b);
int main()
{

	
	HMODULE hModule = LoadLibrary(_T("D:\\TestDll\\TestDll.dll"));
	FUNADD add = (FUNADD)GetProcAddress(hModule, "Add");
	FUNMINUS minus = (FUNMINUS)GetProcAddress(hModule, "Minus");
	cout << add(11, 22) << endl;
	cout << minus(22, 6) << endl;
	FreeLibrary(hModule);
	return 0;
}
