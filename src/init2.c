#include "../fractol.h"

char	what_color(t_data *data, char *option)
{
	if (!ft_strncmp(option, "original", 9))
		data->fc = 0;
	else if (!ft_strncmp(option, "d_red", 6))
		data->fc = 1;
	else if (!ft_strncmp(option, "d_green", 8))
		data->fc = 2;
	else if (!ft_strncmp(option, "d_blue", 7))
		data->fc = 3;
	else
		return (0);
	return (1);
}

void	init_burning_ship(t_data *data, char **option)
{
	data->f = &ft_burning_ship;
	if (option[0] == NULL)
		data->fc = 0;
	else
	{
		if (!what_color(data, option[0]) || option[1])
			bad_arg(data, 1);
	}
}

void	init_mandelbrot(t_data *data, char **option)
{
	if (option[0] != NULL && option[1] == NULL)
	{
		if (!ft_strncmp(option[0], "2", 2))
			data->f = &ft_formule_mandelbrot;
		else if (!ft_strncmp(option[0], "3", 2))
			data->f = &ft_formule_mandelbrot3;
		else if (!ft_strncmp(option[0], "-2", 2))
			data->f = &ft_formule_mandelbrotn2;
		else if (!what_color(data, option[0]))
			bad_arg(data, 1);
	}
	else if (option[0] != NULL && option[1] != NULL)
	{
		if (!ft_strncmp(option[1], "2", 2))
			data->f = &ft_formule_mandelbrot;
		else if (!ft_strncmp(option[1], "3", 2))
			data->f = &ft_formule_mandelbrot3;
		else if (!ft_strncmp(option[1],"-2", 2))
			data->f = &ft_formule_mandelbrotn2;
		else
			bad_arg(data, 1);
		if (!what_color(data, option[0]))
			bad_arg(data, 1);
	}
}

void	init_julia(t_data *data, char **option)
{
	if (option[0] && option[1] == NULL)
	{
		if (!what_color(data, option[0]))
			bad_arg(data, 1);
	}
	if (option[0] && option[1] && option[2] == NULL)
	{
		if (what_color(data, option[0]) && what_color(data, option[1]))
			bad_arg(data, 1);
		data->mt.c_r = ft_atolf(option[0]);
		data->mt.c_i = ft_atolf(option[1]);
		if ((data->mt.c_r == 0 && option[0][0] != 48) || (data->mt.c_i == 0 && option[1][0] != 48))
			bad_arg(data, 1);
	}
	if (option[0] && option[1] && option[2])
	{
		if (!what_color(data, option[0]))
			bad_arg(data, 1);
		data->mt.c_r = ft_atolf(option[1]);
		data->mt.c_i = ft_atolf(option[2]);
		if ((data->mt.c_r == 0 && option[1][0] != 48) || (data->mt.c_i == 0 && option[2][0] != 48))
			bad_arg(data, 1);
	}	
	
}

void	what_algo(t_data *data, char *name, char **option)
{
	if (!ft_strncmp(name, "Mandelbrot", 11))
	{
		data->f = &ft_formule_mandelbrot;
		if (option[0] == NULL)
			data->fc = 0; // couleur par default
		init_mandelbrot(data, option);
	}
	else if (!ft_strncmp(name, "Julia", 6))
	{
		data->f = &ft_julia;
		data->mt.c_r = 0.1;
		data->mt.c_i = -0.625;
		if (option[0] == NULL)
			bad_arg(data, 0);
		else
			init_julia(data, option);
	}
	else if (!ft_strncmp(name, "Burning_ship", 13))
		init_burning_ship(data, option);
}

