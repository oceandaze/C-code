#include "stdafx.h"
#include <iostream>
using namespace std;

class Student1
{
public:
	virtual void output()
	{
		cout << "������" << name << "\t"
			<< "���䣺" << age << endl;
	}
private:
	char name[12];
	int  age;
};

int main()
{

// 	Student1 s1;
// 	char buffer[1024] = { 0 };
// 	*(int*)buffer = *(int*)&s1;
// 	//memcpy(buffer, &s1, 4);
// 	sprintf_s(buffer + 4, 12, "С��%d", 1);
//   	*(int*)(buffer + 16) = 20;
//   	((Student1*)buffer)->output();

//����:��buffer�з�10��ѧ����������ʾѧ����Ϣ
	const int n= 10;
	Student1 s1[n];
	char buffer[1024] = { 0 };
// 
	for (int i=0;i<n;i++)
	{
		*(int*)(buffer+i*20) = *(int*)(s1+i);
		sprintf_s(buffer + i * 20 + 4, 12, "С��%d", i);
		 *(int*)(buffer + i * 20 + 16) = 20+i;
	}
	for (int i=0;i<n;i++)
	{
		((Student1*)(buffer + i*20))->output();
	}

	return 0;
}