#include "fractol.h"

int k_h(int keysym, t_f *f)
{
    if (keysym == XK_plus)
        f->ither += 10;
    else if (keysym == XK_minus)
        f->ither -= 10;
    else if (keysym == XK_Up)
        f->s_y -= 0.5;
    else if (keysym == XK_Down)
        f->s_y += 0.5;
    else if (keysym == XK_Right)
        f->s_x -= 0.5;
    else if (keysym == XK_Left)
        f->s_x += 0.5;
    else if (keysym == XK_Escape)
        c_h(f);//todo
    f_r(f);
    return 0;
}