#pragma once
#include  <iostream>

using namespace std;
template<class T>
class Vector
{
public:
	Vector()
	{
		data = nullptr;
		pos = 0;
	}
	Vector(const T * p,int cnt)
	{
		if (p != nullptr){
			pos = cnt;
			data = new T[pos];
			for (int i=0;i<pos;++i)
			{
				data[i] = p[i];
			}
		}
		else{
			pos = 0;
			data = nullptr;
		}
	}
	Vector(const Vector & other)
		: Vector(other.data, other.pos)
	{
	}
	~Vector()
	{
		if (data!=nullptr){
			delete[]data;
			data = nullptr;
		}
	}

	int size()	const
	{
		return pos;
	}
	void push_back(const T &v)
	{
		T *p = new T[pos + 1];
		for (int i = 0; i < pos; ++i) {
			p[i] = data[i];
		}

		if (data != nullptr) {
			delete[] data;
		}
		data = p;
		data[pos++] = v;
	}

	T at(int index) const
	{
		//异常处理
		return data[index];
	}
	T front() const
	{
		return data[0];
	}

	T back() const
	{
		return data[pos - 1];
	}

	bool empty() const
	{
		return pos == 0;
	}
	bool equal(const Vector & other) const
	{
		if (size() != other.size()) {
			return false;
		}
		for (int i = 0; i < pos; ++i) {
			if (data[i] != other.data[i]) {
				return false;
			}
		}

		return true;
	}
	void output() const
	{
		if (data != nullptr) {
			for (int i = 0; i < pos; ++i) {
				cout << data[i] << " ";
			}
			cout << endl;
		}
	}
	void erase(int index)
	{
		if (index < 0 || index >= size()) {
			return;
		}

		for (int i = index; i < pos - 1; ++i) {
			data[i] = data[i + 1];
		}
		--pos;
	}
	T &operator[](int index)
	{
		try
		{
			if (index < 0 || index >= pos)
			{
				throw - 1;
			}
			else
			{
				throw 1;
			}
		}
		catch (int e)
		{
			if (e == -1)
			{
				cout << "下标越界";
			}
			else
			{
				return data[index];
			}
		}

	}

	const T operator[](int index) const
	{
		try
		{
			if (index < 0 || index >= pos)
			{
				throw - 1;
			}
			else
			{
				throw 1;
			}
		}
		catch (int e)
		{
			if (e == -1)
			{
				cout << "下标越界";
			}
			else
			{
				return data[index];
			}
		}
	}

private:
	T *data;
	int pos;
};