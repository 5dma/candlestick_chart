#include <glib-2.0/glib.h>
#include <headers.h>
#include <stdio.h>

Data_Passer *initialize() {
	Data_Passer *data_passer = g_malloc(sizeof(Data_Passer));

	data_passer->ylabel.font_size = 15;
	g_stpcpy(data_passer->ylabel.font_family, "sans-serif");
	g_stpcpy(data_passer->ylabel.font_weight, "normal");
	g_stpcpy(data_passer->ylabel.text_anchor, "end");
	g_stpcpy(data_passer->ylabel.fill, "#000000");

	data_passer->xlabel.font_size = 15;
	g_stpcpy(data_passer->xlabel.font_family, "sans-serif");
	g_stpcpy(data_passer->xlabel.font_weight, "normal");
	g_stpcpy(data_passer->xlabel.text_anchor, "end");
	g_stpcpy(data_passer->xlabel.fill, "#000000");

	data_passer->ytick.stroke_width = 3;
	g_stpcpy(data_passer->ytick.fill, "#000000");

	data_passer->ytick.stroke_width = 3;
	g_stpcpy(data_passer->ytick.fill, "#000000");

	data_passer->chart = NULL;
	data_passer->database_path = NULL;
	data_passer->activity_list = NULL;
	return data_passer;
}
