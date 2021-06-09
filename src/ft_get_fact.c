#include "fractol.h"

double	find_cx(int i, t_win win)
{
	double	r;
	double	res;

	r = win.width / win.height;
	res = i;
	res = res / win.width;
	res = res * win.w;
	res = res + win.px - (win.w / 2);
	return (res);
}

double	find_cy(int j, t_win win)
{
	double	r;
	double	res;

	r = win.w * win.height / win.width;
	res = j;
	res = res / win.height;
	res = res * r;
	res = win.py + r / 2 - res;
	return (res);
}

int	find_d(double cx, double cy, int num)
{
	int		i;
	double	dx;
	double	dy;
	double	fsq;
	double	tmp;

	i = 0;
	dx = cx;
	dy = cy;
	fsq = cx * cx + cy * cy;
	while (i++ < num && fsq <= 4)
	{
		tmp = dx;
		dx = dx * dx - dy * dy + cx;
		dy = 2.0 * tmp * dy + cy;
		fsq = dx * dx + dy * dy;
	}
	return (--i);
}

int	find_d_julia(double cx, double cy, t_win win)
{
	int		i;
	double	dx;
	double	dy;
	double	fsq;
	double	tmp;

	i = -1;
	dx = cx;
	dy = cy;
	cx = win.jx;
	cy = win.jy;
	fsq = cx * cx + cy * cy;
	while (i++ < win.num && fsq <= 4)
	{
		tmp = dx;
		dx = dx * dx - dy * dy + cx;
		dy = 2.0 * tmp * dy + cy;
		fsq = dx * dx + dy * dy;
	}
	return (--i);
}
