// 1214.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include "String.h"
using namespace std;

/*
class  String
{
public:
	String(const char *str=nullptr)
	{
		if (str!=nullptr)
		{
			int len = strlen(str) + 1;
			p = new char[len];
			strcpy_s(p, len, str);
		}
		else
		{
			p = nullptr;
		}
		
	}
	void output()
	{
		cout << p << endl;
	}
	
	~String()
	{
		if (p!=nullptr)
		{
			delete[] p;
		}
		cout << "�ͷ�\n";
		
	}
private:
	char*p;
};
*/

int main1()
{
	//String s1("ABC hello");
	//s1.output();
	//String s2;
	//s2.output();
	//String s2[4]; //�����Ĵι��������
	//String*p;//Ϊ�������󲻵��ù������������
// 	String*q=new String; //	���Ͽ��ٵĶ�����ڴ沢δ�ͷţ���Ҫ�ֶ��ͷŲŻ������������
// 	delete q;//�ͷ�q��ָ����ڴ��ϵĶ���
	
	return 0;
}

int main()
{
	String s1("Hello world!");
	//String s1; //�޲����
	s1.cat("ABCD1"); //���ƴ�ӹ���
	s1.output(); //�����Hello world!ABCD1
	cout << s1.size() << endl; //��������ַ�������
	return 0;
}