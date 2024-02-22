/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:11:27 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/20 23:48:01 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Usage: ./fractol mandelbrot or ./froctol julia with two values\n"
/* the width and height*/
# define W 800
# define H 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY 0x808080
# define DARK_GRAY 0x404040
# define LIGHT_GRAY 0xC0C0C0
# define ORANGE 0xFFA500
# define PURPLE 0x800080

/*
i_p is an image pointer
pix_p is the pixels pointer
bpp is for bits pixels pointer
*/

typedef struct	s_img
{
	void	*i_p;
	char	*pix_p;
	int	bpp;
	int	l_e;
	int	ed;
}	t_img;
/*
 m_c mlx connection for mlx_init.
 wid mlx for a new window mlx_new_window()
 g is the image
 n is the name of the program
*/
typedef struct	s_fractol
{
	void	*m_c;
	void	*wid;
	t_img	g;
	char	*n;
	double	sc;
	int		ither;
	double	s_x;
	double	s_y;
}	t_f;

/*a struct of the complex math*/
typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

/*libft function*/
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

/*error function*/
void	elucation_error(void);

/* math functions
the m function is 
sum function to grep the sum
of the z^2 + c
*/
double m(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
//double  m(double us_m, double m, double x, double o_x);
t_complex   ft_sum(t_complex z1, t_complex z2);
t_complex   ft_square(t_complex z);

/*fractol functions*/
void	f_r(t_f *f);
void	f_i(t_f *f);
void	pix_h(int x, int y, t_f *f);
void	events(t_f *f);
int k_h(int keycode, t_f *f);
int    c_h(t_f *f);

#endif
