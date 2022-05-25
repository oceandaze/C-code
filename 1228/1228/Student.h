#pragma once
#include <iostream>
using namespace std;
class Student
{
public:
	Student();
	~Student();

	void setName(char *name);
	void setAge(int age);
	void setSex(char *sex);
	int getAge()const;

	friend ostream & operator<<(ostream &out, const Student & p);
private:
	char name[32];
	char sex[4];
	int age;
};

