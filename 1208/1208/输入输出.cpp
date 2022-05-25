#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include <stdio.h>
using namespace std;
int GetMax(int *arr,int n)
{
	//int n = sizeof(arr) / sizeof(arr[0]);
	int max = INT_MIN;
	for (int i=0;i<n;i++)
	{
		if (max<arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}
char GetGrade(int score)
{
	if (score<60)
	{
		return 'D';
	}
	else if (score < 80)
	{
		return 'C';
	}
	else if (score<90)
	{
		return 'B';
	}
	else
	{
		return 'A';
	}
}
void GetNum(int* arr, int n, int &max, int &min,double &aver)
{
	double sum=0;
	for (int i=0;i<n;i++)
	{
		if (max<arr[i])
		{
			max = arr[i];
		}
		if (min>arr[i])
		{
			min = arr[i];
		}
		sum += arr[i];
	}
	aver = sum / n;
}
int GetAlphaCnt(char * str)
{
	int i = 0;
	int cnt=0;
	while (str[i]!='\0')
	{
		if (islower(str[i]))
		{
			cnt++;
		}
		i++;
	}
	return cnt;
}
void ChangeAtoa(char*str)
{
	int i = 0;
	while (str[i]!='\0')
	{
		if (isupper(str[i]))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
}
void StrReverse(char * str)
{
	char*p = NULL;
	char*q = NULL;
	 for (p=str,q=str+strlen(str)-1;p<q;p++,q--)
	 {
		 char temp = *p;
		 *p = *q;
		 *q = temp;
	 }
}
int main()
{
	//输出流对象
	/*乘法口诀表*/
// 	for (int i = 1; i <= 9; i++)
// 	{
// 		for (int j = 1; j <= i; j++)
// 		{
// 			cout << j << "*"
// 				<< i << "=" << setw(2) << setfill('0')
// 				<< j*i << "\t";
// 		}
// 		cout << endl;
// 	}
	//输入流对象
// 	int a;
// 	double b;
// 	char str[64] = {0};
// 	string s = "C++";
// 	cin >> a >> b >>str;
// 
// 	cout << a << endl
// 		<< b << endl
// 		<< str << endl;
		//cout<<s<<endl;
	
//1、输入三个数，求最大值
// 	int arr[3] = {0};
// 	cout << "请输入三个数" << endl;
// 	for (int i=0;i<3;i++)
// 	{
// 		cin >> arr[i];
// 	}
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int max=GetMax(arr,n);
// 	cout << max << endl;

//2、输入一个成绩，打印相应等级
	/*cout << "请输入一个成绩" << endl;
	int score;
	cin >> score;
	char grade = GetGrade(score);
	cout << "你获得了" << grade << endl;*/
	

//3、输入10个数，求其最大最小和平均值
	/*cout << "请输入10个数" << endl;
	int arr[10] = {0};
	for (int i=0;i<10;i++)
	{
		cin >> arr[i];
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	int max=INT_MIN;
	int min=INT_MAX;
	double aver;
	GetNum(arr,n,max,min,aver);
	cout << "max="<<max <<"\nmin="<< min <<"\naver="<< aver << endl;*/

//4、编一程序，输入一行字符串，统计其中的小写英文字母个数。
	/*cout << "请输入一行字符串"<< endl;
	char str[100] = { 0 };
	cin >> str;
	int cnt = GetAlphaCnt(str);
	cout << cnt;*/

//5、编一程序，输入一行字符号串，将其中的大写英文字母改为小写，再输出。
	/*cout << "请输入一行字符串" << endl;
	char str[100] = {0};
	cin >> str;
	ChangeAtoa(str);
	cout << str;*/
// 14、编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 
// 的形式给出。不要给另外的数组分配额外的空间，你必须原地修改输入数组。
// 示例：输入 abc123 输出321cba

// 	char str[100] = { 0 };
// 	cin >> str;
// 	StrReverse(str);
// 	cout << str;
	string str1 = "hello world";
	int n = str1.length();
	cout << n;
	return 0;
}

