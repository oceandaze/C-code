#include "stdafx.h"
#include "String.h"

String::String(const char * s)
	:str(nullptr)
{
	if (s!=nullptr)
	{
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy_s(str,len,s);
	}

}

String::String(const String & other)
	:String(other.str)
{
}

String::String( String && other)
{
	cout << "String( String && other)" << endl;
	str = other.str;
	other.str = nullptr;
}

String::~String()
{
	if (str!=nullptr)
	{
		delete[]str;
		cout << "调用析构函数" << endl;
	}
	//cout << "调用析构函数" << endl;
}

void String::output() const
{
	if (str!=nullptr)
	{
		cout << str << endl;
	}
}

int String::size() const
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

int String::length() const
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

bool String::empty() const
{
	if (str != nullptr)
	{
		return true;
	}
	return false;
}

char * String::c_str() const
{
	return str;
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

String  String::operator+(const String & other) const
{
	String tmp = *this;
	tmp += other;
	return tmp;
}

String & String::operator=(const String & other)
{
	if (str != nullptr)
	{
		delete[]str;
		str = nullptr;
	}
	if (other.str == nullptr)
	{
		return *this;
	}
	int len = strlen(other.str) + 1;
	str = new char[len];
	strcpy_s(str, len, other.str);
	return *this;
}

String & String::operator=(String && other)
{
	cout << "operator=(String &&)" << endl;
	if (str!=nullptr)
	{
		delete[]str;
		str = nullptr;
	}
	str = other.str;
	other.str = nullptr;
	return *this;
}

char & String::operator[](int index)
{
	return str[index];
}
const char & String::operator[](int index) const
{
	return str[index];
}
bool String::operator==(const String & other) const
{
	return strcmp(str, other.str) == 0;
}

bool String::operator!=(const String & other) const
{
	return strcmp(str, other.str) != 0;
}
ostream & operator<<(ostream & out, const String & other)
{
	if (other.str !=nullptr)
	{
		out << other.str;
	}
	
	return out;
}
