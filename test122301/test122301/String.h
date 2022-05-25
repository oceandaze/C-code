#pragma once

class String
{
public:
	String(const char *str = nullptr);
	String(const String &other);
	~String();

	void output() const;
	String &operator+=(const char *str);
	String operator+(const char *str) const;

	char &operator[](int index);
	const char &operator[](int index) const;
private:
	char *p;
};

