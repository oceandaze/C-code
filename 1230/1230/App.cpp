#include "stdafx.h"
#include "App.h"
#include "NormalUser.h"
#include "Admin.h"
#include <iostream>

using namespace std;
App::App()
{
	index = 0;
}
App::~App()
{
}

void App::run()
{	 
	while (true)
	{
		cout << "----------------------------------------------------------\n";
		cout << " 1、添加用户      2、显示所有用户		3、退出系统 \n";
		cout << "----------------------------------------------------------\n";
		int n;
		cin >> n;
		if (n==1){
			add();
		}
		else if (n==2){
			show();
		}
		else if (n==3) {
			break;
		
		}
		else{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	
}

void App::show()
{
	for (int i=0;i<index;++i)
	{
		users[i]->show();
	}
}

void App::add()
{
	cout << "请选择添加用户属性:1、普通用户  2、超级管理员用户" << endl;
	int n = 0;
	cin >> n;
	User  *pUser = creatuser(n);
	if (pUser!=nullptr)
	{
		pUser->input();
		users[index++] = pUser;
	}
	
}

User * App::creatuser(int n) const
{
	if (n==1)
	{
		return new NormalUser;
	}
	else if(n==2)
	{
		return new Admin;
	}
	return nullptr;
}
