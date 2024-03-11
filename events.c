/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:11:45 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/23 16:29:51 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	k_h(int keysym, t_f *f)
{
	if (keysym == XK_plus)
		f->ither += 10;
	else if (keysym == XK_minus)
		f->ither -= 10;
	else if (keysym == XK_Up)
		f->s_y += 0.5 * f->zoom;
	else if (keysym == XK_Down)
		f->s_y -= 0.5 * f->zoom;
	else if (keysym == XK_Right)
		f->s_x += 0.5 * f->zoom;
	else if (keysym == XK_Left)
		f->s_x -= 0.5 * f->zoom;
	else if (keysym == XK_Escape)
		c_h(f);
	f_r(f);
	return (0);
}

int	m_h(int btn, int x, int y, t_f *f)
{
	(void)x;
	(void)y;
	if (btn == 4)
	{
		f->zoom *= 0.90;
	}
	else if (btn == 5)
	{
		f->zoom *= 1.5;
	}
	f_r(f);
	return (0);
}
