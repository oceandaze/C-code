#include "stdafx.h"
#include "Admin.h"
#include <iostream>
using namespace std;


Admin::Admin()
{
	strcpy_s(attribute, 32, "��������Ա");
}


Admin::~Admin()
{
}

void Admin::input()
{
	cout << "����д�û���Ϣ���û��������룩\n"
		<< "�������û���  ";
	cin >> name;
	cout << "����������  ";
	cin >> pwd;
	cout << "������\n";
}

void Admin::show()
{
	cout << "������" << name << "\t"
		<< "���ԣ�" << attribute << endl;
}
