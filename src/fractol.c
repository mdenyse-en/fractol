#include "fractol.h"

int	draw_f(int key, t_win *win);

void	print_opport(void)
{
	int		rs;
	int		fd;
	char	buf[100];

	fd = open ("./src/parameters.txt", O_RDONLY);
	if (fd != -1)
	{
		rs = 1;
		while (rs > 0)
		{
			rs = read(fd, buf, 100);
			write (1, buf, rs);
		}
		close(fd);
	}
}

void	fill_img(t_win *win)
{
	int		i;
	int		j;

	j = INTY - 1;
	while (++j < win->w_height)
	{
		i = INTX - 1;
		while (++i < win->w_width)
			win->img.data[j * win->w_width + i] = get_c_by_d(win->img.data
				[j * win->w_width + i], win->num, win->color, win->c_count);
	}
}

int	draw_f(int key, t_win *win)
{
	(void)key;
	if (!win->h_key)
	{
		get_d(win, -1, -1, 0);
		fill_img(win);
		draw_int(win);
		mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
		ft_print_data(win);
	}
	return (1);
}

void	create_win(t_win win)
{
	win.mlx = mlx_init();
	win.win = mlx_new_window (win.mlx, win.w_width, win.w_height, win.title);
	if (!win.win)
		terminate("Window does not created", 0);
	win.img.img = (int *)mlx_new_image (win.mlx, win.w_width, win.w_height);
	if (!win.img.img)
		terminate("Image does not created", 0);
	win.img.data = (int *)mlx_get_data_addr
		(win.img.img, &win.img.bpp, &win.img.size_l, &win.img.end);
	draw_f(0, &win);
	mlx_mouse_hook (win.win, get_mouse, &win);
	mlx_key_hook (win.win, get_keyboard, &win);
	if (!(win.h_key))
		mlx_hook(win.win, 6, 0, move_mouse, &win);
	mlx_hook(win.win, 17, 0, ft_close_p, &win);
	if (!win.win)
		exit (0);
	mlx_loop (win.mlx);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc < 2)
		print_opport();
	else if (parc_param(argc, argv, &win))
		create_win(win);
	else
		write(1, "unvalid parameters", ft_strlen("unvalid parameters"));
	return (0);
}
