#include <glib-2.0/glib.h>
#include <headers.h>
#include <unistd.h>

GSList *read_activity_list(Data_Passer *data_passer) {
	if (access(data_passer->database_path, F_OK) != 0) {
		g_print("The database %s does not exist. Try again.\n", data_passer->database_path);
		exit(1);
	}

	int rc = sqlite3_open(data_passer->database_path, &(data_passer->database_handle));
	if (rc != SQLITE_OK) {
		g_print("Cannot open database: %s\n", data_passer->database_path);
		exit(1);
	}

	sqlite3_stmt *stmt;
	rc = sqlite3_prepare_v2(data_passer->database_handle, "SELECT trade_date, open, high, low, close FROM history WHERE run_date=? AND symbol_id=? AND api_id=? ORDER BY trade_date;", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		printf("Error executing sql statement\n");
		sqlite3_close(data_passer->database_handle);
		exit(-1);
	}

	sqlite3_bind_int(stmt, 1, 2460703);
	sqlite3_bind_int(stmt, 2, 1);
	sqlite3_bind_int(stmt, 3, 2);
	;

	while (sqlite3_step(stmt) != SQLITE_DONE) {
		for (int col = 0; col <= 4; col++) {
			if (col == 0) {
				printf("%d", sqlite3_column_int(stmt, col));
			} else {
				printf("  %5.2f", sqlite3_column_double(stmt, col));
			}
		}
		printf("\n");
	}

	sqlite3_finalize(stmt);

	sqlite3_close(data_passer->database_handle);
	return NULL;
}