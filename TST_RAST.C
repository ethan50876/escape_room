#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	blank_screen();
	
	fill_screen(base, -1);     /* set screen to all black */
	Cnecin();                  /* wait for key press, don't echo */

	fill_screen(base, 1);      /* set screen to all white */
	Cnecin();
	
	blank_screen();  
	plot_point(base,100,200);	/* plots 2 points */
	plot_point(base,200,250);
	Cnecin();
	
	blank_screen();
	plot_vline(base, 100, 100, 200);	/* vert line test */
	Cnecin();
	
	blank_screen();
	plot_hline(base, 100, 300, 250);	/* horz line test */
	Cnecin();
	
	blank_screen();
	plot_rectangle(base, 100, 100, 200, 100);	/* rectangle test */

	return 0;
}
