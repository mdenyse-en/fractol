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

int	draw_f(int key, t_win *win) //main function that fill the image by values of struct "win"
{
	(void)key;
	clock_t			begin;
	clock_t			end;
	int				i;
	
	if (!win->h_key)
	{
// old one thread type of working
/*		begin = clock(); //control time that need for count "d" - main fractol parameter
		get_d(win, -1, -1, 0); //count d and choose color by it's value
		end = clock();
		printf("old type: %.3f, ", (double)(end - begin) / 1000000);
*/
		
		
// start threads (change THREADS_COUNT in fractol.h if you want to try different counts of threads and delete comments from needable threads callings)
		begin = clock();
 
		i = -1;
		while (++i < THREADS_COUNT)
			pthread_create(&win->threads[i].thr, NULL, ft_fill_img_all_thr, &win->threads[i]);
		i = -1;
		while (++i < THREADS_COUNT)
			pthread_join(win->threads[i].thr, NULL);

		end = clock();
		printf("threads works: %.3f, ", (double)(end - begin) / 1000000);

//drawing interface
		begin = clock();
		draw_int(win);
		mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
		ft_print_data(win);
		end = clock();
		printf("interface: %.3f\n", (double)(end - begin) / 1000000);
	}
	return (1);
}

void	create_win(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window (win->mlx, win->w_width, win->w_height, win->title);
	if (!win->win)
		terminate("Window does not created", 0);
	win->img.img = (int *)mlx_new_image (win->mlx, win->w_width, win->w_height);
	if (!win->img.img)
		terminate("Image does not created", 0);
	win->img.data = (int *)mlx_get_data_addr
		(win->img.img, &win->img.bpp, &win->img.size_l, &win->img.end);
	draw_f(0, win);
	mlx_mouse_hook (win->win, get_mouse, win);
	mlx_key_hook (win->win, get_keyboard, win);
	if (!(win->h_key))
		mlx_hook(win->win, 6, 0, move_mouse, win);
	mlx_hook(win->win, 17, 0, ft_close_p, win);
	mlx_hook(win->win, 5, 0, ft_mouse_wheel, win);
	if (!win->win)
		exit (0);
	mlx_loop (win->mlx);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc < 2)
		print_opport();
	else if (parc_param(argc, argv, &win))
		create_win(&win);
	else
		write(1, "unvalid parameters", ft_strlen("unvalid parameters"));
	return (0);
}
