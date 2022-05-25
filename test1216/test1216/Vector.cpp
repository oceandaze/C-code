#include "stdafx.h"
#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector()
{
	arr = nullptr;
	n = 0;
}

Vector::Vector(const int * p, int cnt)
{
	cnt = cnt < 0 ? 0 : cnt;
	n = cnt;
	arr = new int[n];
	if (p!=nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = p[i];
		}
	}
	
}

Vector::Vector(const Vector & other)
	:Vector(other.arr,other.n)
{
}


Vector::~Vector()
{
	//cout << "析构函数调用" << endl;
	if (arr!=nullptr)
	{
		delete[] arr;
	}
}



int Vector::size()
{
	return n;
}

void Vector::push_back(int v)
{
	
	int *temp = new int[n+1];
	if (arr != nullptr)
	{
		for (int i = 0; i < n ; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
	}
	temp[n++] = v;
	arr = temp;

}

int Vector::at(int index)
{

	//此处最好写个异常处理
	if (arr != nullptr&&index<n||index>0)
	{
		return arr[index];
	} 
}

int Vector::front()
{
	if (arr != nullptr)
	{
		return arr[0];
	}
}

int Vector::back()
{
	if (arr != nullptr)
	{
		return arr[n-1];
	}
}

bool Vector::empty()
{
	return n==0;
}

bool Vector::equal(const Vector &other)
{
	
	if (n != other.n)
	{
		return false;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != other.arr[i])
		{
			return false;
		}
	}
	
	return true;
	
}
void Vector::output()
{
	if (arr != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

void Vector::erase(int index)
{

	if (arr!=nullptr&&index<n || index>0)
	{
		for (int i = index; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		n = n - 1;
	}
	
}

void Vector::update(int index,int m)
{
	if (arr != nullptr&&index < n || index>0)
	{
		arr[index] = m;
	}
}
