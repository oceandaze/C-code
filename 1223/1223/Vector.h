#pragma once
#include <iostream>

using namespace std;
class Vector
{
public:
	Vector(const int *p=nullptr , int n=0);
	Vector(const Vector&other);
	~Vector();

	int size() const ;
	void push_bach(int v);
	bool empty()const;
	int front()const;
	int back()const;
	void print() const;

	Vector & operator +=(const Vector & other);
	Vector  operator +(const Vector & other) const;
	bool  operator ==(const Vector & other) const;
	bool  operator !=(const Vector & other) const;
	int &operator[](int index);
	const int operator[](int index)const;
	Vector &operator=(const Vector &other);

	friend istream &operator >> (istream & in,Vector &a);
	friend ostream &operator << (ostream & out, const Vector &a);
private:
	int *data;
	int pos;
};

