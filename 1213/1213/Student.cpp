#include "stdafx.h"
#include "Student.h"
#include<iostream>

using namespace std;

Student::Student()
{
	strcpy_s(m_name, "undefine");
	cout << "�޲ι��캯������" << endl;
}
Student::Student(const char*n)
{
	strcpy_s(m_name,n);
	cout << "�вι��캯��" << endl;
}

Student::~Student()
{
}
