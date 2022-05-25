#include "stdafx.h"
#include "Student.h"

Student::Student(const string & name, int age)
{
	this->name = name;
	this->age = age;
}

ostream &operator<<(ostream &out, const Student &stu)
{
	out << stu.name << " "
		<< stu.age;
	return out;
}