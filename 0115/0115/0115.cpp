// 0115.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include "PackFile.h"
#include "UnPackFile.h"
using namespace std;

int main1()
{
	ofstream file("1.txt", ios::binary);
// 	int a = 6;
// 	file.write((const char*)&a, 4);
// 
// 	double b = 5.22;
// 	file.write((const char*)&b, 8);
// 	char ch[15] = "good boy\n";
// 	file.write(ch, strlen(ch));
// 
// 	string str = "ejejjeeeee123456789qwertyas\n";
// 	file.write(str.c_str(), str.size());
// 
// 	string str2 = "6 5.22";
// 	file.write(str2.c_str(), str2.size());
	int a = 6;
	//double b = 5.2;
	char arr[] = {"hello world!"};//13

	file.write((const char*)&a, sizeof(a));
	//file.write((const char*)&b, sizeof(b));
	int n = sizeof(arr);
	file.write((const char*)&n, sizeof(int));
	file.write(arr, sizeof(arr));


    return 0;
}


int main2()
{
	ifstream file("1.txt", ios::binary);
	int a = 0;
	double b = 0;
	char arr[24] = { 0 };//13

	file.read((char*)&a, sizeof(a));
	file.read((char*)&b, sizeof(b));
	file.read(arr, 13);
	cout << "a=" << a << endl
		<< "b=" << b << endl
		<< "arr=" << arr << endl;

	return 0;
}

int main3()
{
	ifstream file("C:\\Users\\Administrator\\Desktop\\��Ѷ����ͼƬ_20220115114917.png", ios::binary);
	file.seekg(0, ios::end);//��λ�ļ�ָ��
	cout << "�ļ���С���ļ�ָ��λ�ã���" << file.tellg() << endl;
	return 0;
}

int main4()
{
	ifstream file("C:\\Users\\Administrator\\Desktop\\111.bmp", ios::binary);
	if (!file)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return -1;
	}
	file.seekg(18, ios::beg);//��λ�ļ�ָ��
	//cout << "�ļ���С���ļ�ָ��λ�ã���" << file.tellg() << endl;
	int width = 0;
	int height = 0;
	file.read((char*)&width, sizeof(width));
	file.read((char*)&height, sizeof(height));
	cout << "width= " << width << " ����" << endl
		<< "height= " << height << " ����" << endl;

	return 0;
}
/*10��������Ӧ����Ƴ���
����ļ�   */
int main5()
{
	PackFile p("123.me");
	p.add("2.txt");
	p.add("1.exe");
 	p.add("4.jpg");
 	p.save();//��add��ӵ��ļ��ϲ������123.me�ļ���
	return 0;
}


/*
11��������Ӧ����Ƴ���
����ļ� */
int main()
{
	UnPackFile  p("123.me");
	p.save("D:\\test");  //��123.me�е��ļ�������ŵ�D:\testĿ¼��
	return 0;
}
