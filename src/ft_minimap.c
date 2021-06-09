#include "fractol.h"

static t_win	init_win_mini(t_win win)
{
	t_win	w1;

	w1.w = W;
	w1.px = PX;
	w1.py = PY;
	w1.height = win.height;
	w1.width = win.width;
	w1.num = MAPNUM;
	w1.jx = win.jx;
	w1.jy = win.jy;
	return (w1);
}

static int	find_d_for_mini(t_win win, t_win *w1, double cx, double cy)
{
	int	d;

	if (win.type_f == 1)
		d = find_d (cx, cy, w1->num);
	else if (win.type_f == 2)
	{
		w1->px = w1->jx;
		w1->py = w1->jy;
		d = find_d_julia (cx, cy, *w1);
	}
	else if (win.type_f == 3)
		d = find_d_newton (cx, cy, *w1);
	else if (win.type_f == 4)
		d = find_d_maldbar (cx, cy, *w1);
	else if (win.type_f == 5)
		d = find_d_b_ship (cx, cy, *w1);
	else
		d = find_d_c_mald (cx, cy, *w1);
	return (d);
}

void	ft_draw_mini_2(t_win *win, int x, int y, t_comp tmp)
{
	int	i;
	int	j;

	if (y < MAPY + tmp.y)
		y = MAPY + tmp.y;
	else if (y > MAPY + MH - tmp.y)
		y = MAPY + MH - tmp.y;
	j = y - tmp.y;
	while (++j < y + tmp.y)
	{
		if (x < MAPX + tmp.x)
			x = MAPX + tmp.x;
		else if (x > MAPX + MW - tmp.x)
			x = MAPX + MW - tmp.x;
		i = x - tmp.x;
		while (++i < x + tmp.x)
		{
			if (i == x - tmp.x + 1 || i == x + tmp.x - 1)
				win->img.data[j * win->width + i] = get_trgb(0, 200, 200, 200);
			if (j == y - tmp.y + 1 || j == y + tmp.y - 1)
				win->img.data[j * win->width + i] = get_trgb(0, 200, 200, 200);
		}
	}
}

void	ft_draw_mini(int x, int y, t_win *win)
{
	double	wm;
	double	hm;
	t_comp	tmp;

	wm = (double)win->w / W * MW;
	hm = (double)(win->w) / W * MH * win->height / win->width;
	if (wm < 10)
	{
		wm = 10;
		hm = (double)win->height / win->width;
		hm = hm * 10;
	}
	else if (wm > MW || hm > MH)
	{
		wm = MW;
		hm = MH;
	}
	tmp.x = (int)wm / 2;
	tmp.y = (int)hm / 2;
	ft_draw_mini_2(win, x, y, tmp);
}

void	ft_draw_minimap(int i, int j, t_win *win)
{
	double	cx;
	double	cy;
	int		d;
	double	tmp;
	t_win	w1;

	w1 = init_win_mini(*win);
	tmp = MW;
	tmp = (double)((i - MAPX) * win->width) / tmp + w1.px;
	cx = find_cx(tmp, w1);
	tmp = MH;
	tmp = (double)((j - MAPY) * win->height) / tmp + w1.py;
	cy = find_cy(tmp, w1);
	d = find_d_for_mini(*win, &w1, cx, cy);
	if (d == MAPNUM)
	{
		win->img.data[j * win->width + i] = get_trgb(0, 20, 20, 20);
	}
	else
		win->img.data[j * win->width + i] = get_trgb(0, 150, 150, 150);
}
