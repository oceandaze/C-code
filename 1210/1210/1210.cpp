// 1210.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << name << color << "����" << endl;
	}
	void Stop()
	{
		cout << name << color << "ֹͣ" << endl;
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
		cout << type <<"\t"<< name << "��" << food << endl;
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
	/*ջ��*/
// 	Car bmw;
// 	bmw.Set("����", "��ɫ");
// 	bmw.Strat();
// 	bmw.Stop();
// 	Car bmw2;
// 	bmw2.Set("����", "��ɫ");
// 	bmw2.Strat();
// 	bmw2.Stop();
// 	cout << sizeof(bmw) << endl;
// 	cout << sizeof(bmw2) << endl;
// 	cout << sizeof(Car) << endl;
// 	/*����*/
// 	Car *p = new Car;
// 	p->Set("С��", "��ɫ");
// 	p->Strat();
// 	p->Stop();
// 	delete p;
// 	p = nullptr;
// 
// 
//  	Car * car = new Car[3];
// 	car[0].Set("����", "��ɫ");
// 	car[1].Set("�µ�", "��ɫ");
// 	car[2].Set("����", "��ɫ");
// 	car[0].Strat();
// 	car[1].Strat();
// 	car[2].Strat();
// 	car[0].Stop();
// 	car[1].Stop();
// 	car[2].Stop();
// 	delete[] car;

	Animal cat;
	cat.set("è", "è��");
	cat.eat("è��");
	Animal dog;
	dog.set("̩��","Ȯ��");
	dog.eat("��");

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
			strcpy_s(sex,"��");
		}
		else
		{	
			strcpy_s(sex, "Ů");
		}
		
		age = a;
	}
	void  info_show()
	{
		cout << "������" << name << "  �Ա�" << sex << "  ���䣺" << age << endl;;
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
		 s == 'M' ? strcpy_s(sex, "��") : strcpy_s(sex, "Ů");
		 strcpy_s(tel,num);
	 }
	 void info_Show()
	 {
		 cout << "����:" << name << "  �Ա�:" << sex << "  �绰:" << tel << endl;
	 }
	 void name_Change(const char*n)
	 {
		 strcpy_s(name, n);
		 cout << "���º���Ϣ" << endl;
		 info_Show();
	 }
	 void sex_Change(char s)
	 {
		 s == 'M' ? strcpy_s(sex, "��") : strcpy_s(sex, "Ů");
		 cout << "���º���Ϣ" << endl;
		 info_Show();
	 }
	 void tel_Change(const char*num)
	 {
		 strcpy_s(tel, num);
		 cout << "���º���Ϣ" << endl;
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
	s1.set("С��", 'M', 18);
	s1.info_show();

	Contacts  linkman1;
	linkman1.set("����", 'M', "18629340000");
	linkman1.info_Show();
	linkman1.name_Change("������");
	linkman1.tel_Change("18629340730");
	return 0;
}

	


