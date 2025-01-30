#include <glib-2.0/glib.h>
#include <headers.h>
#include <unistd.h>

time_t *get_time(int julian) {
	int l = julian + 68569;
	int n = 4 * l / 146097;
	l = l - (146097 * n + 3) / 4;
	int i = 4000 * (l + 1) / 1461001;
	l = l - 1461 * i / 4 + 31;
	int j = 80 * l / 2447;
	int k = l - 2447 * j / 80;
	l = j / 11;
	j = j + 2 - 12 * l;
	i = 100 * (n - 49) + i + l;
	int year = i;
	int month = j;
	int day = k;
	struct tm tm;
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;

	time_t *localtime = g_malloc(sizeof(time_t));
	*localtime = mktime(&tm);
	return localtime;
}

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


	while (sqlite3_step(stmt) != SQLITE_DONE) {
		for (int col = 0; col <= 4; col++) {
			if (col == 0) {
				int julian = sqlite3_column_int(stmt, col);
				get_time(julian);
				printf("%d", julian);
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