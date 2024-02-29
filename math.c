/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:54:02 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/25 20:18:11 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*m is a function to scale the valus
of the pixsel.
the us_m is for unsvaled number
m for new minimum
x for new maximum
o_x for old maximum
*/

double	m(double us_m, double m, double x, double o_x)
{
	return ((x - m) * (us_m - 0) / (o_x - 0) + m);
}

t_complex	ft_sum(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	ft_square(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

double	ft_atodbl(char *s)
{
	long	i;
	double	d;
	double	pow;
	int		sign;

	i = 0;
	d = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		d = d + (*s++ - 48) * pow;
	}
	return ((i + d) * sign);
}
