#include "stdafx.h"
#include "Student.h"


Student::Student()
{
	memset(name, 0, sizeof(name));
	memset(sex, 0, sizeof(sex));
	age = 0;
}


Student::~Student()
{
}

void Student::setName(char *name)
{
	strcpy_s(this->name, name);
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setSex(char *sex)
{
	strcpy_s(this->sex, sex);
	
}

int Student::getAge() const
{
	return age;
}

ostream & operator<<(ostream & out, const Student & p)
{
	cout <<"������"<<p.name 
		<<" ���䣺"<<p.age
		<<" �Ա�"<<p.sex << endl;
	return out;
}
