// 1209.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void BubbleSort(int *arr,int n,int selt)
{
	for (int i=0;i<n-1;++i)
	{
		for (int j=0;j<n-1-i;++j)
		{
			if (selt==1)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			else if (selt == 2)
			{
				if (arr[j] < arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			
		}
	}
}
void PrintArr(int *arr,int n)
{
	for (int i=0;i<n;++i)
	{
		cout << arr[i] << " ";
	}
}
int main1()
{
	int * p = new int;
	int *p1 = new int(50);
	*p = 10;
	cout << *p << endl;
	cout << *p1 << endl;
	delete p;
	delete p1;
	cout << p << endl;
	//p = NULL;
	cout << p1<< endl;
// 
// 	char *str = new char[32];
// 	strcpy_s(str, 32, "hello world!");
// 	cout << str << endl;
// 	delete[] str;
// 
// 	int* arr = new int[10];
// 	for (int i=0;i<10;++i)
// 	{
// 		arr[i] = i;
// 	}
// 	for (int i=0;i<10;++i)
// 	{
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// 	delete[] arr;

// 	int n= 0;
// 	cout << "请输入要输入数据个数" << endl;
// 	cin >> n;
// 	int *arr = new int[n];
// 	for (int i=0;i<n;++i)
// 	{
// 		cin >> arr[i];
// 	}
// 	cout << "请选择排序方式，1升序，2降序" << endl;
// 	int input = 0;
// 	cin >> input;
// 	BubbleSort(arr, n, input);
// 	PrintArr(arr, n);
// 	delete[] arr;
// 	arr = NULL;

// 	char *p1 = nullptr;
// 	if (p1!=nullptr)
// 	{
// 		cout << "指针不为空" << endl;
// 
// 	}
// 	else
// 	{
// 		cout <<"指针为空" << endl;
// 	}

// 	char a1[5] = {0};
// 	//strcpy(a1, "123456789");
// 	//strcpy_s(a1, 5, "123456789");
// 	strcpy_s(a1, 5, "1234");
// 	cout << a1 << endl;
// 	char a[100] = {0};
// 	strcpy_s(a, "12345");
// 	strcat_s(a, "123456789");
// 	cout << a << endl;
// 
// 	char*p = new char[100];
// 	strcpy_s(p,100, "123456789");
// 	strcat_s(p,100,"12345");
// 	cout << p << endl;

// 	char a2[10] = {"0"};
// 	strcat_s(a2, "abc1234");
// 	cout << a2 << endl;


    return 0;
}


int main()
{
	int n = 10;
	int a[] = { 2,3,1,4,5,6,7,8,9 ,10 };
	//int a[n] = { 2,3,1,4,5,6,7,8,9 ,10}; //error	栈区定义数组长度必须为常量值
	int *p = new int[n];//堆区开辟数组空间空间大小可以为变量
	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int i = 0; i < n;++i) {
		cout << p[i]<<" ";
	}
	cout << endl;
}

void Set1(char** p, const char* src)
{
	*p = new char[100];
	strcpy_s(*p, 100, src);
}
void Set2(char*& p, const char* src)
{
	p = new char[100];
	strcpy_s(p, 100, src);
}
char* Set3(char* p, const char* src)
{
	p = new char[100];
	strcpy_s(p, 100, src);
	return p;
}
int main2()
{
 	char* p = nullptr;	
	Set1(&p, "hello world!");
	cout<< p << endl;
	delete p; 
	p = nullptr;
	Set2(p, "hello world!");
	cout << p << endl;
	delete p;
	p = nullptr;
	p=Set3(p, "hello world!");
	cout << p << endl;
	delete p;
	p = nullptr;
	return 0;
}

// 15、请你来实现一个 myAtoi 函数，使其能将字符串转换成整数。
// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
//接下来的转化规则如下：
// 1）如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组
//合起来，形成一个有符号整数。
// 2）假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
// 3）不考虑溢出问题
// ——
// 输入 : "42"
// 	输出 : 42
// 
// 	输入 : "   -42"
// 	输出 : -42
// 
// 	输入 : "4193 with words"
// 	输出 : 4193
// 
// 	输入 : "words and 987"
// 	输出 : 0
int myAtoi(char*str)
{
	int i = 0;
	int flag = 0;
	while (*str==' ')
	{
		str = str + 1;
	}
	if (*str == '-')
	{
		flag = -1;
		str = str + 1;
	}
	else if (isdigit(*str))
	{
		flag = 1;
	}
	else 
	{
		return 0;
	}
	int len = strlen(str);
	int t = 0;
	int num = 0;
	int cnt = 0;
	int maxlong=0;
	while (i < len - 1)
	{
		if (isdigit(str[i]))
		{
			t = t*10+ str[i]-'0';
			cnt++;
			maxlong < cnt ? maxlong = cnt, num = t:0;
		}
		else
		{
			if (flag==1)
			{
				return num;
			}
			else 
			{
				t = 0;
				cnt = 0;
			}
		}
		i++;
	}
	return flag*num ;
}
int main4()
{
	char str[100] = {"  -12wa2314a12bb22312b"};

	int n=myAtoi(str);
	cout << n << endl;
	return 0;

}
