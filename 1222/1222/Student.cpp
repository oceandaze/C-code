#include "stdafx.h"
#include "Student.h"
#include <iostream>

using namespace std;



Student::Student()
{
	memset(name,0,sizeof name);
	age = 0;
}

Student::Student(const char * name, int age)
{
	strcpy_s(this->name, name);
	this->age = age;
}

Student::Student(const Student & other)
	:Student(other.name,other.age)
{
}

void Student::input(const char * name, int age)
{
	strcpy_s(this->name, name);
	this->age = age;
}


void Student::output()
{
	cout <<"ĞÕÃû£º"<< name << endl;
	cout << "ÄêÁä£º" << age << endl;
}

bool Student::operator<(const Student & other) const
{
	if (age<other.age)
	{
		return true;
	}
		return false;
}
bool Student::operator>(const Student & other) const
{
	if (age > other.age)
	{
		return true;
	}
	return false;
}
bool Student::operator==(const Student & other) const
{
	if (strcmp(name,other.name)==0)
	{
		return true;
	}
	return false;
}


