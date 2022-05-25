#include "stdafx.h"
#include "String.h"
#include <iostream>
using namespace std;

String::String(const char * str)
	: p(nullptr)
{
	if (str != nullptr) {
		int len = strlen(str) + 1;
		p = new char[len];
		strcpy_s(p, len, str);
	}
}

String::String(const String & other)
	: String(other.p)
{

}

String::~String()
{
	if (p != nullptr) {
		delete[] p;
	}
}

void String::output() const
{
	if (p != nullptr) {
		cout << p << endl;
	}
}

String &String::operator+=(const char *str)
{
	if (str == nullptr) {
		return *this;
	}

	int len = strlen(str) + 1;
	if (p != nullptr) {
		len += strlen(p);
	}
	char *p1 = new char[len];
	memset(p1, 0, len);
	if (p != nullptr) {
		strcpy_s(p1, len, p);
		delete[] p;
	}
	strcat_s(p1, len, str);
	p = p1;

	return *this;
}

String String::operator+(const char *str) const
{
	String temp = *this;
	temp += str;
	return temp;
}

char &String::operator[](int index)
{
	//异常处理
	return p[index];
}

const char &String::operator[](int index) const
{
	//异常处理
	return p[index];
}