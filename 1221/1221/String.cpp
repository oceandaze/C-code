#include "stdafx.h"
#include "String.h"	 
#include <iostream>

using namespace std;


String::String(char * str)
{
	if (str!=nullptr)
	{
		int len = strlen(str) + 1;
		ret = new char[len];
		strcpy_s(ret, len, str);
	}
	else
	{
		ret = nullptr;
	}
	
}

String::String(String & other)
	:String(other.ret)
{
}

String::~String()
{
	  if (ret!=nullptr)
	  {
		  delete[] ret;
		  ret = nullptr;
	  }
}

void String::cat(int s)
{
	char buffer[11] = {0};
	sprintf_s(buffer, sizeof(buffer), "%d", s);
// 	if (ret != nullptr)
// 	{
// 		int len = strlen(ret) + strlen(buffer)+1;
// 		 char *temp = new char[len];
// 		 sprintf_s(temp, len, "%s%s", ret, buffer);
// 		 delete[]ret;
// 		 ret = temp;
// 		 temp=nullptr;
// 	}
// 	else
// 	{
// 		int len = strlen(buffer) + 1;
// 		char *temp = new char[len];
// 		sprintf_s(temp,len, "%s", buffer);
// 		ret = temp;
// 		temp = nullptr;
// 	}
	cat(buffer);
}

void String::cat(const char * str)
{
	if (str==nullptr)
	{
		return;
	}
	if (ret != nullptr)
	{
		int len = strlen(ret) + strlen(str) + 1;
		char *temp = new char[len];
		sprintf_s(temp, len, "%s%s", ret, str);
		delete[]ret;
		ret = temp;
		temp = nullptr;
	}
	else
	{
		int len = strlen(str) + 1;
		char *temp = new char[len];
		sprintf_s(temp, len, "%s", str);
		ret = temp;
		temp = nullptr;
	}

}

void String::cat(double s)
{
	char buffer[20] = { 0 };
	sprintf_s(buffer, sizeof(buffer), "%.2f", s);
// 	if (ret != nullptr)
// 	{
// 		int len = strlen(ret) + strlen(buffer) + 1;
// 		char *temp = new char[len];
// 		sprintf_s(temp, len, "%s%s", ret, buffer);
// 		delete[]ret;
// 		ret = temp;
// 		temp = nullptr;
// 	}
// 	else
// 	{
// 		int len = strlen(buffer) + 1;
// 		char *temp = new char[len];
// 		sprintf_s(temp, len, "%s", buffer);
// 		ret = temp;
// 		temp = nullptr;
// 	}

	cat(buffer);
}

void String::output() const
{
	if (ret!=nullptr)
	{
		cout << ret << endl;
	}
}

bool String::equal(const char * str)
{
	if (ret!=nullptr)
	{
		return !strcmp(ret, str);
	}
	return false;
}

bool String::equal(const String & other)
{
	return equal(other.ret);
}
