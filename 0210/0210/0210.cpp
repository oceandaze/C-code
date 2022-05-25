// 0210.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <atomic>
using namespace std;


#define CIR(r) r*r 
struct name2 
{ 
	char str;
	int num; 
	short x; 
};


void main()
{
	cout << sizeof(name2) << endl;
	int a = 1;
	int b = 2;
	int t;
	t = CIR(a + b);
	printf("%d\n", t);
	return;
}


void test(string name)
{
	for (int i=0;i<10;i++)
	{
		cout << name<<"-test" << i << endl;
	}
}
int main1()
{
	thread t1(test,"�߳�1");
	t1.join();
    return 0;
}


class A
{
public:
	void output(int a) {
		cout << "�߳�����" << a << endl;
	}
private:
};

int main2()
{
	A a1;
	thread t2(&A::output, a1, 10);
	t2.join();
	return 0;
}

int main3()
{
	thread t2([](int a) {
		cout << "�����߳�" << a << endl;
	},10);
	t2.join();
	return 0;
}											  

mutex g_m;
//�Զ�������������
//int g_cnt = 0;

//ԭ�Ӳ���
atomic_int g_cnt = 0;
void work()
{
	for (int i=0;i<1000000;i++)
	{
		//�Զ�������������
		//lock_guard <mutex> lock(g_m); //�ȼ��滻�Զ���������
		////g_m.lock();
		//g_cnt = g_cnt + 1;
		////g_m.unlock();
		
		//ԭ�Ӳ���
		++g_cnt;
	}
}

int main4()
{
	thread t1(work);
	
	thread t2(work);
	
	thread t3(work);
	t1.join();
	t2.join();
	t3.join();
	cout << g_cnt << endl;
	return 0;
}


