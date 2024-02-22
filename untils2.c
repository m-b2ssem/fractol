#include "fractol.h"

int    c_h(t_f *f)
{
    mlx_destroy_image(f->m_c, f->g.i_p);
    mlx_destroy_window(f->m_c, f->wid);
    mlx_destroy_display(f->m_c);
    free(f->m_c);
    exit(0);
}