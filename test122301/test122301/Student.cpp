#include "stdafx.h"
#include "Student.h"


Student::Student()
{
}

istream &operator >> (istream &in, Student &stu)
{
	in >> stu.name >> stu.age;
	return in;
}

ostream &operator << (ostream &out, const Student &stu)
{
	out << stu.name << "\t"
		<< stu.age;
	return out;
}
