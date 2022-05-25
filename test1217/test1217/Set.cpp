#include "stdafx.h"
#include "Set.h"
#include<iostream>

using namespace std;


Set::Set(const int * p, int cnt)
{
	if (p != nullptr)
	{
		data = new int[cnt];
		pos = cnt;
		for (int i=0;i<pos;i++)
		{
			data[i] = p[i];
		}
		sort();
	}
	else
	{
		data = nullptr;
		pos = cnt;
	}
}

Set::Set(const Set & other)
:Set(other.data,other.pos)
{
}

 

Set::~Set()
{		
	if (data!=nullptr)
	{
		delete[] data;
	}
}

void Set::output() const
{
	if (data!=nullptr)
	{
		for (int i = 0; i < pos; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	
}

void Set::sort()
{
	if (data!=nullptr) {
		for (int i = 0; i < pos - 1; ++i) {
			for (int j = 0; j < pos - 1 - i; ++j) {
				if (data[j] > data[j + 1]) {
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	
}

void Set::insert(int n)
{
	if (data!=nullptr)
	{
		for (int i=pos-1;i>=0;i--)
		{
			if (data[i]==n)
			{
				return;
			}
			else if(data[i]<n)
			{
				int *p = new int[pos + 1];
				int j = 0;
				for (j=pos;j>i+1;j--)
				{
					p[j] = data[j-1];
				}
				p[j] = n;
				for (j=i;j>=0;j--)
				{
					p[j] = data[j];
				}
				delete[] data;
				pos = pos + 1;
				data = p;
				p = nullptr;
				break;
			}
		}
	}
	else
	{
		data = new int[++pos];
		data[0] = n;
	}
}

void Set::find(int n)
{
	  if (data!=nullptr)
	  {
		  for (int i=0;i<pos;i++)
		  {
			  if (data[i]==n)
			  {
				  cout << data[i] << endl;
				  return;
			  }
		  }
		  cout << "²éÕÒÊ§°Ü" << endl;
	  }
}

void Set::clear()
{
	pos = 0;
	delete[] data;
	data = nullptr;
}

bool Set::empty()
{
	
	return pos==0;
}

int Set::size()
{
	return pos;
}

void Set::erase(int val)
{
	if (data!=nullptr)
	{
		for (int i=0;i<pos;i++)
		{
			if (data[i]==val)
			{
				for (int j=i;j<pos;j++)
				{
					data[j] = data[j + 1];
				}
				pos = pos - 1;
				return;
			}
		}
	}
}

int Set::count(int val)
{
	int cnt = 0;
	if (data!=nullptr)
	{
		for (int i=0;i<pos;i++)
		{
			if (data[i]==val)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
