#include "stdafx.h"
#include "String.h"
#include <iostream>

using namespace std;






String::String(const char * s)
{
	if (s != nullptr)
	{
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy_s(str, len, s);
	}
	else
	{
		str = nullptr;
	}

}
String::String(const String & other)
{
	if (other.str!=nullptr)
	{
		int len = strlen(other.str) + 1;
		str = new char[len];
		strcpy_s(str, len, other.str);
	}
	else
	{
		str = nullptr;
	}
	
}
void String::cat(const char * sc)
{

	if (sc != nullptr&&str != nullptr)
	{
		int len = strlen(sc) + strlen(str) + 1;
		char *temp = new char[len];
		strcpy_s(temp, len, str);
		delete[] str;
		str = temp;
		strcat_s(str, len, sc);
	}
	else if (sc != nullptr&&str == nullptr)
	{
		int len = strlen(sc) + 1;
		str = new char[len];
		strcpy_s(str, len, sc);
	}
	else
	{
		return;
	}

}
void String::output()
{
	if (str != nullptr)
	{
		cout << str << endl;
	}

}
char * String::c_str()
{
	if (str != nullptr)
	{
		return str;
	}
	return nullptr;
	
}
int String::size()
{
	if (str != nullptr)
	{
		return strlen(str);
	}
	else
	{
		return 0;
	}

}
bool String::empty()
{
	if (str!=nullptr)
	{
		return true;
	}
	return false;
}
bool String::equal(const String & other)
{
	return !strcmp(str,other.str);
}

String String::substr(int a, int b)
{
		String s(str+a);
		s.str[b] = '\0';
		return s;
	
}

String::~String()
{
	cout <<str<< "ÊÍ·Å" << endl;
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	
}