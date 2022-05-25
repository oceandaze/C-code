#include "stdafx.h"
#include "String.h"
#include <iostream>
using namespace std;

String::String(const char * str)
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
	cout << p << "ÊÍ·Å" << endl;
	if (p != nullptr) {
		delete[] p;
	}
}

void String::output()
{
	if (p != nullptr) {
		cout << p << endl;
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
	char *p1 = new char[len];
	memset(p1, 0, len);
	if (p != nullptr) {
		strcpy_s(p1, len, p);
		delete[] p;
	}
	strcat_s(p1, len, str);
	p = p1;
}

const char * String::c_str()
{
	return p;
}

int String::size()
{
	return p == nullptr ?0 : strlen(p);
}

bool String::empty()
{ 
	return p == nullptr;
}

bool String::equal(const String & other)
{
	return strcmp(p, other.p) == 0;
}

String String::substr(int pos, int cnt)
{
	String temp(nullptr);
	int len = size();
	if (p == nullptr || pos >= len) {
		return temp;
	}
	cnt = cnt > (len - pos) ? len - pos : cnt;
	temp.p = new char[cnt + 1];
	strncpy_s(temp.p,cnt + 1, p + pos, cnt);
	return temp;
}
