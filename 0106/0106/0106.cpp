// 0106.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
// 	int a = 18333848;
// 	char b = (char)a;
// 	char c = static_cast<char>(a);
// 	cout << b << endl;
// 	cout << c << endl;
// 
// 	char*p = new char[10];
// 	int *p1 = (int*)p;
// 	int *p2 = reinterpret_cast<int*>(p);

	const char*p = "hello!";
	/*char * p3 = (const char*)p;*/
	char *p4 = const_cast<char*>(p);
	cout << p4 << endl;
	p4 = "world";
	cout << p4 << endl;
    return 0;

}

class A
{
public:
	virtual void output()
	{
	
	}
protected:
private:
};

class B: public A
{
public:
	B()
	{
		p = new char[128];
		cout << "我被调用了" << endl;
	}

	void update()
	{
		strcpy_s(p, 128, "hello world hello");
		cout << p << endl;
	}
// protected:
// private:
	char*p;
};

int main2()
{

	A * p = new A;
	B *p1 = dynamic_cast<B*>(p);
	if (p1!=nullptr)
	{
		p1->update();
	}
	else
	{
		cout << "指针为空" << endl;
	}
	return 0;

}

template <class T, class Cmp>
void Sort(T *arr, int cnt, Cmp cmp)
{
	//冒泡排序
	for (int i=0;i<cnt-1;++i)
	{
		for (int j = 0; j < cnt - 1 - i; ++j)
		{
			if (cmp(arr[j+1],arr[j]))
			{
				T temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	//输出
	for (int i=0;i<cnt;++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

bool cmp(int a, int b)
{
	return a < b;
}
template<class T>
bool cmp2(T a, T b)
{
	return a < b;
}

int main3()
{

	auto f1 = [](int a, int b)->int {
		return a + b;
	};

	cout << f1(10, 20) << endl;

	auto f2 = [](int a, int b){
		return a + b;
	};

	cout << f2(30, 20) << endl;


	int a1[] = { 6,3,4,1,2 };
	double a2[] = { 2.1,10.4,3.2,1.1,7.8 };

// 	Sort(a1, 5,cmp2<int>);
// 	Sort(a2, 5, cmp2<double>);

	Sort(a1, 5, [](int a, int b) {
		return a < b; 
	});
	Sort(a1, 5, [](int a, int b) {
		return a > b;
	});
	return 0;
}

int main5()
{
	int a1 = 10;
// 	auto f1 = []() {
// 		cout << "a1=" << a1 << endl;
// 	};
	auto f2=[=]() {
		cout << "a1=" << a1 << endl;
	};
	f2();
	auto f3 = [&]() {
		a1 = 20;
		cout << "a1=" << a1 << endl;
	};
	f3();

	return 0;
}