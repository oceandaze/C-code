// 0107.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Exception
{
public:
	Exception(int code, const char *p)
	{
		this->code = code;
		strcpy_s(msg, p);
	}
	
	const char *what() const
	{
		return msg;
	}
	int getCode() const
	{
		return code;
	}
private:
	int code;
	char msg[64];
};

double Divide(int a, int b)
{
	if (b == 0)
	{
		//throw Exception(1, "����Ϊ0");
		throw string("����Ϊ0");
	}
	return a / b;
}

int main1()
{
	cout << "��ʼ����\n";
	try
	{
		Divide(1, 0);
		cout << "�����������" << endl;
	}
	catch (int e)
	{
		
		cout << "�����룺" <<e<< endl;
	}
	catch (double e)
	{

		cout << "������1��" << e << endl;
	}
	catch(const char * p)
	{

		cout << "����������:" << p << endl;
	}
	catch (Exception &e)
	{
		cout << "�����룺" << e.getCode() << "\n����������" << e.what() << endl;
	}
	catch (...) 
	{		
		cout << "�����쳣\n";
	
	}
	cout << "�����˳�\n";
    return 0;
}

int main2() 
{
	string s1="hello world!";
	//cout << "���������ݣ�" << endl;
	//cin >> s1;
	//cout << "�������Ϣ��" << s1 << endl;

	cout << "s1=" << s1 << endl;
	cout << "s1.size()=" << s1.size() << endl;
	cout << "s1.length()="<< s1.length()<< endl;
	cout << "s1.empty()=" << boolalpha << s1.empty() << endl;
	cout << "s1[1]" << s1[1] << endl;
	cout << "s1.at(2)" << s1.at(2) << endl;

	//�±����
	cout << "�±����һ���÷�";
	for (size_t i = 0; i < s1.size(); i++) {//typedef unsigned int size_t
		cout << s1[i] << " ";

	}
	cout << endl;
	cout << "��Χ������C++11����";
	for (auto i : s1)
	{
		cout << i << " ";
	}
	cout << endl;


	return 0;
}


/*
1�������ַ�����ͳ�����е�СдӢ����ĸ�ĸ�����
2�������ַ����������еĴ�дӢ����ĸ��ΪСд�������ַ����䣩���������*/

int main3()
{
	string s1;
	cout << "������һ���ַ�" << endl;
	cin >> s1;
	size_t cnt=0;
	for (auto i : s1) {
		 if (islower(i))
		 {
			 cnt++;
		 }
	}
	cout << "s1��СдӢ����ĸ����Ϊ��" << cnt << endl;
	return 0;
}

int main4()
{
	string s1;
	cout << "������һ���ַ�" << endl;
	cin >> s1;
	for (size_t i = 0; i < s1.size(); i++) {
		
		if (isupper(s1[i]))
		{
			s1[i]+=32;
		}
	}
	cout << s1 << endl;
	return 0;

}


/*1�����ַ�����С��, ��, 20������string�ཫ���Ϊһ���ַ������顣*/
void test1()
{
	string s1 = "С��,��,20";
	//string s1 = "AB,CD,EF,20";
	string s[3];
	size_t start = 0;
	size_t end = 0;
	int m = 0;
	while ((end=s1.find("," ,start))!=string::npos)
	{
		s[m++] = s1.substr(start, end - start);
		start = end + 1;
	}
	if (start<s1.size())
	{
		s[m] = s1.substr(start);
	}
	for (int i=0;i<=m;i++)
	{
		cout << s[i] << endl;
	}
}
/*2�����ַ�����1001110110����ͳ������0��1�ĸ���������ÿ��Ԫ����͡�*/
void test2()
{
	string s1 = "1001110110";
	int cnt0 = 0;
	int cnt1 = 0;
	int sum = 0;
	for (auto i : s1) {
		if (i=='0')
		{
			cnt0++;
		}
		else
		{
			cnt1++;
		}
		sum += i;
	}
	cout << "0����Ϊ��" << cnt0 << endl;
	cout << "1����Ϊ��" << cnt1 << endl;
	cout << "Ԫ�غ�" << sum << endl;
}

/*3��ʵ��һ�����������ж�һ���ַ����Ƿ�Գƣ�����aa1bb��*/
bool test3(const string &s) 
{
	int i = 0;
	int j = s.size()-1;
	for (i,j;i<j;i++,j--)
	{
		if (s[i] != s[j])
		{
			return false;
		}
	}
	return true;
}

/*4�����ַ�������111* aaa eeiie����ֻ����ַ������֡�*/

void test4()
{
	int m = 0;
	string s1 = "111 * aaa eeiie";
	for (size_t i=0;i<s1.size();i++)
	{
		if (isalpha(s1[i]) || isdigit(i))
		{
			s1[m++] = s1[i];
		}
	}
	s1.resize(m);
	cout << s1 << endl;
}
/*5����дһ�����򣬽�����һ���ı��еĸ������ʵ���ĸ˳��ת��
��To are not be do�� ת��Ϊ��oT era ton eb od*/string test5(const string &s){	string ret = "";	string tmp;	size_t start = 0;	size_t end = 0;	size_t len = 0;	while (true){
		end = s.find(" ", start);
		if (end== string::npos){
			len = s.size() - start;
			tmp = s.substr(start, len);
			reverse(tmp.begin(), tmp.end());
			ret += tmp;
			return ret;
		}
		else{
			len = end - start;
			tmp = s.substr(start, len);
			reverse(tmp.begin(), tmp.end());
			ret += tmp + ' ';
			start = end + 1;
		}
	}}int main()
{
	test1();
	test2();
	string s = "aa1bb";
	cout << "���Ĵ�" << boolalpha<<test3(s)<<endl;
	test4();

	string s5 = "To are not be do";
	string ret = test5(s5);
	cout << ret << endl;
	return 0;
}