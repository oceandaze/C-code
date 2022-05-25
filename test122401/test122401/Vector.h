#pragma once
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector();
	Vector(const Vector &other);
	~Vector();

	void push_back(int val);
	int size() const;
	bool empty() const;
	int front() const;
	int back() const;

	Vector &operator+=(const Vector &other);
	Vector operator+(const Vector &other) const;
	int &operator[](int index);
	const int &operator[](int index) const;
	bool operator==(const Vector &other) const;

	friend ostream &operator<<(ostream &out, const Vector &ve);
	friend istream &operator >> (istream &in, Vector &ve);
private:
	int *data;
	int  pos;
};

