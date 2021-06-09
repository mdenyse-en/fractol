#include "fractol.h"

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_d(t_win *win, int i, int j, int d)
{
	int	x;
	int	y;

	while (++j < win->w_height)
	{
		y = j - INTY;
		i = INTX - 1;
		while (++i < win->w_width)
		{
			x = i - INTX;
			if (win->type_f == 1)
				d = find_d (find_cx (x, *win), find_cy (y, *win), win->num);
			else if (win->type_f == 2)
				d = find_d_julia (find_cx (x, *win), find_cy (y, *win), *win);
			else if (win->type_f == 3)
				d = find_d_newton (find_cx (x, *win), find_cy (y, *win), *win);
			else if (win->type_f == 4)
				d = find_d_maldbar (find_cx (x, *win), find_cy (y, *win), *win);
			else if (win->type_f == 5)
				d = find_d_b_ship (find_cx (x, *win), find_cy (y, *win), *win);
			else if (win->type_f == 6)
				d = find_d_c_mald (find_cx (x, *win), find_cy (y, *win), *win);
			win->img.data[j * win->w_width + i] = d;
		}
	}
}

int	get_color(int i, double tmp)
{
	// if (i == 0)
	// 	return (get_trgb (0, 255 - 250 * tmp, 255 - 200 * tmp, 100 - 50 * tmp));
	// else if (i == 1)
	// 	return (get_trgb (0, 5 + 230 * tmp, 55 + 100 * tmp, 50 + 50 * tmp));
	// else if (i == 2)
	// 	return (get_trgb (0, 235 + 15 * tmp, 155 + 75 * tmp, 100 + 155 * tmp));
	// else if (i == 3)
	// 	return (get_trgb (0, 250 - 250 * tmp, 230 - 80 * tmp, 255 - 55 * tmp));
	// else if (i == 4)
	// 	return (get_trgb (0, 0 + 200 * tmp, 150 - 50 * tmp, 200 + 55 * tmp));
	// else if (i == 5)
	// 	return (get_trgb (0, 200 + 55 * tmp, 100 + 100 * tmp, 255 - 55 * tmp));
	// else if (i == 6)
	// 	return (get_trgb (0, 255 - 155 * tmp, 200 + 55 * tmp, 200 - 100 * tmp));
	// else if (i == 7)
	// 	return (get_trgb (0, 50 + 100 * tmp, 255 - 155 * tmp, 100 - 100 * tmp));
	// else if (i == 8)
	// 	return (get_trgb (0, 150 + 100 * tmp, 100 + 100 * tmp, 0 + 100 * tmp));
	// else if (i == 9)
	// 	return (get_trgb (0, 250 + 0 * tmp, 200 + 50 * tmp, 100 + 0 * tmp));
	// else if (i == 10)
	// 	return (get_trgb
	// 		(0, 255 - 250 * tmp, 255 - 255 * tmp, 100 - 100 * tmp));
	// else
	// 	return (get_trgb (0, 0, 0, 0));
	if (i == 0)
		return (get_trgb (0, 0 + 250 * tmp * tmp, 0 + 200 * tmp * tmp, 50 + 200 * tmp));
	else if (i == 1)
		return (get_trgb (0, 250 - 230 * tmp * tmp, 200 - 100 * tmp * tmp, 250 - 50 * tmp));
	else if (i == 2)
		return (get_trgb (0, 20 + 100 * tmp * tmp, 100 + 80 * tmp * tmp, 200 + 50 * tmp));
	else if (i == 3)
		return (get_trgb (0, 120 - 120 * tmp, 180 - 80 * tmp * tmp, 250 - 50 * tmp));
	else if (i == 4)
		return (get_trgb (0, 0 + 200 * tmp, 100 - 100 * tmp * tmp, 200 + 50 * tmp));
	else if (i == 5)
		return (get_trgb (0, 200 + 55 * tmp * tmp, 0+ 100 * tmp, 250 - 150 * tmp));
	else
		return (get_trgb (0, 0, 0, 0));
}

int	get_c_by_d(int d, int num, int c, int c_count)
{
	double	tmp;
	int		i;

	tmp = -1;
	if (d == num)
		i = 11;
	else
	{
		tmp = (double)num / c_count;
	 	i = (d * c_count) / num;
		tmp = (double)(d - i * tmp) / (tmp);
	}
	i = i + c - 1;
	return (get_color(i, tmp));
}
