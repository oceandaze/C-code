// TestMySQL.cpp : �������̨Ӧ�ó������ڵ㡣
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
	mysql_init(&mysql);//��ʼ��
	//�������ݿ������          ������IP     �û���  ����    ���ݿ�  �˿ں�
	mysql_real_connect(&mysql, "127.0.0.1", "root", "root", "0214", 3306, NULL, 0);

	string sql;
	//sql = "select User,Host FROM user";
	sql = "set names gbk";
	//ִ��sql���
	mysql_real_query(&mysql, sql.c_str(), sql.size());
	sql = "select * from t_user";
	sql = "update t_user set name = '������'  where id = 1 ";
	sql = "delete  from T_user where id = 3";
	sql = "insert into T_user values(9,'����2','����')";
	//ִ��sql���
	mysql_real_query(&mysql, sql.c_str(), sql.size());

	MYSQL_RES *res;
	MYSQL_ROW row;
	//��ȡSQLִ�н��
// 	res = mysql_store_result(&mysql);
// 	//������¼��
// 	while ((row=mysql_fetch_row(res))!=NULL)
// 	{
// 		for (size_t i=0;i<mysql_num_fields(res);++i)
// 		{
// 			cout << row[i] << "\t";
// 		}
// 		cout << endl;
// 	}
// 	//�ͷż�¼��
// 	mysql_free_result(res);
	//�ر����ݿ�����
	mysql_close(&mysql);
    return 0;
}

