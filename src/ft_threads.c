//this file contains function for working by threads
//function fill peace of image that depends on THREADS_COUNT value and id of thread struct
//you can change count of threads by changing THREADS_COUNT value in "fractol.h"
#include "fractol.h"


void	*ft_fill_img_all_thr(void *t)
{
	t_win 		*win;
	t_threads	*thr;
	int i;
	int j;
	int d;
	int	x;
	int	y;
	int	del;

	thr = (t_threads *)t;
	win = thr->win;
	del = win->width / THREADS_COUNT;
	j = INTY - 1;
	while (++j < win->w_height)
	{
		y = j - INTY;
		i = INTX - 1 + del * (thr->id - 1);
		while (++i < del * thr->id)
		{
			x = i - INTX;
			if (win->type_f == 1)
			{				
				d = find_d (find_cx (x, *win), find_cy (y, *win), win->num);
			}
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
			win->img.data[j * win->w_width + i] = get_c_by_d(d, win->num, win->color, win->c_count);
		}
	}
	
	return ((void *)0);
}
