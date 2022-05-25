// test01051.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Log.h"
#include <Windows.h>
using namespace std;

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

