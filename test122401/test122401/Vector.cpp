#include "stdafx.h"
#include "Vector.h"


Vector::Vector()
	: data(nullptr)
	, pos(0)
{

}

Vector::Vector(const Vector & other)
	: data(nullptr)
	, pos(other.pos)
{
	if (pos > 0) {
		data = new int[pos];
		for (int i = 0; i < pos; ++i) {
			data[i] = other.data[i];
		}
	}
}


Vector::~Vector()
{
	if (data != nullptr) {
		delete[] data;
	}
}

void Vector::push_back(int val)
{
	int *ptr = new int[pos + 1];
	for (int i = 0; i < pos; ++i) {
		ptr[i] = data[i];
	}

	if (data != nullptr) {
		delete[] data;
	}
	data = ptr;
	data[pos++] = val;
}

int Vector::size() const
{
	return pos;
}

bool Vector::empty() const
{
	return data == nullptr;
}

int Vector::front() const
{
	//异常处理，解决
	return data[0];
}

int Vector::back() const
{
	//异常处理，解决
	return data[pos - 1];
}

Vector & Vector::operator+=(const Vector & other)
{
	for (int i = 0; i < other.pos; ++i) {
		push_back(other.data[i]);
	}
	return *this;
}

Vector Vector::operator+(const Vector & other) const
{
	Vector temp = *this;
	temp += other;
	return temp;
}

int & Vector::operator[](int index)
{
	return data[index];
}

const int & Vector::operator[](int index) const
{
	return data[index];
}

bool Vector::operator==(const Vector & other) const
{
	if (pos != other.pos) {
		return false;
	}

	for (int i = 0; i < pos; ++i) {
		if (data[i] != other.data[i]) {
			return false;
		}
	}

	return true;
}

ostream & operator<<(ostream & out, const Vector & ve)
{
	if (ve.pos > 0) {
		for (int i = 0; i < ve.pos; ++i) {
			out << ve.data[i] << " ";
		}
	}
	return out;
}

istream & operator >> (istream & in, Vector & ve)
{
	if (ve.data != nullptr) {
		delete[] ve.data;
	}

	cout << "请输入个数：";
	in >> ve.pos;
	ve.data = new int[ve.pos];
	for (int i = 0; i < ve.pos; ++i) {
		in >> ve.data[i];
	}
	return in;
}
