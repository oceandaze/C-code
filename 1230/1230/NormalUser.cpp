#include "stdafx.h"
#include "NormalUser.h"
#include <iostream>
using namespace std;

NormalUser::NormalUser()
{
	strcpy_s(attribute, 32, "普通用户");
	strcpy_s(userRight, 100, "查看、修改");
	
}


NormalUser::~NormalUser()
{
}

void NormalUser::input()
{
	cout << "请填写用户信息（用户名、密码、用户主目录）\n"
		<< "请输入用户名  ";
	cin >> name;
	cout << "请输入密码  ";
	cin >> pwd;
	cout << "请输入用户主目录  ";
	cin >> contents;
	
	cout << "添加完成\n";
}

void NormalUser::show()
{
	cout << "姓名："<<name << "\t" 
		<< "属性："<<attribute << "\t"
		<<"用户主目录："<<contents << "\t"
		<<"权限列表："<<userRight<< endl;
}


