#include "../fractol.h"

static void	lennb(unsigned long nb, int *t)
{
	int	i;

	i = 0;
	if (nb == 0)
		*t = *t + 1;
	else
	{
		while (nb != 0)
		{
			nb /= 10;
			*t = *t + 1;
			i++;
			if (i % 3 == 0)
				*t = *t + 1;
		}
		if (i % 3 == 0)
			*t = *t - 1;
	}
}

char	*ft_itoal(unsigned long nb)
{
	int		t;
	int		i;
	char	*str;

	t = 0;
	i = 1;
	lennb(nb, &t);
	str = malloc(sizeof(char) * (t + 1));
	if (str == NULL)
		return (NULL);
	str[t] = '\0';
	while (t > 0)
	{
		t--;
		if (t > 0 && i % 4 == 0)
			str[t] = 32;
		else
		{
			str[t] = nb % 10 + 48;
			nb /= 10;
		}
		i++;
	}
	return (str);
}

void	stringput(t_data *data)
{
	char	*s;
	char	*fs;

	s = ft_itoal(data->p.zoom);
	if (!s)
		return ;
	fs = ft_strjoin("ZOOM * ", s);
	free(s);
	if (fs)
		mlx_string_put(data->mlx, data->mlx_win, 0, 10, 0x808080, fs);
	free(fs);
	s = ft_itoal(data->max_iteration);
	if (!s)
		return ;
	fs = ft_strjoin("max_iteration = ", s);
	free(s);
	if (fs)
		mlx_string_put(data->mlx, data->mlx_win, 0, 20, 0x808080, fs);
	free(fs);
}

long	midatolf(char *str, int *i, int *signe)
{
	long	l;
	
	l = 0.0;
	while (str[*i] == 32 || (str[*i] <= 13 && str[*i] >= 9))
		*i = *i + 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*signe = -1;
		*i = *i + 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		l = l * 10 + str[*i] - 48;
		*i = *i + 1;
	}
	if (str[*i] == '.' && str[*i + 1] >= '0' && str[*i + 1] <= '9')
		*i = *i + 1;
	while (str[*i + 1] >= '0' && str[*i + 1] <= '9')
		*i = *i + 1;
	return (l);
}

long double	ft_atolf(char *str)
{
	long double	r;
	long	l;
	int	i;
	int	signe;

	signe = 1;
	r = 0.0;
	i = 0;
	l = midatolf(str, &i, &signe);
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r / 10.0 + str[i] - 48;
		i--;
	}
	return (((double)l + r / 10) * signe);
}
