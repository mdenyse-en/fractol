#include "fractol.h"

void	get_win_size(char **argv, t_win *win, int i)
{
	if (argv[i][0] == 'x' && ft_isdigit(argv[i][1]))
	{
		win->w_width = ft_atoi(argv[i] + 1);
		if (win->w_width < 700)
			win->w_width = 700;
		if (win->w_width > 2400)
			win->w_width = 2400;
	}
	if (argv[i][0] == 'y' && ft_isdigit(argv[i][1]))
	{
		win->w_height = ft_atoi(argv[i] + 1);
		if (win->w_height < 400)
			win->w_height = 400;
		if (win->w_height > 1300)
			win->w_height = 1300;
	}
}

void	get_further_par(int argc, char **argv, t_win *win)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == 'c' && argv[i][1] == 'x' &&
			(ft_isdigit(argv[i][2]) || argv[i][2] == '-'))
			win->jx = ft_atod(argv[i] + 2);
		if (argv[i][0] == 'c' && argv[i][1] == 'y' &&
			(ft_isdigit(argv[i][2]) || argv[i][2] == '-'))
			win->jy = ft_atod(argv[i] + 2);
		if ((argv[i][0] == 'x' || argv[i][0] == 'y') && ft_isdigit(argv[i][1]))
			get_win_size(argv, win, i);
		if (argv[i][0] == 'p' && argv[i][1] == 'x' && ft_isdigit(argv[i][2]))
			win->px = ft_atod(argv[i] + 2);
		if (argv[i][0] == 'p' && argv[i][1] == 'y' && ft_isdigit(argv[i][2]))
			win->py = ft_atod(argv[i] + 2);
		if (argv[i][0] == 'w' && ft_isdigit(argv[i][1]))
			win->w = ft_atod(argv[i] + 1);
		if (argv[i][0] == 'i' && ft_isdigit(argv[i][1]))
			win->num = ft_atoi(argv[i] + 1);
	}
}

void	choose_title(t_win *win)
{
	if (win->type_f == 1)
		win->title = "Mandelbrot";
	else if (win->type_f == 2)
	{
		win->title = "Julia";
		win->px = win->jx;
		win->py = win->jy;
	}
	else if (win->type_f == 3)
		win->title = "Newtons pools";
	else if (win->type_f == 4)
		win->title = "Mandelbar";
	else if (win->type_f == 5)
		win->title = "Burning ship";
	else if (win->type_f == 6)
		win->title = "Celtic Maldebrot";
}

int	parc_param(int argc, char **argv, t_win *win)
{
	if (!(argv[1][0] == '1' || argv[1][0] == '2' || argv[1][0] == '3'
		|| argv[1][0] == '4' || argv[1][0] == '5' || argv[1][0] == '6'))
		return (0);
	win->w_width = WIDTH;
	win->w_height = HEGHT;
	win->px = PX;
	win->py = PY;
	win->w = W;
	win->num = NUM;
	win->h_key = 0;
	win->move_key.key_push = 0;
	win->z_ch_n_key = 1;
	win->jx = 0.28;
	win->jy = 0.008;
	win->color = 1;
	win->c_count = 1;
	win->type_f = argv[1][0] - '0';
	choose_title(win);
	get_further_par(argc, argv, win);
	win->width = win->w_width - INTX;
	win->height = win->w_height - INTY;

	//creat massive of threads in main struct
	int i = -1;
	win->threads = (t_threads *)malloc(THREADS_COUNT * sizeof(t_threads));
	while (++i < THREADS_COUNT)
	{
		win->threads[i].id = i + 1;
		win->threads[i].win = win;
	}

	return (1);
}
