// 0108.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int split(const string &str, const string &sp, string arr[])
{
	size_t start = 0;
	size_t end = 0;
	int m = 0;
	while ((end=str.find(sp,start))!=string::npos)
	{
		arr[m++] = str.substr(start, end - start);
		start = end + sp.size();
	}
	if (start < str.size())
	{
		arr[m++] = str.substr(start);
	}
	return m;		
}
// 输入一行字符串，数据使用 ? 作为分隔符，格式：姓名 ? 性别 ? 年龄 ? 体重 ? 身高，
// 要求输出：
// 姓名：小明
// 性别：男
// 年龄：18
// 体重：76.4kg
// BMI： 正常

void BMI(const string &str)
{
	string arr[6];
	string sp = "？";
	int m=split(str, sp, arr);
	double bmi = stod(arr[3]) / (stod(arr[4])	* stod(arr[4]));
	if (bmi<18.5)
	{
		arr[5]= "消瘦";
	}
	else  if(bmi<24)
	{
		arr[5] = "正常";
	}
	else if(bmi<28)
	{
		arr[5] = "超重";
	}
	else if (bmi<30)
	{
		arr[5] = "肥胖";
	}
	else
	{
		arr[5] = "高度肥胖";
	}

	char *label[] = { "姓名" , "性别" , "年龄" , "体重", "身高","BMI" };

	for (int i = 0; i <=m; i++)
	{
		cout << label[i] << "：" << arr[i] << endl;
	}
}
int main1()
{
	string s = "小明，男，20";
	//s = "AB,CD,20";
	string sp = "，";
	string sarr[10] ;
	int m = split(s, sp, sarr);
	for (int i = 0; i < m; i++)
	{
		cout << sarr[i] << endl;
	}
    return 0;
}

int main2()
{		
	string s = "小明？男？28？78？1.79";
	BMI(s);
	return 0;
}

int main()
{
	string s1 = "abcd1234";

	/*auto  iter = s1.rbegin(); */

	for (auto iter = s1.rbegin(); iter !=s1.rend(); iter++)
	{
		cout << *iter << " ";
	}
	cout <<endl;
	
	cout << endl;
}