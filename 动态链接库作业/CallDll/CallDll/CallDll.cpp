// CallDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

typedef char* (*FUNGETVERSION)();
typedef int(*FUNADD)(int a, int b);
typedef void(*FUNGETTIME) (char * &buffer);
int main()
{
	HMODULE hModule = LoadLibrary(_T("D:\\C++\\C++Code\\动态链接库作业\\CreateDll\\Debug\\CreateDll.dll"));
	FUNGETVERSION version = (FUNGETVERSION)GetProcAddress(hModule, "getVersion");
	FUNGETTIME time = (FUNGETTIME)GetProcAddress(hModule, "getTime");
	cout << version() << endl;
	char *buffer=nullptr;
	time(buffer);
	cout << buffer ;
	FreeLibrary(hModule);
	delete[] buffer;
	return 0;
}


void Set1(char** p, const char* src)
{
	*p = new char[100];
	strcpy_s(*p, 100, src);
}
void Set2(char*& p, const char* src)
{
	p = new char[100];
	strcpy_s(p, 100, src);
}
char* Set3(char* p, const char* src)
{
	p = new char[100];
	strcpy_s(p, 100, src);
	return p;
}

void getTime(char * &buffer)
{
	time_t now_time = time(nullptr);
	tm t_tm;
	localtime_s(&t_tm, &now_time);
	buffer = new char[64];
	asctime_s(buffer, 64, &t_tm);
}
int main2()
{
// 	char* p = nullptr;
// 	Set1(&p, "hello world!");
// 	cout << p << endl;
// 	delete p;
// 	p = nullptr;
// 	Set2(p, "hello world!");
// 	cout << p << endl;
// 	delete p;
// 	p = nullptr;
// 	p = Set3(p, "hello world!");
// 	cout << p << endl;
// 	delete p;
// 	p = nullptr;

	char *buffer = nullptr;
	getTime(buffer);
	cout << buffer;

	return 0;
}