#pragma once
class Student
{
public:
	Student();
	Student(const char * name, int age);
	Student(const Student&other);
	void input(const char *name, int age);
	void output();
	bool operator<(const Student &other)  const;
	bool operator>(const Student & other) const;
	bool operator==(const Student&other) const;
	bool operator!=(const Student&other) const;


private:
	char name[16];
	int age;
};

