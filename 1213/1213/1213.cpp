// 1213.cpp : 定义控制台应用程序的入口点。
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
		cout << "拷贝调用\n";
	}
private:

};

// 定义一个类Array, 求一个二维数组各列元素的平均值，并将所求得的平均值按顺序存入
//一个一维数组中，具体要求如下：
// 私有数据成员
// int a[4][5];
// float b[5]; 数组b依次存放数组a的各列元素的平均值
// 公有成员函数
// Array(int t[][5], int n) :用数组t初始化数组a(n为数组t的行数)，将数组b的元素
//全部初始化为0。
// void avg() : 计算数组a的各列元素的平均值, 并存放到数组b中。
// void show()：输出所有成员数据，二维数组必须按行列形式输出。
// 在主函数中定义一个二维数组，并进行初始化，用该数组对类Array进行测试。


// 10、实现一个File类，可以完成写文件操作 
// int main() 
// {	
// 	File file("1.txt"); 
// 	file.write("123\n");
// 	file.write("456\n");
// 	file.write("789\n");
// } 
// ps:研究一下，怎样保证File可以自动关闭文件。 
// 生成的1.txt内容如下 : 123 456 789
int main1()
{
// 	Student s1;
// 	Student s2("王广旭");

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