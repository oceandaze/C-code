#pragma once
class Array
{
public:
	Array(int t[][5],int n, int m);
	void avg();
	void show();
	~Array();
private:
	int a[4][5];
	float b[5];
	int row;
	int col;

};

