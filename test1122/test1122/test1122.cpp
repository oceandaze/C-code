// test1122.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	String s1("������");
	s1.cat("С��");
	s1.cat("\n���䣺");
	s1.cat(18);
	s1.cat("\n��ߣ�");
	s1.cat(18.5);
	s1.cat("m");
	s1.output();

	String s2("1234");
	cout << boolalpha << s2.equal("1234") << endl;
	cout << boolalpha << s2.equal(s1) << endl;

	
    return 0;
}

