#pragma once
#include <string>
#include <iostream>
using namespace std;
class Student
{
public:
	Student(const string &name, int age);

	bool operator<(const Student&other) const;
	friend ostream &operator <<(ostream& out, const Student &other);
private:
	string name;
	int     age;
};

