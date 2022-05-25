#include "stdafx.h"
#include "Student.h"
#include <iostream>
using namespace std;


Student::Student()
{
	strcpy_s(m_name,"小明");
	m_age = 15;
}
Student:: Student(const char *n, int a)
{
	strcpy_s(m_name, n);
	m_age = a;
}
Student::Student(const Student&p)
{
	m_age = p.m_age;
	strcpy_s(m_name, p.m_name);
}
void Student::input(const char * n, int a)
{
	strcpy_s(m_name, n);
	m_age = a;
}

void Student::output()
{
	cout << "姓名:" << m_name
		<< "\n年龄:" << m_age << endl;
}

void Student::infoCopy(const Student & p)
{
	strcpy_s(m_name, p.m_name);
	m_age = p.m_age;
}
bool Student::ageCompare(const Student &p)
{
	return m_age > p.m_age ? true : false;
}




