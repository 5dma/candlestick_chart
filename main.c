#include <glib-2.0/glib.h>
#include <headers.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
	if (argc < 2) {
		g_print("Specify a path to a SQLite database\n");
		exit(1);
	}

	Data_Passer *data_passer = initialize();
	data_passer->database_path = g_strdup(argv[1]);

	read_activity_list(data_passer);
	g_slist_foreach (data_passer->activity_list, printit, NULL);

	data_passer->chart = fopen("/tmp/chart.svg", "w");
	fprintf(data_passer->chart, "<svg version=\"1.1\" width=\"1400\" height=\"468\" xmlns=\"http://www.w3.org/2000/svg\">");

	/* Canvas */
	fprintf(data_passer->chart, "<rect width=\"100%%\" height=\"100%%\" fill=\"white\"/>");

	/* Symbol */
	fprintf(data_passer->chart, "<text x=\"716\" y=\"50\" font-size=\"40\" font-family=\"sans-serif\" font-weight=\"normal\" text-anchor=\"middle\" fill=\"black\">BARF</text>");

	/* Chart border */
	fprintf(data_passer->chart, "<rect x=\"176\" y=\"56\" width=\"1085\" height=\"361\" stroke=\"black\" stroke-width=\"3\" fill=\"white\"/>");

	/* Y label */
	fprintf(data_passer->chart, "<text x=\"143\" y=\"167\" font-size=\"%d\" font-family=\"%s\" font-weight=\"%s\" text-anchor=\"%s\" dominant-baseline=\"middle\" fill=\"%s\">72.00</text>", data_passer->ylabel.font_size, data_passer->ylabel.font_family, data_passer->ylabel.font_weight, data_passer->ylabel.text_anchor, data_passer->ylabel.fill);

	/* Y tick */
	fprintf(data_passer->chart, "<line x1=\"166\" y1=\"167\" x2=\"176\" y2=\"167\" stroke=\"%s\" stroke-width=\"%d\" />", data_passer->ytick.fill, data_passer->ytick.stroke_width);

	/* X label */
	fprintf(data_passer->chart, "<text x=\"272\" y=\"450\" font-size=\"%d\" font-family=\"%s\" font-weight=\"%s\" text-anchor=\"%s\" fill=\"%s\">12</text>", data_passer->xlabel.font_size, data_passer->xlabel.font_family, data_passer->xlabel.font_weight, data_passer->xlabel.text_anchor, data_passer->xlabel.fill);

	/* X tick */
	fprintf(data_passer->chart, "<line x1=\"272\" y1=\"417\" x2=\"272\" y2=\"427\" stroke=\"%s\" stroke-width=\"%d\" />", data_passer->ytick.fill, data_passer->ytick.stroke_width);

	/* Candle body */
	fprintf(data_passer->chart, "<rect x=\"253\" y=\"195\" width=\"11\" height=\"40\" fill=\"#FF0000\"/>");

	/* Candle bottom wick */
	fprintf(data_passer->chart, "<rect x=\"257\" y=\"235\" width=\"3\" height=\"2\" fill=\"green\"/>");

	/* Candle top wick */
	fprintf(data_passer->chart, "<rect x=\"257\" y=\"176\" width=\"3\" height=\"19\" fill=\"green\"/>");

	fprintf(data_passer->chart, "</svg>");

	fclose(data_passer->chart);
	g_free(data_passer->database_path);
	g_free(data_passer);
}
