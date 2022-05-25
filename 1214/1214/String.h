#pragma once
class String
{
public:
	String();
	String(const char * s);
	~String();
	void cat(const char * sc);
	void output();
	int size();
private:
	char *str;
};

