#include <stdio.h>
#include <headers.h>
#include <glib-2.0/glib.h>


int main(int argc, char *argv[]) {


	Data_Passer data_passer;
	
	YLabel ylabel;
	ylabel.font_size = 15;
	g_stpcpy (ylabel.font_family,"sans-serif");
	g_stpcpy (ylabel.font_weight,"normal");
	g_stpcpy (ylabel.text_anchor,"end");
	g_stpcpy (ylabel.fill,"#000000");

	XLabel xlabel;
	xlabel.font_size = 15;
	g_stpcpy (xlabel.font_family,"sans-serif");
	g_stpcpy (xlabel.font_weight,"normal");
	g_stpcpy (xlabel.text_anchor,"end");
	g_stpcpy (xlabel.fill,"#000000");

	YTick ytick;
	ytick.stroke_width = 3;
	g_stpcpy (ytick.fill,"#000000");

	XTick xtick;
	ytick.stroke_width = 3;
	g_stpcpy (ytick.fill,"#000000");

	FILE *chart;
	chart = fopen("/tmp/chart.svg","w");
	fprintf(chart, "<svg version=\"1.1\" width=\"1400\" height=\"468\" xmlns=\"http://www.w3.org/2000/svg\">");

	/* Canvas */
	fprintf(chart, "<rect width=\"100%%\" height=\"100%%\" fill=\"white\"/>");

	/* Symbol */
	fprintf(chart, "<text x=\"716\" y=\"50\" font-size=\"40\" font-family=\"sans-serif\" font-weight=\"normal\" text-anchor=\"middle\" fill=\"black\">SYMBOL</text>");

	/* Chart border */
	fprintf(chart, "<rect x=\"176\" y=\"56\" width=\"1085\" height=\"361\" stroke=\"black\" stroke-width=\"3\" fill=\"white\"/>");


	/* Y label */
	fprintf(chart, "<text x=\"143\" y=\"167\" font-size=\"%d\" font-family=\"%s\" font-weight=\"%s\" text-anchor=\"%s\" dominant-baseline=\"middle\" fill=\"%s\">72.00</text>",ylabel.font_size, ylabel.font_family, ylabel.font_weight, ylabel.text_anchor, ylabel.fill);

	/* Y tick */
	fprintf(chart, "<line x1=\"166\" y1=\"167\" x2=\"176\" y2=\"167\" stroke=\"%s\" stroke-width=\"%d\" />", ytick.fill, ytick.stroke_width);


	/* X label */
	fprintf(chart, "<text x=\"272\" y=\"450\" font-size=\"%d\" font-family=\"%s\" font-weight=\"%s\" text-anchor=\"%s\" fill=\"%s\">12</text>",xlabel.font_size, xlabel.font_family, xlabel.font_weight, xlabel.text_anchor, xlabel.fill);

	/* X tick */
	fprintf(chart, "<line x1=\"272\" y1=\"417\" x2=\"272\" y2=\"427\" stroke=\"%s\" stroke-width=\"%d\" />", ytick.fill, ytick.stroke_width);

	/* Candle body */
	fprintf(chart, "<rect x=\"253\" y=\"195\" width=\"11\" height=\"40\" fill=\"#FF0000\"/>");

	/* Candle bottom wick */
	fprintf(chart, "<rect x=\"257\" y=\"235\" width=\"3\" height=\"2\" fill=\"green\"/>");

	/* Candle top wick */
	fprintf(chart, "<rect x=\"257\" y=\"176\" width=\"3\" height=\"19\" fill=\"green\"/>");


	fprintf(chart,"</svg>");

	fclose(chart);
}
