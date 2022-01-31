#include "fractol.h"

int	terminate(char *s, int n)
{
	ft_putendl_fd(s, 2);
	exit (n);
}

int	ft_close_p(t_win *win)
{
	(void)win;
	exit (0);
}

void	print_hint(t_win *win, int i, int j)
{
	while (++j < win->w_height)
	{
		i = -1;
		while (++i < win->w_width)
			win->img.data[j * win->w_width + i] = 0;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	j = win->w_height / 2 - 100;
	i = win->w_width / 2 - 180;
	put_hints(win, i, j);
}

void	put_hints(t_win *win, int i, int j)
{
	mlx_string_put(win->mlx, win->win, i + 140, j - 20,
		0xCCCCCC, "HELP");
	mlx_string_put(win->mlx, win->win, i, j,
		0xCCCCCC, "1, 2, 3, 4, 5, 6    - Show fractals");
	mlx_string_put(win->mlx, win->win, i, j + 20,
		0xCCCCCC, "-/+                 - Zoom (on center)");
	mlx_string_put(win->mlx, win->win, i, j + 40, 0xCCCCCC,
		",/.                 - Change count of interations");
	mlx_string_put(win->mlx, win->win, i, j + 60, 0xCCCCCC,
		"[, ]                - Change real (for Julia's set)");
	mlx_string_put(win->mlx, win->win, i, j + 80, 0xCCCCCC,
		"', \\                - Change imagine (for Julia)");
	mlx_string_put(win->mlx, win->win, i, j + 100, 0xCCCCCC,
		"R                   - Return w to base parameters");
	mlx_string_put(win->mlx, win->win, i, j + 120, 0xCCCCCC,
		"Mouse will (Scroll) - Zoom (on mouse position)");
	mlx_string_put(win->mlx, win->win, i, j + 140, 0xCCCCCC,
		"Mouse will (Press)  - Move by mouse (press again to cancel)");
	mlx_string_put(win->mlx, win->win, i, j + 160, 0xCCCCCC,
		"Mouse left button   - Move on mouse position");
	mlx_string_put(win->mlx, win->win, i, j + 180, 0xCCCCCC,
		"Arrows              - Move left, right, up, down");
	mlx_string_put(win->mlx, win->win, i, j + 200, 0xCCCCCC,
		"0, 9                - Change gradient");
	mlx_string_put(win->mlx, win->win, i, j + 220, 0xCCCCCC,
		"C                   - (ON/OFF) iterations when zooming");
	mlx_string_put(win->mlx, win->win, i + 100, j + 240,
		0xCCCCCC, "(press 'H' to close)");
}
