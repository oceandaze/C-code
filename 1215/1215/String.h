#pragma once
class String
{
public:
	String(const char * s= nullptr);
	String(const String &other);
	~String();
	void cat(const char * sc);
	void output();
	char *  c_str();
	int size();
	bool empty();
	bool equal(const String &other);
	String  substr(int a, int b);
	
private:
	 char *str;
	 //static char *sstr;
};

