#pragma once

class Vector
{
public:
	Vector(const int *p = nullptr, int cnt = 0);
	Vector(const Vector &other);
	~Vector();

	void push_back(int v);
	int size() const;
	void output() const;

	int at(int index) const;
	int front() const;
	int back() const;

	bool empty() const;
	bool equal(const Vector &other) const;
	void erase(int index);
private:
	int *data;
	int pos;
};

