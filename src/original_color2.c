#include "../fractol.h"

void	original5(t_color *color, int *iteration)
{
	if (*iteration > 0 && *iteration >= 26)
	{
		color->r += 51;
		color->g -= 51;
	}
	else if (*iteration > 0)
	{
		color->r += (*iteration * 2);
		color->g -= (*iteration * 2);
	}
	*iteration = *iteration - 26;
	if (*iteration > 0 && *iteration >= 51)
	{
		color->b -= 102;
		color->g -= 102;
	}
	else if (*iteration > 0)
	{
		color->b -= (*iteration * 2);
		color->g -= (*iteration * 2);
	}
	*iteration = *iteration - 51;	
	if (*iteration > 0 && *iteration >= 64)
		color->b -= 127;
}

void	original6(t_color *color, int *iteration)
{
	if (*iteration > 0 && *iteration < 64)
		color->b -= (*iteration * 2);
	*iteration = *iteration - 64;
	if (*iteration > 0 && *iteration >= 25)
	{
		color->b += 25;
		color->g += 25;
	}
	else if (*iteration > 0)
	{
		color->b += *iteration;
		color->g += *iteration;
	}
	*iteration = *iteration - 25;
}

