// 0208.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SharedPtr.h"
#include <iostream>
#include <ctime>
#include <memory>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	time_t now_time = time(nullptr);
	tm t_tm;
	localtime_s(&t_tm, &now_time);
	char buffer[64] = { 0 };
	asctime_s(buffer, sizeof(buffer), &t_tm);
	cout << buffer << endl;
// 	cout << put_time(&t_tm, "%X  %x  %D  %F") << endl;
// 
// 
// 	ostringstream stream;
// 	stream << put_time(&t_tm, "%X  %x  %D  %F");
// 	string s1 = stream.str();
// 	stream.str("");	//清空数据
// 	cout << s1 << endl;
    return 0;
}

class Test
{
public:
	Test() {
		cout << "Test()" << endl;
	}
	~Test(){
		cout << "~Test()" << endl;
	}
	void Output() {
		cout << "Output()" << endl;
	}
};

template <class T>
 class AutoPtr
 {
 public:
	 AutoPtr(T *ptr) {
		 this->ptr=ptr;
	 }
	 ~AutoPtr() {
		 if (ptr!=nullptr) {
			 delete ptr;
		 }
	 }
	 T &operator*() {
		 return *ptr;
	 }
	 T* get() {
		 return ptr;
	 }
	 T* operator->() {
		 return ptr;
	 }
 private:	 AutoPtr(const AutoPtr&) = delete;	 AutoPtr& operator=(const AutoPtr&) = delete;
 private:
	 T *ptr;
 };
int main2()
{
	AutoPtr<Test> p1(new Test);
	p1->Output();
	p1.get()->Output();
	//AutoPtr<Test> p2 = p1;
	return 0;
}

int main3()
{
	unique_ptr<int> p1(new int);
	*p1 = 10;
	cout << *p1 << endl;
	unique_ptr<string>  s1(new string);
	*s1 = "hello world";
	cout << *s1 << endl;
	return 0;
}


int main4()
{
	shared_ptr<int> p1(new int);
	shared_ptr<int> p2(p1);
	*p1 = 10;
	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;
	return 0;
}

int main5()
{
	int(*n)[10];
	printf("%d",sizeof(n));
	return 0;
}


class B;
class A
{
public:
	A() { cout << "A::A() called" << endl; }
	~A() { cout << "A::~A() called" << endl; }
	//shared_ptr<B> p;
	weak_ptr<B> p;
};
class B
{
public:
	B() { cout << "B::B() called" << endl; }
	~B() { cout << "B::~B() called" << endl; }
	//shared_ptr<A> p;
	weak_ptr<A> p;
};

int main6()
{
	shared_ptr<A> pA(new A);
	shared_ptr<B> pB(new B);
	pA->p = pB;
	pB->p = pA;
	cout << "pA use_count: " << pA.use_count() << endl;
	cout << "pB use_count: " << pB.use_count() << endl;
	return 0;
}

weak_ptr<Test> get()
{
	shared_ptr<Test> p1(new Test);
	return p1;
}

int main7()
{
	weak_ptr<Test> p = get();
	shared_ptr<Test> s1 = p.lock();
	if (s1)
	{
		s1->Output();
	}
	else
	{
		cout << "指针为空" << endl;
	}
	return 0;
}
//template<> int SharedPtr<Test>::cnt = 0;

int main8()
{
	SharedPtr<Test> p1(new Test);

	{
		SharedPtr<Test> p3;
		//*p1 = 10;
		p3 = p1;
		//cout << *p3 << endl;
		cout << p3.use_count() << endl;
	}


	//cout << *p1 << endl;
	//cout << *p2 << endl;

	{
		SharedPtr<Test> p2(p1);
		cout << p2.use_count() << endl;
	}
	cout << p1.use_count() << endl;
	
	
	return 0;
}