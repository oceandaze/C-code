#include "stdafx.h"
#include "NormalUser.h"
#include <iostream>
using namespace std;

NormalUser::NormalUser()
{
	strcpy_s(attribute, 32, "��ͨ�û�");
	strcpy_s(userRight, 100, "�鿴���޸�");
	
}


NormalUser::~NormalUser()
{
}

void NormalUser::input()
{
	cout << "����д�û���Ϣ���û��������롢�û���Ŀ¼��\n"
		<< "�������û���  ";
	cin >> name;
	cout << "����������  ";
	cin >> pwd;
	cout << "�������û���Ŀ¼  ";
	cin >> contents;
	
	cout << "������\n";
}

void NormalUser::show()
{
	cout << "������"<<name << "\t" 
		<< "���ԣ�"<<attribute << "\t"
		<<"�û���Ŀ¼��"<<contents << "\t"
		<<"Ȩ���б�"<<userRight<< endl;
}


