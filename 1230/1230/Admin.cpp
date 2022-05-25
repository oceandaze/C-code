#include "stdafx.h"
#include "Admin.h"
#include <iostream>
using namespace std;


Admin::Admin()
{
	strcpy_s(attribute, 32, "超级管理员");
}


Admin::~Admin()
{
}

void Admin::input()
{
	cout << "请填写用户信息（用户名、密码）\n"
		<< "请输入用户名  ";
	cin >> name;
	cout << "请输入密码  ";
	cin >> pwd;
	cout << "添加完成\n";
}

void Admin::show()
{
	cout << "姓名：" << name << "\t"
		<< "属性：" << attribute << endl;
}
