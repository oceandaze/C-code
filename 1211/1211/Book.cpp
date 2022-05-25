#include "stdafx.h"
#include "Book.h"
#include <iostream>

using namespace std;

void Book:: input(const char*t, const char *p, const char *a)
{
	strcpy_s(m_title, t);
	strcpy_s(m_price, p);
	strcpy_s(m_author, a);
}
void Book::output()
{
	cout << "书名:" << m_title << endl;
	cout << "作者:" << m_author << endl;
	cout << "价格:" << m_price << endl;
}

Book::Book()
{
	strcpy_s(m_title,"C++.Primer.Plus");
	strcpy_s(m_price,"￥72");
	strcpy_s(m_author, "Stephen Prata");
}

Book::Book(const char * t, const char * p, const char * a)
{
	strcpy_s(m_title, t);
	strcpy_s(m_price, p);
	strcpy_s(m_author, a);
}


