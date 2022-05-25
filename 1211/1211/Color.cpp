#include "stdafx.h"
#include "Color.h"
#include <iostream>

using namespace std;
void Color::setName(const char * n)
{
	strcpy_s(m_name, n);
}
void Color::infoShow()
{
	cout <<"ÑÕÉ«Ãû³Æ£º"<< m_name << endl;
}
