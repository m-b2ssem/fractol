/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:11:27 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/18 18:27:46 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Usage: ./fractol mandelbrot or ./froctol julia with two values\n"
/* the width and height*/
# define W 600
# define H 600

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
}	t_f;

/*a struct of the complex math*/
typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex

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
double  m(double us_m, double m, double x, double o_x);
t_complex   sum(t_complex z1, t_complex z2);


#endif
