#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
public:
	Stack()
	{
		data = nullptr;
		pos = 0;
	}

	~Stack()
	{
		if (data!=nullptr)
		{
			delete[] data;
		}

	}

	T top() const
	{
		if (data!=nullptr)
		{
			return data[0];
		}
	}
	void push(const T &n)
	{
		if (data==nullptr)
		{		 
			pos = 1;
			data = new T[pos];
			data[0] = n;
		}
		else
		{
			T *p = new T[pos + 1];
			for (int i=pos;i>0;--i)
			{
				p[pos] = data[pos - 1];
			}
			delete[]data;
			data = p;
			p = nullptr;
			data[0] = n;
			++pos;
		}	
	}
	void pop()
	{
		if (data==nullptr){
			return;
		}
		for (int i=0;i<pos-1;++i){
			data[i] = data[i + 1];
		}
		--pos;
	}
	bool empty()   const
	{
		if (pos==0){
			return true;
		}
		return false;
	}
	int size() const
	{
		return pos;
	}
private:
	T *data;
	int pos;

};