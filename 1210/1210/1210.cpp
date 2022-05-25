// 1210.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
/*using namespace std;*/
// namespace A
// {
// 	int a;
// 	void test(int x)
// 	{
// 
// 		cout << "this is abc ::test" << endl;
// 		cout << x << endl;
// 	}
// 	namespace B
// 	{
// 		int a;
// 		void test(int x)
// 		{
// 
// 			cout << "this is ABC ::test" << endl;
// 			cout << x << endl;
// 		}
// 	};
// };

// namespace std
// {
// 	void strcpy(char*str1, char*str2)
// 	{
// 		int i = 0;
// 		for ( i=0;str2[i]!='\0';i++)
// 		{
// 			str1[i] = str2[i];
// 		}
// 		str1[i] = '\0';
// 	}
// 
// }
//  using namespace A::B;


using namespace std;

class Car
{

public:
	void Set(const char*n, const char *c)
	{
		strcpy_s(name, n);
		strcpy_s(color, c);
	}
	void  Strat()
	{
		cout << name << color << "启动" << endl;
	}
	void Stop()
	{
		cout << name << color << "停止" << endl;
	}
private:
	char name[32];

	char color[32];
};
class Animal
{
public:
	void set(const char *n,const char *t)
	{
		strcpy_s(name, n);
		strcpy_s(type, t);
	}
	void eat(const char*food)
	{
		cout << type <<"\t"<< name << "吃" << food << endl;
	}

private:
	char name[64];
	char type[32];
};

int main1()
{
	// 	A::a = 10;
	// 	A::test(A::a);
	// 	A::B::a = 20;
	// 	A::B::test(A::B::a);
	// 	char str1[100] = {"abcde123"};
	// 	char str2[100] = {0};
	// 	strcpy(str2, str1);
	// 	cout << str2 << endl;
	/*栈上*/
// 	Car bmw;
// 	bmw.Set("宝马", "白色");
// 	bmw.Strat();
// 	bmw.Stop();
// 	Car bmw2;
// 	bmw2.Set("宝骏", "花色");
// 	bmw2.Strat();
// 	bmw2.Stop();
// 	cout << sizeof(bmw) << endl;
// 	cout << sizeof(bmw2) << endl;
// 	cout << sizeof(Car) << endl;
// 	/*堆上*/
// 	Car *p = new Car;
// 	p->Set("小米", "黑色");
// 	p->Strat();
// 	p->Stop();
// 	delete p;
// 	p = nullptr;
// 
// 
//  	Car * car = new Car[3];
// 	car[0].Set("长城", "蓝色");
// 	car[1].Set("奥迪", "白色");
// 	car[2].Set("大众", "红色");
// 	car[0].Strat();
// 	car[1].Strat();
// 	car[2].Strat();
// 	car[0].Stop();
// 	car[1].Stop();
// 	car[2].Stop();
// 	delete[] car;

	Animal cat;
	cat.set("猫", "猫科");
	cat.eat("猫粮");
	Animal dog;
	dog.set("泰迪","犬科");
	dog.eat("肉");

	return 0;
}

class stu
{
public:
	void set(const char*n,char s,int a)
	{
		strcpy_s(name, n);
		if(s=='M')
		{
			strcpy_s(sex,"男");
		}
		else
		{	
			strcpy_s(sex, "女");
		}
		
		age = a;
	}
	void  info_show()
	{
		cout << "姓名：" << name << "  性别：" << sex << "  年龄：" << age << endl;;
	}
private:
	char name[32];
	char sex[10];
	int age;

};
 class 	Contacts
 {
 public:
	 void set(const char*n,char s, const char *num)
	 {
		 strcpy_s(name, n);
		 s == 'M' ? strcpy_s(sex, "男") : strcpy_s(sex, "女");
		 strcpy_s(tel,num);
	 }
	 void info_Show()
	 {
		 cout << "姓名:" << name << "  性别:" << sex << "  电话:" << tel << endl;
	 }
	 void name_Change(const char*n)
	 {
		 strcpy_s(name, n);
		 cout << "更新后信息" << endl;
		 info_Show();
	 }
	 void sex_Change(char s)
	 {
		 s == 'M' ? strcpy_s(sex, "男") : strcpy_s(sex, "女");
		 cout << "更新后信息" << endl;
		 info_Show();
	 }
	 void tel_Change(const char*num)
	 {
		 strcpy_s(tel, num);
		 cout << "更新后信息" << endl;
		 info_Show();
	 }
 private:
	 char name[32];
	 char sex[10];
	 char tel[15];
 };
int main()
{
	stu s1;
	s1.set("小明", 'M', 18);
	s1.info_show();

	Contacts  linkman1;
	linkman1.set("王旭", 'M', "18629340000");
	linkman1.info_Show();
	linkman1.name_Change("王广旭");
	linkman1.tel_Change("18629340730");
	return 0;
}

	


