#pragma once
#include <iostream>

using namespace std;

template<class T>
class Queue
{
public:
	Queue()
	{
		data = nullptr;
		pos = 0;
	}

	~Queue()
	{
		if (data != nullptr)
		{
			delete[] data;
		}
	}

	T font() const // ��ȡͷ��Ԫ��
	{
		if (data!=nullptr)
		{
			return data[0];
		}
	}
	T back() const //��ȡβ��Ԫ��
	{
		if (data != nullptr)
		{
			return data[pos-1];
		}
	}
	void push(const T &n)//β������Ԫ��
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
			for (int i=0;i<pos;++i){
				p[i] = data[i];
			}
			delete[] data;
			data = p;
			p = nullptr;
			data[pos++] = n;
		}
	}
	void pop()//ɾ��ͷ��Ԫ��
	{
		if (data == nullptr) {
			return;
		}
		for (int i = 0; i < pos - 1; ++i) {
			data[i] = data[i + 1];
		}
		--pos;
	}

	void popTail()//ɾ��β��Ԫ��
	{
		--pos;
	}

	bool empty() const//�ж϶����Ƿ�Ϊ��
	{
		if (pos==0)
		{
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