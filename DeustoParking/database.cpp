extern "C" {
#include "sqlite3.h"
#include "reserva.h"
}
#include <stdio.h>
#include <string.h>

static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*) data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}

int cuentaReservas(sqlite3 *db) {
	sqlite3_stmt *stmt;
	char *zErrMsg = 0;
	int rc;
	int numReserv = 0;

	int result = sqlite3_exec(db, "SELECT COUNT(*) FROM RESERVA", callback, &numReserv, &zErrMsg);
	if (result) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		printf("count: %d\n", numReserv);
		return numReserv;
	}

	return numReserv;
}

void recogeReservas(Reserva*, sqlite3 *db) {


}

sqlite3* db;
int rc = sqlite3_open("test.db", &db);
int a = cuentaReservas(db)

