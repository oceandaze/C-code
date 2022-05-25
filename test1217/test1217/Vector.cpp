#include "stdafx.h"
#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(const int *p, int cnt)
{
	if (p != nullptr) {
		pos = cnt;
		data = new int[pos];
		for (int i = 0; i < pos; ++i) {
			data[i] = p[i];
		}
	}
	else {
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
	if (data != nullptr) {
		delete[] data;
	}
}

void Vector::push_back(int v)
{
	int *p = new int[pos + 1];
	for (int i = 0; i < pos; ++i) {
		p[i] = data[i];
	}

	if (data != nullptr) {
		delete[] data;
	}
	data = p;
	data[pos++] = v;
}

int Vector::size() const
{
	return pos;
}

void Vector::output() const
{
	if (data != nullptr) {
		for (int i = 0; i < pos; ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
}

int Vector::at(int index) const
{
	//Òì³£´¦Àí
	return data[index];
}

int Vector::front() const
{
	return data[0];
}

int Vector::back() const
{
	return data[pos - 1];
}

bool Vector::empty() const
{
	return pos == 0;
}

bool Vector::equal(const Vector & other) const
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

void Vector::erase(int index)
{
	if (index < 0 || index >= size()) {
		return;
	}

	for (int i = index; i < pos - 1; ++i) {
		data[i] = data[i + 1];
	}

	--pos;
}
