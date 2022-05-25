#pragma once
class Vector
{
public:
	Vector();
	Vector(const int * p , int cnt);
	Vector(const Vector &other);
	~Vector();

	
	int size();
	void push_back(int v);
	int at(int index);
	int front();
	int back();
	bool empty();
	bool equal(const Vector &other);
	void output();
	void erase(int index);
	void update(int index,int n);
private:
	int *arr;
	int n;
};

