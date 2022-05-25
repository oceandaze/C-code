#pragma once
class Set
{
private:
	int * data;
	int pos;
public:
	Set(const int * p=nullptr,int cnt=0);
	Set(const Set &other);
	~Set();

	void output() const;
	void sort();
	void insert(int n);
	void find(int n);
	void clear();
	bool empty();
	int size();
	void erase(int val);
	int count(int val);

};

