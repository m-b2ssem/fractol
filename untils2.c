#include "fractol.h"

int    c_h(t_f *f)
{
    mlx_destroy_image(f->m_c, f->g.i_p);
    mlx_destroy_window(f->m_c, f->wid);
    mlx_destroy_display(f->m_c);
    free(f->m_c);
    exit(0);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void    ft_julia(t_complex *z, t_complex *c, t_f *f)
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