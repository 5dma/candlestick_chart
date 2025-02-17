#include <time.h>
#include <stdio.h>
#include <glib-2.0/glib.h>
#include <sqlite3.h>

#define tick_length 10
#define attribute_length 100

typedef struct Activity {
	float open;
	float high;
	float low;
	float close;
	time_t *date;
} Activity;

typedef struct Candlestick {
	int body_width;
	int wick_width;
	char down_color[8];
	char up_color[8];
	
} Candlestick;

typedef struct YLabel {
	int font_size;
	char font_family[attribute_length];
	char font_weight[attribute_length];
	char text_anchor[attribute_length];
	char fill[8];
} YLabel;

typedef struct XLabel {
	int font_size;
	char font_family[attribute_length];
	char font_weight[attribute_length];
	char text_anchor[attribute_length];
	char fill[8];
} XLabel;


typedef struct YTick {
	char fill[8];
	int stroke_width;
} YTick;

typedef struct XTick {
	char fill[8];
	int stroke_width;
} XTick;

typedef struct Data_Passer {
	YLabel ylabel;
	XLabel xlabel;
	YTick ytick;
	XTick xtick;
	FILE *chart;
	GSList *activity_list;
	gchar *database_path;
	sqlite3 *database_handle;

} Data_Passer;


Data_Passer *initialize();
void read_activity_list(Data_Passer *data_passer);
void printit(gpointer data, gpointer user_data);
