#pragma once
class Student
{
public:
	Student();
	Student(const char *n, int a);
	Student(const Student &p);
	void input(const char *n, int a);
	void output();
	void infoCopy(const Student &p);
	bool ageCompare(const Student &p);
private:
	char m_name[32];
	int  m_age;

};

