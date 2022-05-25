#pragma once
#include <iostream>
using namespace std;
class String
{
public:
	String(const char * s=nullptr);
	String(const  String &other);
	String( String &&other);

	~String();
	String &operator =(const String &other);
	String &operator =( String &&other);

	void output() const;
	int size()const;
	int length()const;
	bool empty()const;
	char *c_str()const;

	String &operator +=(const String &other);
	String operator +(const String &other) const;

	char & operator[](int index);
	const char & operator[](int index) const;
	bool operator==(const String &other)const;
	bool operator!=(const String &other)const;
	friend ostream &operator<< (ostream &out, const String &other);

private:
	char *str;
};

