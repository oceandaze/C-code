// connOracle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// #include "ocilib.h"
// 
// int main(void)
// {
// 	OCI_Connection *cn;
// 	OCI_Statement  *st;
// 	OCI_Resultset  *rs;
// 
// 	if (!OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT))
// 		return EXIT_FAILURE;
// 
// 	cn = OCI_ConnectionCreate("wgxdb.dbf", "wgx", "wgx123", OCI_SESSION_DEFAULT);
// 	st = OCI_StatementCreate(cn);
// 
// 	OCI_ExecuteStmt(st, "select * from T_customer");
// 
// 	rs = OCI_GetResultset(st);
// 
// 	while (OCI_FetchNext(rs))
// 		printf("code: %i, name %s\n", OCI_GetInt(rs, 1), OCI_GetString(rs, 2));
// 
// 	printf("\n%d row(s) fetched\n", OCI_GetRowCount(rs));
// 
// 	OCI_Cleanup();
// 
// 	return EXIT_SUCCESS;
// }

// #include "ocilib.h"
// #include <string>
// using namespace std;
// int main(int argc, char *argv[])
// 
// {
// 
// 	OCI_Connection* cn;
// 
// 	OCI_Statement* st;
// 
// 	OCI_Resultset* rs;
// 
// 	OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT);
// 
// 	string db = "wgxdb.dbf";
// 	
// 	cn = OCI_ConnectionCreate((otext*)db.c_str(), "wgx", "wgx123", OCI_SESSION_DEFAULT);
// 	string id = "1";
// 	st = OCI_StatementCreate(cn);
// 	OCI_Prepare(st, "select * from T_customer WHERE cust_ID=:ID");
// 	OCI_BindString(st, ":ID", (otext*)id.c_str(), id.size());
// 	OCI_Execute(st);
// 
// 	rs = OCI_GetResultset(st);
// 	while (OCI_FetchNext(rs))
// 	{
// 		printf(" %s\n", OCI_GetString(rs, 1));
// 
// 	}
// 	OCI_Cleanup();
// 	return EXIT_SUCCESS;
// }


#include <iostream>
#include <string>
#include "ocilib.hpp"
#pragma comment(lib,"ociliba.lib")

void err_handler(OCI_Error *err)
{
	printf("%s\n", OCI_ErrorGetString(err));
}

int main(void)
{
	OCI_Connection *cn;

	if (!OCI_Initialize(err_handler, NULL, OCI_ENV_DEFAULT))
	{
		return EXIT_FAILURE;
	}
	cn = OCI_ConnectionCreate("wgxdb.dbf", "wgx", "wgx123", OCI_SESSION_DEFAULT);
	printf("Server major    version : %i\n", OCI_GetServerMajorVersion(cn));
	printf("Server minor    version : %i\n", OCI_GetServerMinorVersion(cn));
	printf("Server revision version : %i\n\n", OCI_GetServerRevisionVersion(cn));
	printf("Connection      version : %i\n\n", OCI_GetVersionConnection(cn));
	OCI_Statement *st = OCI_StatementCreate(cn);
	//OCI_ExecuteStmt(st, "insert into test values(7,'oci','test')");
	//OCI_ExecuteStmt(st, "commit");
	OCI_ExecuteStmt(st, "select * from T_customer");
	OCI_Resultset *rs = OCI_GetResultset(st);
	while (OCI_FetchNext(rs))
		printf("ID: %d, NAME: %s, MESSAGE: %s\n", OCI_GetInt(rs, 1), OCI_GetString(rs, 2), OCI_GetString(rs, 3));
	printf("\n%d row(s) fetched\n", OCI_GetRowCount(rs));
	OCI_StatementFree(st);
	OCI_ConnectionFree(cn);
	OCI_Cleanup();
	system("PAUSE");

	return EXIT_SUCCESS;
}