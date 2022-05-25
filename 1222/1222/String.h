#pragma once
class String
{
public:
	String(const char *str=nullptr);
	String(const String & other);
	~String();

	String & operator +=(const String&other );
	String  operator +(const String&other)  const;

	char & operator[](int index);
	const char & operator[](int index) const;
	void output();
private:
	char * str;
};

