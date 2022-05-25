#pragma once
#include <initializer_list>

template <class T>
class Iterator
{
public:
	Iterator(T* p = nullptr) {
		this->ptr = p;
	}

	bool operator!=(const Iterator &other) const
	{
		return ptr != other.ptr;
	}

	Iterator &operator++()
	{
		++ptr;
		return *this;
	}

	T &operator*()
	{
		return *ptr;
	}
private:
	T *ptr;
};

typedef unsigned int Size_t;
template <class T>
class Vector
{
public:
	typedef Iterator<T> iterator;

	Vector() : pos(0) 
	{ 
	}

	Vector(const std::initializer_list<T> &list) : pos(0)
	{
		for (const auto &i : list) {
			push_back(i);
		}
	}

	void push_back(const T &val) {
		data[pos++] = val;
	}

	Size_t size() const { return pos;  }
	bool empty() const { return pos == 0; }

	const T &operator[](int index) const
	{
		return data[index];
	}

	iterator begin()
	{
		return iterator(data);
	}

	iterator end()
	{
		return iterator(data + pos);
	}
private:
	T		data[1024];
	Size_t	pos;
};