/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:24:43 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/20 17:21:47 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	f_r(t_f *f)
{
	int	x;
	int	y;
	
	y = -1;
	while(++y < H)
	{
		y = -1;
		while(++x < W)
		{
			pix_h(x, y, f);
		}
	}
	mlx_put_image_to_window(f->m_c, f->wid, f->g.i_p, 0, 0);
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
	
}

int	main(int argc, char **argv)
{
	t_f	f;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		// fractol initialization
		f.n = argv[1];
		f_i(&f);
		// fractol render
		f_r(&f);
		// to watch even from the mouse and keys
		mlx_loop(f.m_c);
	}
	else	
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(1);
	}

}
