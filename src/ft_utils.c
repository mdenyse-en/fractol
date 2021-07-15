#include "fractol.h"

void	ft_return_base(t_win *win)
{
	win->px = PX;
	win->py = PY;
	win->w = W;
	win->num = NUM;
	win->jx = 0.28;
	win->jy = 0.008;
}