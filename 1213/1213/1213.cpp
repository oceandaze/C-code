// 1213.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Student.h"
#include <iostream>
#include "Array.h"
#include "File.h"

using namespace std;
class A
{
public:
// 	A()
// 	{
// 		cout << "A()" << endl;
// 	}
// 	A(int a=0)
// 	{
// 		cout << "A(int a)" << endl;
// 	}
	A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A & other)
	{
		cout << "��������\n";
	}
private:

};

// ����һ����Array, ��һ����ά�������Ԫ�ص�ƽ��ֵ����������õ�ƽ��ֵ��˳�����
//һ��һά�����У�����Ҫ�����£�
// ˽�����ݳ�Ա
// int a[4][5];
// float b[5]; ����b���δ������a�ĸ���Ԫ�ص�ƽ��ֵ
// ���г�Ա����
// Array(int t[][5], int n) :������t��ʼ������a(nΪ����t������)��������b��Ԫ��
//ȫ����ʼ��Ϊ0��
// void avg() : ��������a�ĸ���Ԫ�ص�ƽ��ֵ, ����ŵ�����b�С�
// void show()��������г�Ա���ݣ���ά������밴������ʽ�����
// ���������ж���һ����ά���飬�����г�ʼ�����ø��������Array���в��ԡ�


// 10��ʵ��һ��File�࣬�������д�ļ����� 
// int main() 
// {	
// 	File file("1.txt"); 
// 	file.write("123\n");
// 	file.write("456\n");
// 	file.write("789\n");
// } 
// ps:�о�һ�£�������֤File�����Զ��ر��ļ��� 
// ���ɵ�1.txt�������� : 123 456 789
int main1()
{
// 	Student s1;
// 	Student s2("������");

 	//A a1;
 	//A a2;
	//A *a1 = new A[10];//error
 	//A * a3 = new A(5);
// 	A();
// 	A(5);
// 	A b;
// 	A a(b);
// 	A c = a;
	int t[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int n = sizeof(t) / sizeof(t[0]);
	int m= sizeof(t[0]) / sizeof(t[0][0]);
	Array a1(t, n,m);
	a1.avg();
	a1.show();
    return 0;
}

int main()
{
	File file("1.txt");
	file.write("123\n");
	file.write("456\n");
	file.write("789\n");
	return 0;
}