#include <glib-2.0/glib.h>
#include <headers.h>

void printit(gpointer data, gpointer user_data) {
	Activity *activity = (Activity *) data;
	g_print("%ld %5.2f %5.2f %5.2f %5.2f\n", activity->date, activity->open, activity->high, activity->low, activity->close);
}