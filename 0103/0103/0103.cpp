// 0103.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <functional>
using namespace std;
class Dog
{
public:
	Dog() {
		this->no = 1;
		strcpy_s(this->name , "金毛");
		this->age = 2;
	}
	Dog(int no,char *name,int age) {
		this->no = no;
		strcpy_s(this->name, name);
		this->age = age;
	}
	void setinfo(int no, char *name, int age){
		this->no = no;
		strcpy_s(this->name, name);
		this->age = age;
	}
	void print() const {
		cout << "no:" << no << "\n"
			<< "name:" << name << "\n"
			<< "age:" << age << endl;
	}
	void  getinfo(int &no , char * name,int &age) const{

		no = this->no;
		strcpy_s(name, strlen(this->name)+1, this->name);
		age = this->age;
	}

private:
	int no;
	char name[32];
	int age;

};


int main1()
{
	Dog d1;
	int no = 0;
	char name[32];
	int age = 0;
	d1.setinfo(5, "泰迪", 10);
	d1.print();

	d1.getinfo(no, name, age);
	cout << no << endl;
	cout << name<< endl;
	cout << age << endl;
    return 0;
}


template <class T>
T add(T a, T b)
{
	return a + b;

}

template <class T1,class T2>
T2 add(T1 a, T1 b)
{
	return a + b;

}

template <class T,int rows>
void sum(T data[], T&result)
{
	for (int i=0;i<rows;++i)
	{
		result += data[i];
	}
}

template <class T,typename Cmp>
void Sort(T * arr, int cnt, Cmp cmp)
{
	for (int i=0;i<cnt-1;++i)
	{
		for (int j=0;j<cnt-1-i;++j)
		{
			if (cmp(arr[j+1],arr[j]))
			{
				T temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < cnt; ++i)
	{
		cout << arr[i]<<" ";
	}
}
bool Cmp1(int a, int b)
{
	return a < b;
}
bool Cmp2(int a, int b)
{
	return a > b;
}

template <class T>
struct Greater
{
	bool operator()(T a, T b)const
	{
		return a > b;
	}
};
template <class T>
struct Less
{
	bool operator()(T a, T b)const
	{
		return a < b;
	}
};


int main11()
{

// 	cout << add(1, 2) << endl;
// 	cout << add(1.1, 2.2) << endl;
// 	cout << add<double>(1, 2.2) << endl;
// 	cout << add<int>(1.1, 2.2) << endl;
// 	cout << add<double,double>(1.1, 2) << endl;

// 	int array[] = { 1,2,3,4,5 };
// 	int result = 0;
// 	sum<int, 5>(array, result);
// 	cout << result << endl;


	int array[5] = { 2,12,4,3,1 };
	Sort(array, 5,Cmp2);
	return 0;
}

int main22()
{
// 	Greater g1;
// 	if (g1(1,2))
// 	{
// 	}
// 	Greater c1;
// 	Less c2;
	int a1[] = { 6,3,4,1,2 };
	double a2[] = {2.1,10.4,3.2,1.1,7.8};
// 	Sort(a1, 5, c1);
// 	Sort(a1, 5, c2);
	Sort(a2, 5, Less<double>());
	Sort(a2, 5, Greater<double>());


	return 0;
}
class Student
{
public:
	Student(const char* name, int age) {
		strcpy_s(this->name, name);
		this->age = age;
	}
	bool operator<(const Student &other) const {
		return this->age < other.age;
	}

	bool operator>(const Student &other) const {
		return this->age > other.age;
	}

	friend ostream &operator<<(ostream &out, const Student &stu) {
		out << stu.name << "\t"
			<< stu.age << endl;
		return out;
	}
private:
	char name[14];
	int  age;
};

int main() {

	Student p[3] = {
		Student("小明", 20),
		Student("小白", 15),
		Student("小黑", 22),
	};

	//Sort(p, 3, less<Student>());
	Sort(p, 3, greater<Student>());
	return 0;
}