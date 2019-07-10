#include <iostream>
#include <sqlite3.h>

#include "sqlite.h"

using namespace std;

int main()
{
    sqlite3_stmt *stmt;
    sqlite3_prepare(db, pSQL, -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        cout << sqlite3_column_text(stmt, 0) << endl;
        cout << sqlite3_column_text(stmt, 1) << endl;
        cout << sqlite3_column_text(stmt, 2) << endl;
    }
    return 0;
}