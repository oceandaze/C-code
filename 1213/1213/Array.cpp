#include "stdafx.h"
#include "Array.h"
#include <iostream>

using namespace std;

Array::Array(int t[][5], int n,int m)
{	 
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			a[i][j] = t[i][j];
		}
	}
	row = n;
	col = m;
	memset(b,0,sizeof(float)*m);
	for (int i=0;i<m;i++)
	{
		cout << b[i] << endl;
	}
}

void Array::avg()
{

	
	for (int i=0;i<col;i++)
	{
		float sum = 0;
		for (int j=0;j<row;j++)
		{
			sum = sum + a[j][i];
		}
		b[i] = sum / row;
	}

}

void Array::show()
{
	cout <<"a数组" <<"\n";
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "b数组" << "\n";
	for (int i=0;i<col;i++)
	{
		cout << b[i] << "\t";
	}
}

Array::~Array()
{
}
