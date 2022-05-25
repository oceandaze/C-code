#include "stdafx.h"
#include "Student.h"


Student::Student(const string &name,int	age)
{
	this->name = name;
	this->age = age;
}

bool Student::operator<(const Student & other) const
{
	return age<other.age;
}

ostream &operator <<(ostream& out, const Student &other)
{
	out << other.name << " "
		<< other.age;
	return out;
}