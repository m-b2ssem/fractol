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

void	pix_h(int x, int y, t_f *f)
{
	t_complex	z;
	t_complex	c;

	z.x = 0.0;
	z.y = 0.0;

	c.x = m(x, -2, +2, W);
	c.y = m(y, +2, -2, H);
}