#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"


#define DB_NAME "training.db"

static int callback(void *data, int argc, char **argv, char **azColName)
{
	int i;
	fprintf(stdout, "%s: \n", (const char *)data);

	for (i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");

	return 0;
}

int main(int argc, char * argv[])
{
	sqlite3 *db;
	char *zErrMsg = NULL;

	int rc;
	char *sql = "SELECT * FROM knowledge";
	const char* data = "Callback function called";


	rc = sqlite3_open(DB_NAME, &db);

	if (rc) {
		fprintf(stderr, "Can't open database '%s' : %s\n", DB_NAME, sqlite3_errmsg(db));
		exit(EXIT_FAILURE);
	}
		
	fprintf(stdout, "Success to open database '%s'\n", DB_NAME);
	
	rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);
	
	if ( rc != SQLITE_OK ) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Operation done successfully\n");
	}

	
	sqlite3_close(db);

	return 0;
}
