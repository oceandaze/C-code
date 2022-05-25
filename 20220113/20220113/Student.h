#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student(const string &name,int age);

	friend ostream &operator<<(ostream &out, const Student &stu);
private:
	string  name;
	int     age;
};

