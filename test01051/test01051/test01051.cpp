// test01051.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Log.h"
#include <Windows.h>
using namespace std;

Log g_log;

void test1()
{
	LOG_INFO("test1����");
	LOG_INFO("test1�뿪");
}

void test2()
{
	LOG_INFO("test2����");
	LOG_INFO("test2�뿪");
}

void test3()
{
	LOG_INFO("test3����");
	LOG_INFO("test3�뿪");
}

void test4()
{
	LOG_INFO("test4����");
	for (int i = 0; i < 10; ++i) {
		LOG_INFO("�ȴ�����ָ�...");
		Sleep(1000);
	}
	LOG_INFO("test4�뿪");
}

void test5()
{
	LOG_INFO("test5����");
	LOG_INFO("test5�뿪");
}

void test6()
{
	LOG_INFO("test6����");
	int *ptr = nullptr;
	*ptr = 10;
	LOG_INFO("test6�뿪");
}

int main()
{
	LOG_INFO("��������, V1.0.0.1 ^_^");
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	LOG_INFO("�����˳�");
    return 0;
}

