// OCCIConnectOracle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>  
#define WIN32COMMON //���⺯���ض������  
#include <occi.h>  
using namespace std;
using namespace oracle::occi;


int main()
{
	system("pause");
	//����OCCI�����Ļ���  
	Environment *env = Environment::createEnvironment();
	if (NULL == env) {
		printf("createEnvironment error.\n");
		return -1;
	}
	else
		cout << "success" << endl;

	string name = "wgx";
	string pass = "wgx123";
	string srvName = "localhost:1521/saledb";

	try
	{
		//�������ݿ�����  
		Connection *conn = env->createConnection(name, pass, srvName);//�û��������룬���ݿ���  
		if (NULL == conn) {
			printf("createConnection error.\n");
			return -1;
		}
		else
			cout << "conn success" << endl;

		//  ���ݲ���,����Statement����  
		Statement *pStmt = NULL;    // Statement����  
		pStmt = conn->createStatement();
		if (NULL == pStmt) {
			printf("createStatement error.\n");
			return -1;
		}

		// ��ѯ���ݿ�ʱ��    
		std::string strTemp;
		ResultSet *pRs = pStmt->executeQuery(
			"SELECT TO_CHAR(SYSDATE, 'YYYY-MM-DD HH24:MI:SS') FROM DUAL");
		while (pRs->next()) {
// 			strTemp = pRs->getString(1);
			
// 			printf("db time:%s.\n", strTemp.c_str());
			
			// int����ȡֵ��getInt()    
			break;
		}
		pStmt->closeResultSet(pRs);

		//--------����---------    
		// ָ��DMLΪ�Զ��ύ    
		pStmt->setAutoCommit(TRUE);
		// ����ִ�е�SQL���    
		//pStmt->setSQL("INSERT INTO TA (ID, NAME) VALUES (1, 'ZS')");    
		pStmt->setSQL("INSERT INTO TABLE_TEST_WANG (NAME, NUM, AGE) VALUES ('�˳�', '99', '41')");

		// ִ��SQL���    
		unsigned int nRet = pStmt->executeUpdate();
		if (nRet == 0) {
			printf("executeUpdate insert error.\n");
		}

		// ��ֹStatement����    
		conn->terminateStatement(pStmt);

		//  �ر�����  
		env->terminateConnection(conn);
		// pEnv->terminateConnection(pConn);    
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		system("pause");
		return -1;
	}


	// �ͷ�OCCI�����Ļ���    
	Environment::terminateEnvironment(env);
	cout << "end!" << endl;
	system("pause");
	return 0;
}
