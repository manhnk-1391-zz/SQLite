#include <iostream>
#include <sqlite3.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

sqlite3_stmt *select(sqlite3 *db,const char* pSQL);
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main()
{
   sqlite3 *db;
   char *zErrMsg = 0;
   const char *pSQL = "SELECT a.ID, a.LastName, b.Salary FROM Table1 AS a, Table2 AS b WHERE a.ID = b.ID";
   int rc;

   //open database
   rc = sqlite3_open("Sqlite_Test.db", &db);

   if (rc)
      cout << "Can't open database: " << sqlite3_errmsg(db) << "\n";
   else
      cout << "Open database successfully\n\n";

   // rc = sqlite3_exec(db, pSQL, callback, 0, NULL);
   // rc = sqlite3_exec(db, pSQL, NULL, 0, NULL);

   sqlite3_stmt* stmt = select(db, pSQL);
   sqlite3_finalize(stmt);

   // while ( sqlite3_step(stmt) == SQLITE_ROW )
   // {
   //    cout << sqlite3_column_text(stmt, 0) << endl;
   //    cout << sqlite3_column_text(stmt, 1) << endl;
   //    cout << sqlite3_column_text(stmt, 2) << endl;
   //    cout << endl;
   // }

   sqlite3_close(db);
   return 0;
}

sqlite3_stmt *select(sqlite3 *db,const char* pSQL){
   sqlite3_stmt *stmt;
   sqlite3_prepare(db, pSQL, -1, &stmt, NULL);

   return stmt;
}

// static int callback(void *NotUsed, int argc, char **argv, char **azColName)
// {
//    for (int i = 0; i < argc; i++)
//       cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";

//    return 0;
// }

bool insertDB(char* str, sqlite3* db){
   int rc;

   rc = sqlite3_exec(db, str, NULL, 0, NULL);
   if(rc)   return false;

   return true;
}