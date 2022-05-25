// 1225.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
	public:
		int operator ()(int a,int b) const
		{
			return a + b;
		}

		void operator()(int a) const
		{
			cout << "a="<<a << endl;
		}

};
struct Less //<
{
	bool operator()(int a, int b)const
	{
		return a < b;
	}

};

struct   Greater
{
	bool operator ()(int a, int b)const
	{
		return a > b;
	}
};
class B
{
public:

	B(int x) :a(x) {}
	B*operator->()
	{
		return this;
	}
	void Output() {
		cout << a << endl;
	}
private:
	int a;
};

int main1()
{
	A a1;
	cout << a1(1, 2) << endl;
	a1(10);

	Less a2;
	if (a2(1,2))
	{
		cout << "小于\n";
	}

	cout << Less()(1, 2) << endl;

	Greater b1;
	if (b1(3,2))
	{
		cout << "大于\n";
	}


	B b(2);
	b->Output();
	return 0;
}


class Person
{
public:
	Person() {
		memset(name, 0, sizeof(name));
		memset(sex, 0, sizeof(sex));
		age = 0;
	}
	void setName(const char* name)
	{
		strcpy_s(this->name, name);
	}

protected:
	char name[32];
	char sex[4];
	int age;

private:

};

class Student :public Person
{
public:
	Student(int id,const char* name,const char*sex,int age)
	{
		this->id = id;
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
		this->age = age;
	}
	void output()
	{
		cout << id << "\t" << name << "\t" <<
			sex << "\t" << age << endl;
	}
	
protected:
private:
	int id;
};


   class C
   {
   public:
	   C(int n) {
		   cout << "n=" << n<<endl;
	   }
   protected:
   private:
   };
   class D :public C
   {
   public:
	   D() :C(0){
		   cout << "D()\n";
	   }
	   D(int n) :C(n) {
		   cout << "D(int)\n";
	   }
   protected:
   private:
   };

int main()
{
// 	Student s1(9527,"李白","男",25);
// 	//s1.setName("杜甫");
// 	
// 	s1.output();

	D d1(1);

	return 0;
}
