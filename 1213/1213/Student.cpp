#include "stdafx.h"
#include "Student.h"
#include<iostream>

using namespace std;

Student::Student()
{
	strcpy_s(m_name, "undefine");
	cout << "无参构造函数调用" << endl;
}
Student::Student(const char*n)
{
	strcpy_s(m_name,n);
	cout << "有参构造函数" << endl;
}

Student::~Student()
{
}
