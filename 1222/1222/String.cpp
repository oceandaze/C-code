#include "stdafx.h"
#include "String.h"
#include <iostream>

using namespace std;

String::String(const char * str)
{
	if (str!=nullptr)
	{
		int len = strlen(str) + 1;
		this->str = new char[len];
		strcpy_s(this->str,len, str);
	}
	else
	{
		this->str = nullptr;
	}
}

String::String(const String & other)
	:String(other.str)
{
}

String::~String()
{
	if (str!=nullptr)
	{
		delete[] str;
	}
}

String & String::operator+=(const String & other)
{
	if (other.str == nullptr)
	{
		return *this;
	}
	int len = strlen(other.str) + 1;
	if (str != nullptr)
	{
		len += strlen(str);
	}
	char *temp = new char[len];
	memset(temp, 0, len);
	if (str != nullptr)
	{
		strcpy_s(temp, len, str);
		delete[] str;
	}
	strcat_s(temp, len, other.str);
	str = temp;
	return *this;
}

String  String::operator+(const String & other)	 const
{
	String temp= *this;
	temp += other;
	return temp;
}

char & String::operator[](int index)
{
	return str[index];
}

const char & String::operator[](int index) const
{
	return str[index];
}

void String::output()
{
	cout << str << endl;
}
