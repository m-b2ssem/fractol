/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:54:19 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/26 21:44:12 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	c_h(t_f *f)
{
	mlx_destroy_image(f->m_c, f->g.i_p);
	mlx_destroy_window(f->m_c, f->wid);
	mlx_destroy_display(f->m_c);
	free(f->m_c);
	exit(0);
}

void	ft_julia(t_complex *z, t_complex *c, t_f *f)
{
	if (!ft_strncmp(f->n, "julia", 5))
	{
		c->x = f->j_x;
		c->y = f->j_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	pix_h(int x, int y, t_f *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (m(x, -2, +2, W) * f->zoom) + f->s_x;
	z.y = (m(y, +2, -2, H) * f->zoom) + f->s_y;
	ft_julia(&z, &c, f);
	while (i < f->ither)
	{
		z = ft_sum(ft_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->sc)
		{
			color = m(i, BLACK, ORANGE, f->ither);
			put_pixel(x, y, &f->g, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &f->g, WHITE);
}

bool	ft_valid_argv(char **argv, t_f *f)
{
	f->j_x = ft_atodbl(argv[2]);
	f->j_y = ft_atodbl(argv[3]);
	
	return (f->j_x > -2 && f->j_x < 2 && f->j_y > -2 && f->j_y < 2);	
}
