#pragma once
class String
{
public:
	String(const char *p);
	String(const String &other);
	~String();

	void output();
	void cat(const char *str);
	const char *c_str();

	int size();
	bool empty();
	bool equal(const String &other);
	String substr(int pos, int cnt);
private:
	char *p;
};

