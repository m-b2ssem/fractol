/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:54:02 by bmahdi            #+#    #+#             */
/*   Updated: 2024/02/18 18:27:55 by bmahdi           ###   ########.fr       */
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
double  m(double us_m, double m, double x, double o_x) // understand more
{
    return ((x - m) * (us_m - 0) / (o_x - 0) + m);
}

t_complex   sum(t_complex z1, t_complex z2)
{
    t_complex   result;
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
}