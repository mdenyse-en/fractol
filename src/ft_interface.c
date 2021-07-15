#include "fractol.h"

t_interf	ft_get_interf_size(char type, t_win win)
{
	t_interf	res;

	if (type == 'm')
	{
		res.x = MAPX;
		res.y = MAPY;
		res.w = MW;
		res.h = MH;
	}
	else if (type == 'g')
	{
		res.x = win.w_width - 220;
		res.y = 20;
		res.w = 200;
		res.h = 20;
	}
	else if (type == '1')
	{
		res.x = 10;
		res.y = 5;
		res.w = MAPX - 30;
		res.h = 11;
	}
	else if (type == '2')
	{
		res.x = 10;
		res.y = 18;
		res.w = MAPX - 30;
		res.h = 11;
	}
	else if (type == '3')
	{
		res.x = 10;
		res.y = 31;
		res.w = MAPX - 30;
		res.h = 11;
	}
	else if (type == '4')
	{
		res.x = 10;
		res.y = 44;
		res.w = MAPX - 30;
		res.h = 11;
	}
	else
		res.x = 0;
	return (res);
}

void	ft_obvodka(char type, t_win *win)
{
	int			i;
	int			j;
	t_interf	in;

	in = (ft_get_interf_size(type, *win));
	i = in.x;
	j = in.y;
	while (i <= in.x + in.w)
		win->img.data[j * (win->width) + i++] = OBV_DARK;
	i = in.x;
	j = in.y + in.h;
	while (i <= in.x + in.w)
		win->img.data[j * (win->width) + i++] = OBV_LIGHT;
	i = in.x;
	j = in.y - 1;
	while (++j <= in.y + in.h - 1)
		win->img.data[j * win->width + i] = OBV_DARK;
	i = in.x + in.w;
	j = in.y - 1;
	while (++j <= in.y + in.h - 1)
		win->img.data[j * win->width + i] = OBV_LIGHT;
}

void	ft_draw_panel(t_win *win, int i, int j)
{
	j = -1;
	while (++j < INTY)
	{
		i = -1;
		while (++i < win->width)
		{
			if (i > win->width - 220 && i < win->width - 20 && j > 20 && j < 40)
				win->img.data[j * win->width + i] = get_c_by_d(
						(i - win->width + 220) * (double)(win->num) / 200,
						win->num, win->color, win->c_count);
			else if (i > MAPX && i < MAPX + MW && j > MAPY && j < MAPY + MH)
				ft_draw_minimap(i, j, win);
		//	else if (i >= 10 && i <= 10 + MAPX - 30 && j >= 6 && j <= INTY - 6)  //(cod 43)that part for numbers fields (I think that it was unnecessary)
		//		win->img.data[j * win->width + i] = 0x00999999;
			else
				win->img.data[j * win->width + i] = get_trgb(0, 240 - (j / 2
							+ 20), 240 - (j / 2 + 20), 240 - (j / 2 + 20));
		}
	}
	i = -1;
	while (++i < win->width)
	{
		win->img.data[j * win->width + i] = get_trgb(0, 160, 160, 160);
	}
}

void	draw_int(t_win *win)
{
	double	vx;
	double	vy;

	ft_draw_panel(win, -1, -1);
	ft_obvodka('m', win);
	ft_obvodka('g', win);
/*	ft_obvodka('1', win);  //(cod 43)that part for numbers fields (I think that it was unnecessary)
	ft_obvodka('2', win);
	ft_obvodka('3', win);
	ft_obvodka('4', win);*/
	vx = MAPX + MW / 2 + MW / W * (win->px - PX);
	vy = MAPY + MH / 2 - MH / W * (win->py - PY);
	ft_draw_mini(vx, vy, win);
	ft_print_data(win);
}

void	ft_print_data(t_win *win)
{
	char	*s;

	s = ft_itoa(win->num);
	mlx_string_put(win->mlx, win->win, 20, 15, 0x00000000, s);
	free (s);
	s = ft_dtoa(win->w, 16);
	mlx_string_put(win->mlx, win->win, 20, 28, 0x00000000, s);
	free(s);
	s = ft_dtoa(win->px, 16);
	mlx_string_put(win->mlx, win->win, 20, 41, 0x00000000, s);
	free(s);
	s = ft_dtoa(win->py, 16);
	mlx_string_put(win->mlx, win->win, 20, 54, 0x00000000, s);
	free(s);
	mlx_string_put(win->mlx, win->win, AFTER_MINIMAP, 50, 0, "H - show help");
	if (win->type_f == 2)
	{
		s = ft_dtoa(win->jx, 10);
		mlx_string_put(win->mlx, win->win, AFTER_MINIMAP + 100, 20, 0, s);
		free (s);
		s = ft_dtoa(win->jy, 10);
		mlx_string_put(win->mlx, win->win, AFTER_MINIMAP + 100, 30, 0, s);
		free(s);
	}
}
