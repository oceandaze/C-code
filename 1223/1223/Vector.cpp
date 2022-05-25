#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include <exception>

using namespace std;

Vector::Vector(const int * p, int n)
{
	if (p!=nullptr)
	{
		pos = n;
		data = new int[pos];
		memset(data, 0, pos);
		for (int i=0;i<pos;i++)
		{
			data[i] = p[i];
		}
	}
	else
	{
		pos = 0;
		data = nullptr;
	}
}

Vector::Vector(const Vector & other)
	: Vector(other.data, other.pos)
{
}


Vector::~Vector()
{
	if (data!=nullptr)
	{
		delete[]data;
		data = nullptr;
		cout << "释放" << endl;
	}

}

int Vector::size() const
{
	return pos;
}

void Vector::push_bach(int v)
{
	int *temp = new int[pos + 1];
	memset(temp, 0, pos + 1);
	for (int i = 0; i < pos; ++i)
	{
		temp[i] = data[i];
	}
	if (data != nullptr)
	{
		delete[]data;
	}
	data = temp;
	data[pos++] = v;
	temp = nullptr;
}

bool Vector::empty() const
{
	return pos==0;
}

int Vector::front()	const
{
	return data[0];
}

int Vector::back() const
{
	return data[pos-1];
}

void Vector::print()  const
{
	if (data!=nullptr)
	{
		for (int i=0;i<pos;i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
}

Vector & Vector::operator+=(const Vector & other)
{
	if (other.data==nullptr)
	{
		return *this;
	}
	int len = other.pos;
	if (data!=nullptr)
	{
		len += pos;
	}
	int *temp = new int[len];
	memset(temp, 0, len);
	if (data!=nullptr)
	{
		for (int i=0;i<pos;++i)
		{
			temp[i] = data[i];
		}
		delete[]data;
	}
	for (int i=0;i<other.pos;++i)
	{
		temp[i+ pos] = other.data[i];
	}
	data = temp;
	pos = len;
	temp = nullptr;
	return *this;
}




Vector Vector::operator+(const Vector & other) const
{
	Vector t = *this;
	t += other;
	return t;
}

bool Vector::operator==(const Vector & other) const
{
	if (size() != other.size())
	{
		return false;
	}
	for (int i = 0; i < pos; ++i)
	{
		if (data[i] != other.data[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector::operator!=(const Vector & other) const
{
	if (size() != other.size())
	{
		return true;
	}
	for (int i = 0; i < pos; ++i)
	{
		if (data[i] != other.data[i])
		{
			return true;
		}
	}
	return false;
}

int &Vector::operator[](int index)
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
			cout << "下标越界" ;
		}
		else
		{
			return data[index];
		}
	}
	
}

const int Vector::operator[](int index) const
{
	try
	{
		if (index < 0 || index >= pos)
		{
			throw -1;
		}
		else
		{
			throw 1;
		}	
	}
	catch (int e)
	{
		if (e==-1)
		{
			cout << "下标越界";
		}
		else
		{
			return data[index];
		}
	}
}

Vector & Vector::operator=(const Vector & other)
{
	if (data!=nullptr)
	{
		delete[]data;
		data = nullptr;
		pos = 0;
	}
	if (other.data==nullptr)
	{
		return *this;
	}
	pos = other.pos;
	data = new int[pos];
	memset(data, 0, pos);
	for (int i=0;i<pos;++i)
	{
		data[i] = other.data[i];
	}

	return *this;
}

istream & operator >> (istream & in, Vector & a)
{
	if (a.data!=nullptr)
	{
		delete[]a.data;
		a.data = nullptr;
		a.pos = 0;
	}
	int temp = 0;
	int n = 0;
	cout << "请输入元素个数" << endl;
	in >> n;
	for (int i=0;i<n;++i)
	{
		cout << "请输入第"<<(i+1)<<"个元素" << endl;
		in >> temp;
		a.push_bach(temp);
	}
	return in;
}

ostream & operator<<(ostream & out, const Vector & a)
{
	 a.print();
	 return out;
}
