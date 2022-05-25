// 0111.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <xfunctional>
#include <string>
#include "Student.h"
#include <fstream>
using namespace std;

int main1()
{
	vector <int> v1;
	v1.push_back(2);
	v1.push_back(-1);
	v1.push_back(11);
	cout << "v1[1]" << v1[1] << endl;
	cout << "v1.at()" << v1.at(1) << endl;
	cout << "v1.size()" << v1.size() << endl;
	cout << "v1.empty()" << v1.empty() << endl;
	cout << "下标遍历" << endl;
	for (int i=0;i<v1.size();++i){
		cout << v1[i] << " ";
	}
	cout << "\n范围遍历" << endl;
	for (auto i:v1){
		cout << i << " ";
	}
	cout << "\n迭代器遍历" << endl;
	for (auto iter = v1.begin(); iter != v1.end();++iter) {
		cout << *iter << " ";
	}
	

    return 0;
}



void output(const vector<int> &v1)
{
	for (auto i : v1) {
		cout << i << " ";
	}
}
int main2()
{
	vector <int> v1 = { 1,2,1,5,4,1,6 };
	for (auto iter = v1.begin(); iter != v1.end();) {
		if (*iter == 1)
		{
			iter=v1.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	output(v1);
	return 0;
}

int main3()
{
	vector<int> v1 = { 99,33,1,45,6 };
	sort(v1.begin(), v1.end());
	output(v1);
	cout << endl;
	sort(v1.begin(), v1.end(),greater<int>());

	output(v1);
	return 0;

}
// 
// void split(const string &s, const string &sp, vector<string> &arr)
// {
// 	size_t left = 0;
// 	size_t pos = 0;
// 	while ((pos=s.find(sp,left)) !=string::npos)
// 	{
// 		arr.push_back(s.substr(left, pos - left)) ;
// 		left = pos + sp.size();
// 	}
// 	if (left<s.size())
// 	{
// 		arr.push_back(s.substr(left));
// 	}
// }

void split(const string &s, const string &sp, vector<string> &v)
{
	size_t left = 0;
	size_t pos = 0;
	while ((pos = s.find(sp, left)) != string::npos)
	{
		v.push_back(s.substr(left, pos - left));
		left = pos + sp.size();
	}
	if (left < s.size())
	{
		v.push_back(s.substr(left));
	}
}
void output1(const vector<string> &v1)
{
	for (auto i : v1) {
		cout << i << " ";
	}
}
int main4()
{
	string s1 = "Abc:,ksj:,sdj";
	vector<string> v1;
	split(s1, ":,", v1);
	output1(v1);
	return 0;
}


int main5()
{
	vector<Student> arr;
	arr.push_back(Student("小黑", 20));
	arr.push_back(Student("小白", 18));
	arr.push_back(Student("小红", 22));
	sort(arr.begin(), arr.end());
	
	for (auto i: arr)
	{
		cout << i << endl;
	}

// 	Student s("小黑", 20);
// 	cout << s << endl;

	return 0;
}

int main6()
{
	vector<int> v1 = { 1,2,3,3,4,4,6,7,8,9 };
	vector<int>::iterator pos;
	pos = unique(v1.begin(), v1.end());
	output(v1);
	cout <<endl;
	cout << *pos<<endl;
// 	sort(v1.begin(), v1.end(), greater<int>());
// 
// 	output(v1);
	return 0;

}


int main()
{
// 	string str ;
// 	string sp ;
// 	cout << "请输入姓名 性别 年龄 家乡" << endl;
// 	cin >> str;
// 	cout << "请输入分隔符" << endl;
// 	cin >> sp;
	string str = "小明;男;20;陕西西安";
	string sp = ";";
	vector<string> v;
	ofstream file("1.txt");
	split(str, sp, v);
	for (auto i : v)
	{
		file << i << endl;
	}
	return 0;
}