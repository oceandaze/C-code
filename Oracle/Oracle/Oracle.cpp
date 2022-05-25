// Oracle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ocilib.h"


int main(int argc, char *argv[])
{
	OCI_Connection* cn;
	OCI_Statement* st;
	OCI_Resultset* rs;

	OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT);

	cn = OCI_ConnectionCreate("localhost:1521/saledb", "wgx", "wgx123", OCI_SESSION_DEFAULT);
	st = OCI_StatementCreate(cn);

	OCI_ExecuteStmt(st, "select cust_id,cust_name from t_customer");

	rs = OCI_GetResultset(st);

	while (OCI_FetchNext(rs))
	{
		printf("%i - %s\n", OCI_GetInt(rs, 1), OCI_GetString(rs, 2));
	}

	OCI_Cleanup();

	return EXIT_SUCCESS;
}


// #if defined(OCI_CHARSET_WIDE)
// #pragma comment(lib, "ocilibw.lib")
// #elif defined(OCI_CHARSET_ANSI)
// #pragma comment(lib, "ociliba.lib")
// #endif
// 
// void err_handler(OCI_Error *err)
// {
// 	printf(
// 		"code  : ORA-%05i\n"
// 		"msg   : %s\n"
// 		"sql   : %s\n",
// 		OCI_ErrorGetOCICode(err),
// 		OCI_ErrorGetString(err),
// 		OCI_GetSql(OCI_ErrorGetStatement(err))
// 	);
// }
// 
// int main(int argc, _TCHAR* argv[])
// {
// 
// 	OCI_Connection* cn;
// 	OCI_Statement* st;
// 	OCI_Resultset* rs;
// 
// 
// 	OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT);
// 
// 	cn = OCI_ConnectionCreate("wgxdb.dbf", "wgx", "wgx123", OCI_SESSION_DEFAULT);
// 
// 	if (cn == NULL) {
// 		err_handler(OCI_GetLastError());
// 		printf("%i", OCI_GetVersionServer(cn));
// 		printf("连接失败！\n");
// 	}
// 	st = OCI_StatementCreate(cn);
// 
// 	OCI_ExecuteStmt(st, "select cust_id,cust_name from t_customer");
// 
// 	rs = OCI_GetResultset(st);
// 
// 	while (OCI_FetchNext(rs)) {
// 		printf("code: %i, name %s\n", OCI_GetInt(rs, 1), OCI_GetString(rs, 2));
// 	}
// 
// 	printf("\n%d row(s) fetched\n", OCI_GetRowCount(rs));
// 
// 
// 	OCI_Cleanup();
// 
// 
// 	
// 
// 	return EXIT_SUCCESS;
// }

