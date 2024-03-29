/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:24:43 by bmahdi            #+#    #+#             */
/*   Updated: 2024/03/01 16:11:08 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	events(t_f *f)
{
	mlx_hook(f->wid, KeyPress, KeyPressMask, k_h, f);
	mlx_hook(f->wid, ButtonPress, ButtonPressMask, m_h, f);
	mlx_hook(f->wid, DestroyNotify, StructureNotifyMask, c_h, f);
}

void	f_r(t_f *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			pix_h(x, y, f);
		}
	}
	mlx_put_image_to_window(f->m_c, f->wid, f->g.i_p, 0, 0);
}

void	data_init(t_f *f)
{
	f->sc = 4;
	f->ither = 100;
	f->s_x = 0;
	f->s_y = 0;
	f->zoom = 0.5;
}

void	f_i(t_f *f)
{
	f->m_c = mlx_init();
	if (f->m_c == NULL)
		elucation_error();
	f->wid = mlx_new_window(f->m_c, W, H, f->n);
	if (f->wid == NULL)
	{
		mlx_destroy_display(f->m_c);
		free(f->m_c);
		elucation_error();
	}
	f->g.i_p = mlx_new_image(f->m_c, W, H);
	if (f->g.i_p == NULL)
	{
		mlx_destroy_window(f->m_c, f->wid);
		mlx_destroy_display(f->m_c);
		free(f->m_c);
		elucation_error();
	}
	f->g.pix_p = mlx_get_data_addr(f->g.i_p, &f->g.bpp, &f->g.l_e, &f->g.ed);
	data_init(f);
	events(f);
}

int	main(int argc, char **argv)
{
	t_f	f;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		if (argc == 4)
		{
			if (!ft_valid_argv(argv[2]) || !ft_valid_argv(argv[3]))
			{
				ft_putstr_fd("please enter valid number", 2);
				exit(1);
			}
			f.j_x = ft_atodbl(argv[2]);
			f.j_y = ft_atodbl(argv[3]);
		}
		f.n = argv[1];
		f_i(&f);
		f_r(&f);
		mlx_loop(f.m_c);
	}
	else
	{
		ft_putstr_fd("invalid input", 2);
		exit(1);
	}
}
