#include "stdafx.h"
#include "String.h"
#include <iostream>
using namespace std;

String::String(const char *str)
{
	if (str != nullptr) {
		int len = strlen(str) + 1;
		p = new char[len];
		strcpy_s(p, len, str);
	}
	else {
		p = nullptr;
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

void String::cat(const char * str)
{
	if (str == nullptr) {
		return;
	}
	int len = strlen(str) + 1;
	if (p != nullptr) {
		len += strlen(p);
	}

	char *ptr = new char[len];
	memset(ptr, 0, len);
	if (p != nullptr) {
		strcpy_s(ptr, len, p);
		delete[] p;
	}
	strcat_s(ptr, len, str);
	p = ptr;
}

void String::cat(int val)
{
	char buffer[24] = { 0 };
	sprintf_s(buffer, sizeof(buffer), "%d", val);
	cat(buffer);
}

void String::cat(double val)
{
	char buffer[512] = { 0 };
	sprintf_s(buffer, sizeof(buffer), "%.2f", val);
	cat(buffer);
}

void String::output() const
{
	if (p != nullptr) {
		cout << p << endl;
	}
}

bool String::equal(const char * str) const
{
	if (str == nullptr && p == nullptr) {
		return true;
	}

	if (str != nullptr && p != nullptr) {
		return strcmp(str, p) == 0;
	}

	return false;
}

bool String::equal(const String & other) const
{
	return equal(other.p);
}
