#pragma once
#include <iostream>
using namespace std;

class Student
{
public:
	Student();

	bool operator>(const Student &other) const
	{
		return age > other.age;
	}

	bool operator<(const Student &other) const
	{
		return age < other.age;
	}
	friend istream &operator >> (istream &in, Student &stu);
	friend ostream &operator << (ostream &out, const Student &stu);
private:
	char name[16];
	int  age;
};

