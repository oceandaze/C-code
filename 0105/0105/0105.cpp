// 0105.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Log.h"
#include <Windows.h>
#define V 2
#include "test.h"
#define STR(x) #x
#define CALL(n) test##n()


using namespace std;


// void test1()
// {
// 	cout << "test1" << endl;
// }
// void test2()
// {
// 	cout << "test2" << endl;
// }

// int main1()
// {
// #if V==1
// 	cout << "1" << endl;
// #elif V==2
// 	cout << "2" << endl;
// #else
// 	cout << "3" << endl;
// #endif
// 
// #ifdef _AB1
// 	cout << "调试模式" << endl;
// #else 
// 	cout << "发布模式" << endl;
// #endif
// 
// 	Output();
// 
// 	cout << STR(hellow world!) << endl;
// 
// 	CALL(1);
// 	CALL(2);
// 
// 	cout << __DATE__ << endl;
// 	cout << __TIME__ << endl;
// 	cout << __FILE__ << endl;
// 	cout << __FUNCTION__ << endl;
// 	cout << __LINE__ << endl;
//     return 0;
// }

Log g_log;

void test1()
{
	LOG_INFO("test1进入");
	LOG_INFO("test1离开");
}

void test2()
{
	LOG_INFO("test2进入");
	LOG_INFO("test2离开");
}

void test3()
{
	LOG_INFO("test3进入");
	LOG_INFO("test3离开");
}

void test4()
{
	LOG_INFO("test4进入");
	for (int i = 0; i < 10; ++i) {
		LOG_INFO("等待网络恢复...");
		Sleep(1000);
	}
	LOG_INFO("test4离开");
}

void test5()
{
	LOG_INFO("test5进入");
	LOG_INFO("test5离开");
}

void test6()
{
	LOG_INFO("test6进入");
	int *ptr = nullptr;
	*ptr = 10;
	LOG_INFO("test6离开");
}

int main()
{
	LOG_INFO("程序启动, V1.0.0.1 ^_^");
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	LOG_INFO("程序退出");
	return 0;
}