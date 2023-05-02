/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefinition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:22:56 by kscordel          #+#    #+#             */
/*   Updated: 2023/05/02 16:44:25 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom(t_point *p, int E)
{
	long double	dif;

	dif = (p->ecart - ((long double)E / (long double)p->zoom)) / (long double)2;
	if (p->x1 > 0)
		p->x1 = p->x1 + dif;
	else
		p->x1 = p->x1 + dif;
	if (p->x2 > 0)
		p->x2 = p->x2 - dif;
	else
		p->x2 = p->x2 - dif;
	if (p->y1 > 0)
		p->y1 = p->y1 + dif;
	else
		p->y1 = p->y1 + dif;
	if (p->y2 > 0)
		p->y2 = p->y2 - dif;
	else
		p->y2 = p->y2 - dif;
	p->ecart = (long double)E / (long double)p->zoom;
}

void	redefinition(t_point *p, int x, int y, int E)
{
	int	m;
	int	r;

	m = E / 2;
	r = x - m;
	p->x1 = p->x1 + ((double)r / (double)p->zoom);
	p->x2 = p->x2 + ((double)r / (double)p->zoom);
	r = (y - m) * -1;
	p->y1 = p->y1 + ((double)r / (double)p->zoom);
	p->y2 = p->y2 + ((double)r / (double)p->zoom);
}
