/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:30:27 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/16 22:49:22 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static   size_t	ft_strlen(const char *str)
{
	const char	*i;

	i = str;
	while (*str)
		str++;
	return (str - i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		return ;
	}
	write (fd, s, ft_strlen(s));
}


void	elucation_error(void)
{
	perror("there is some problem with malloc");
	exit(1);
}

static void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->l_e) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pix_p + offset) = color;
}

void	pix_h(int x, int y, t_f *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;

	c.x = m(x, -2, +2, 0, W) + f->s_x;
	c.y = m(y, +2, -2, 0, H) + f->s_y;
	while (i < f->ither)
	{
		z = ft_sum(ft_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->sc)
		{
			color = m(i, BLACK, WHITE, 0, f->ither);
			put_pixel(x, y, &f->g, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &f->g, BLACK);
	
}