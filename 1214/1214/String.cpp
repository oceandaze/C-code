#include "stdafx.h"
#include "String.h"
#include <iostream>

using namespace std;




String::String()
{
	str = nullptr;
}

String::String(const char * s )
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

String::~String()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
}

void String::cat(const char * sc)
{
	
	if (sc!=nullptr&&str!=nullptr)
	{
		int len = strlen(sc) + strlen(str) + 1;
		char *temp = new char[len];
		strcpy_s(temp, len, str);
		delete[] str;
		str = temp;
		strcat_s(str, len, sc);
	}
	else if(sc != nullptr&&str == nullptr)
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
	if (str!=nullptr)
	{
		cout << str << endl;
	}
	
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
