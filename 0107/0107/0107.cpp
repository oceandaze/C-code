// 0107.cpp : 定义控制台应用程序的入口点。
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
		//throw Exception(1, "除数为0");
		throw string("除数为0");
	}
	return a / b;
}

int main1()
{
	cout << "开始计算\n";
	try
	{
		Divide(1, 0);
		cout << "正常计算完成" << endl;
	}
	catch (int e)
	{
		
		cout << "错误码：" <<e<< endl;
	}
	catch (double e)
	{

		cout << "错误码1：" << e << endl;
	}
	catch(const char * p)
	{

		cout << "错误码描述:" << p << endl;
	}
	catch (Exception &e)
	{
		cout << "错误码：" << e.getCode() << "\n错误描述：" << e.what() << endl;
	}
	catch (...) 
	{		
		cout << "其他异常\n";
	
	}
	cout << "正常退出\n";
    return 0;
}

int main2() 
{
	string s1="hello world!";
	//cout << "请输入数据：" << endl;
	//cin >> s1;
	//cout << "输出的信息：" << s1 << endl;

	cout << "s1=" << s1 << endl;
	cout << "s1.size()=" << s1.size() << endl;
	cout << "s1.length()="<< s1.length()<< endl;
	cout << "s1.empty()=" << boolalpha << s1.empty() << endl;
	cout << "s1[1]" << s1[1] << endl;
	cout << "s1.at(2)" << s1.at(2) << endl;

	//下标遍历
	cout << "下标遍历一般用法";
	for (size_t i = 0; i < s1.size(); i++) {//typedef unsigned int size_t
		cout << s1[i] << " ";

	}
	cout << endl;
	cout << "范围遍历（C++11）：";
	for (auto i : s1)
	{
		cout << i << " ";
	}
	cout << endl;


	return 0;
}


/*
1、输入字符串，统计其中的小写英文字母的个数。
2、输入字符串，将其中的大写英文字母改为小写（其它字符不变），再输出。*/

int main3()
{
	string s1;
	cout << "请输入一串字符" << endl;
	cin >> s1;
	size_t cnt=0;
	for (auto i : s1) {
		 if (islower(i))
		 {
			 cnt++;
		 }
	}
	cout << "s1中小写英文字母个数为：" << cnt << endl;
	return 0;
}

int main4()
{
	string s1;
	cout << "请输入一串字符" << endl;
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


/*1、有字符串”小明, 男, 20”，用string类将其拆为一个字符串数组。*/
void test1()
{
	string s1 = "小明,男,20";
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
/*2、有字符串”1001110110”，统计其中0和1的个数，并将每个元素求和。*/
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
	cout << "0个数为：" << cnt0 << endl;
	cout << "1个数为：" << cnt1 << endl;
	cout << "元素和" << sum << endl;
}

/*3、实现一个函数用来判断一个字符串是否对称，例如aa1bb。*/
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

/*4、有字符串’’111* aaa eeiie”，只输出字符和数字。*/

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
/*5、编写一个程序，将下面一段文本中的各个单词的字母顺序翻转。
”To are not be do” 转换为”oT era ton eb od*/string test5(const string &s){	string ret = "";	string tmp;	size_t start = 0;	size_t end = 0;	size_t len = 0;	while (true){
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
	cout << "回文串" << boolalpha<<test3(s)<<endl;
	test4();

	string s5 = "To are not be do";
	string ret = test5(s5);
	cout << ret << endl;
	return 0;
}