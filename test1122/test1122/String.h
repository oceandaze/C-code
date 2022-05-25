#pragma once

class String
{
public:
	String(const char *str = nullptr);
	String(const String &other);
	~String();

	void cat(const char* str);
	void cat(int val);
	void cat(double val);
	void output() const;
	bool equal(const char* str) const;
	bool equal(const String &other) const;
private:
	char *p;
};

