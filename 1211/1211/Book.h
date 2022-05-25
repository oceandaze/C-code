#pragma once
class Book
{
public:
	Book();
	Book(const char*t, const char *p, const char *a);
	void input(const char*t, const char *p, const char *a);

	void output();
	
private:
	char m_title[64];
	char m_price[32];
	char m_author[64];
};

