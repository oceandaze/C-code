// test1122.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	String s1("姓名：");
	s1.cat("小明");
	s1.cat("\n年龄：");
	s1.cat(18);
	s1.cat("\n身高：");
	s1.cat(18.5);
	s1.cat("m");
	s1.output();

	String s2("1234");
	cout << boolalpha << s2.equal("1234") << endl;
	cout << boolalpha << s2.equal(s1) << endl;

	
    return 0;
}

