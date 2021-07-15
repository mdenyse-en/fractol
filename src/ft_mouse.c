#include "fractol.h"

int		ft_mouse_wheel(int key, int x, int y, t_win *win)
{
	(void)win;
	(void)x;
	(void)y;

	if (key == 3)
		win->move_key.key_push = 0;
	return (1);
}

void	move_to_mmap(int x, int y, t_win *win)
{
	t_win	w1;
	double	tmp;
	double	cx;
	double	cy;

	w1.w = W;
	w1.px = PX;
	w1.py = PY;
	w1.height = win->height;
	w1.width = win->width;
	w1.num = 20;
	tmp = MW;
	tmp = (double)((x - MAPX) * win->width) / tmp;
	cx = find_cx(tmp, w1);
	tmp = MH;
	tmp = (double)((y - MAPY) * win->height) / tmp;
	cy = find_cy(tmp, w1);
	win->px = cx;
	win->py = cy;
}

int	get_mouse_2(int key, int x, int y, t_win *win)
{
	if (key == 4 && y > INTY)
	{
		win->px = (double)find_cx(x, *win);
		win->py = (double)find_cy(y - INTY, *win);
		win->w = win->w * ZOOM;
		win->px = (win->w * 0.5) - (double)x / win->width * win->w + win->px;
		win->py = win->py - ((win->w * 0.5 * win->height / win->width)
			- (double)(y - INTY) * win->w / win->width);
		if (win->z_ch_n_key)
			win->num = win->num + 2;
	}
	else if (key == 5 && y > INTY)
	{
		win->px = (double)find_cx(x, *win);
		win->py = (double)find_cy(y - INTY, *win);
		win->w = win->w / ZOOM;
		win->px = (win->w * 0.5) - (double)x / win->width * win->w + win->px;
		win->py = win->py - ((win->w * 0.5 * win->height / win->width)
			- (double)(y - INTY) * win->w / win->width);
		if (win->num > 21 && win->z_ch_n_key)
			win->num = win->num - 2;
	}
	else
		return (0);
	return (1);
}

int	get_mouse(int key, int x, int y, t_win *win)
{
	if (win->h_key)
		return (0);
	if (key == 1)
	{
		if (x < win->w_width && x > INTX && y < win->w_height && y > INTY)
		{
			win->px = find_cx(x, *win);
			win->py = find_cy(y - INTY, *win);
		}
		else if (x > MAPX && x < MAPX + MW && y > MAPY && y < MAPY + MH)
			move_to_mmap(x, y, win);
	}
	else if (key == 3 && win->move_key.key_push == 0)
	{
		win->move_key.key_push = 1;
		win->move_key.x = x;
		win->move_key.y = y;
	}
	/*else if (key == 3 && win->move_key.key_push == 1)
		win->move_key.key_push = 0;*/
	else if (!get_mouse_2(key, x, y, win))
		return (0);
	draw_f(0, win);
	return (1);
}

int	move_mouse(int x, int y, t_win *win)
{
	char	*s;

	if (!win->h_key)
	{
		if (y > INTY)
		{
			if (win->move_key.key_push)
			{
				win->px = win->px - (double)(x - win->move_key.x) * win->w / win->width;
				win->py = win->py + (double)(y - win->move_key.y) * win->w / win->width;
				win->move_key.x = x;
				win->move_key.y = y;
				draw_f(0, win);
			}
			draw_int(win);
			mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
			s = ft_dtoa(find_cx(x, *win), 5);
			mlx_string_put(win->mlx, win->win, AFTER_MINIMAP, 20, 0, s);
			free (s);
			s = ft_dtoa(find_cy(y - INTY, *win), 5);
			mlx_string_put(win->mlx, win->win, AFTER_MINIMAP, 30, 0, s);
			free(s);
			ft_print_data(win);
		}
	}
	return (0);
}
