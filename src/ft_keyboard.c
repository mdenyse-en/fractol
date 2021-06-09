#include "fractol.h"

int	get_keyboard_5(int key, t_win *win)
{
	if (key == 18)
		win->type_f = 1;
	else if (key == 19)
		win->type_f = 2;
	else if (key == 20)
		win->type_f = 3;
	else if (key == 21)
		win->type_f = 4;
	else if (key == 23)
		win->type_f = 5;
	else if (key == 22)
		win->type_f = 6;
	else
		return (0);
	return (1);
}

int	get_keyboard_4(int key, t_win *win)
{
	if (key == 15)
		win->w = W;
	else if (key == 33)
		win->jx = win->jx - 0.002;
	else if (key == 30)
		win->jx = win->jx + 0.002;
	else if (key == 35)
		win->jx = win->jx * -1;
	else if (key == 39)
		win->jy = win->jy - 0.002;
	else if (key == 42)
		win->jy = win->jy + 0.002;
	else if (key == 53)
		win->jy = win->jy * -1;
	else
		return (get_keyboard_5(key, win));
	return (1);
}

int	get_keyboard_3(int key, t_win *win)
{
	if (key == 121)
	{
		if (win->color > 1 + win->c_count)
			win->color--;
		else
		{
			if (win->c_count > 1)
				win->c_count--;
			else
				win->c_count = COLORS_MAX;
			win->color = COLORS_MAX - win->c_count + 1;
		}
	}
	else if (key == 4)
	{
		win->h_key = 1;
		print_hint(win, -1, -1);
		return (0);
	}
	else
		return (get_keyboard_4(key, win));
	return (1);
}

int	get_keyboard_2(int key, t_win *win)
{
	if (key == 78 && win->num > 10)
	{
		if (win->num > COLORS_MAX * 2)
			win->num = win->num / 1.5;
	}
	else if (key == 116)
	{
		if (win->color < COLORS_MAX - win->c_count)
			win->color++;
		else
		{
			if (win->c_count < COLORS_MAX)
				win->c_count++;
			else
				win->c_count = 1;
			win->color = 1;
		}
	}
	else
		return (get_keyboard_3(key, win));
	return (1);
}

int	get_keyboard(int key, t_win *win)
{
	if (key == 53)
		exit(0);
	if ((key == 0 || win->h_key) && (key != 4))
		return (0);
	if (win->h_key && key == 4)
		win->h_key = 0;
	else if (key == 123)
		win->px = win->px - win->w * 0.02;
	else if (key == 124)
		win->px = win->px + win->w * 0.02;
	else if (key == 125)
		win->py = win->py - win->w * 0.02;
	else if (key == 126)
		win->py = win->py + win->w * 0.02;
	else if (key == 24)
		win->w = win->w * 0.5;
	else if (key == 27)
		win->w = win->w * 2;
	else if (key == 69)
		win->num = win->num * 1.5;
	else if (!get_keyboard_2(key, win))
		return (0);
	draw_f(0, win);
	return (1);
}
