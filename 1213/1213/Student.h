#pragma once
class Student
{
public:
	Student();
	Student(const char*n);
	~Student();
private:
	char m_name[32];
};

