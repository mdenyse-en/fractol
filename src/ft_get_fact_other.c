#include "fractol.h"

int	find_d_newton (double cx, double cy, t_win win)
{
	int		i;
	double	tmp;
	t_comp	z;
	t_comp	d;
	t_comp	t;

	i = -1;
	z.x = cx;
	z.y = cy;
	d = z;
	while (i++ < win.num && (z.x * z.x + z.y * z.y) < NMAX
		&& (d.x * d.x + d.y * d.y) > NMIN)
	{
		t = z;
		tmp = (t.x * t.x + t.y * t.y) * (t.x * t.x + t.y * t.y);
		z.x = (double)(2) / 3 * t.x + (t.x * t.x - t.y * t.y) / (3 * tmp);
		z.y = (double)(2) / 3 * t.y * (double)(1 - (double)t.x / tmp);
		d.x = (t.x - z.x);
		if (d.x < 0)
			d.x = (double)d.x * -1;
		d.y = (t.y - z.y);
		if (d.y < 0)
			d.y = (double)d.y * -1;
	}
	return (--i);
}

int	find_d_maldbar(double cx, double cy, t_win win)
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
	while (i++ < win.num && fsq <= 4)
	{
		tmp = dx;
		dx = dx * dx - dy * dy + cx;
		dy = -2.0 * tmp * dy + cy;
		fsq = dx * dx + dy * dy;
	}
	return (--i);
}

int	find_d_b_ship(double cx, double cy, t_win win)
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
	while (i++ < win.num && fsq <= 4)
	{
		tmp = dx;
		dx = dx * dx - dy * dy + cx;
		tmp = tmp * dy;
		if (tmp < 0)
			tmp = tmp * -1;
		dy = -2 * tmp + cy;
		fsq = dx * dx + dy * dy;
	}
	return (--i);
}

int	find_d_c_mald(double cx, double cy, t_win win)
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
	while (i++ < win.num && fsq <= 4)
	{
		tmp = dx;
		dx = dx * dx - dy * dy;
		if (dx < 0)
			dx = dx * -1;
		dx = dx + cx;
		dy = 2.0 * tmp * dy + cy;
		fsq = dx * dx + dy * dy;
	}
	return (--i);
}
