// 1207.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <iomanip>
using namespace std;
int test(int a,int b)
{
	int sum = a + b;
	return sum;
}
int main()
{
	int a=0;
	
	a = a + 1;
	int b = a + 2;
	int sum = test(a, b);
	const int n = 5;
	int arr[n] = {1,2,3,4,5};
	for (int i=1;i<=9;i++)
	{
		for (int j=1;j<=i;j++)
		{
			//cout.fill('0');
			//cout.width(2);
			cout << j << "*" << i << "=" << setw(2) << setfill('0')<< i*j << "\t";
		}
		cout << "\n";
	}
// 	for (int i=0;i<n;i++)
// 	{
// 		cin >> arr[i];
// 	}
// 	for (int i=0;i<n;i++)
// 	{
// 		cout << arr[i];
// 	}
//  	cout << a << endl;
// 	cout << b << "\n";
// 	cout << sum << "\n";
    return 0;
}

