// TestMySQL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <WinSock2.h>
#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	MYSQL mysql;
	mysql_init(&mysql);//初始化
	//连接数据库服务器          服务器IP     用户名  密码    数据库  端口号
	mysql_real_connect(&mysql, "127.0.0.1", "root", "root", "0214", 3306, NULL, 0);

	string sql;
	//sql = "select User,Host FROM user";
	sql = "set names gbk";
	//执行sql语句
	mysql_real_query(&mysql, sql.c_str(), sql.size());
	sql = "select * from t_user";
	sql = "update t_user set name = '王广旭'  where id = 1 ";
	sql = "delete  from T_user where id = 3";
	sql = "insert into T_user values(9,'杨涛2','涛涛')";
	//执行sql语句
	mysql_real_query(&mysql, sql.c_str(), sql.size());

	MYSQL_RES *res;
	MYSQL_ROW row;
	//获取SQL执行结果
// 	res = mysql_store_result(&mysql);
// 	//遍历记录集
// 	while ((row=mysql_fetch_row(res))!=NULL)
// 	{
// 		for (size_t i=0;i<mysql_num_fields(res);++i)
// 		{
// 			cout << row[i] << "\t";
// 		}
// 		cout << endl;
// 	}
// 	//释放记录集
// 	mysql_free_result(res);
	//关闭数据库连接
	mysql_close(&mysql);
    return 0;
}

