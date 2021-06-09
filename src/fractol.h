#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <time.h>

# define WIDTH 1200
# define HEGHT 1000
# define W 4
# define NUM 40
# define PX -0.5
# define PY 0
# define ZOOM 0.9

# define INTY 60
# define INTX 0
# define OBV_DARK 0x787878
# define OBV_LIGHT 0xF0F0F0

# define MAPX 200
# define MAPY 5
# define MW 100
# define MH 50
# define MAPNUM 15

# define COLORS_MAX 6

# define NMAX 10000000000000
# define NMIN 0.0000000000001

typedef struct s_interf
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_interf;

typedef struct s_comp
{
	double	x;
	double	y;
}	t_comp;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		end;
}	t_img;

typedef struct s_win
{
	void	*win;
	void	*mlx;
	t_img	img;
	int		width;
	int		height;
	int		w_width;
	int		w_height;
	char	type_f;
	double	px;
	double	py;
	double	w;
	int		num;
	char	*title;
	double	jx;
	double	jy;
	int		color;
	int		c_count;
	int		h_key;
}	t_win;

int		parc_param(int argc, char **argv, t_win *win);
double	find_cx(int i, t_win win);
double	find_cy(int j, t_win win);
int		find_d(double cx, double cy, int num);
int		find_d_julia(double cx, double cy, t_win win);
int		find_d_newton (double cx, double cy, t_win win);
int		find_d_maldbar(double cx, double cy, t_win win);
int		find_d_b_ship(double cx, double cy, t_win win);
int		find_d_c_mald(double cx, double cy, t_win win);

int		get_keyboard(int key, t_win *win);
int		get_mouse(int key, int x, int y, t_win *win);
int		move_mouse(int x, int y, t_win *win);

int		draw_f(int key, t_win *win);
void	draw_int(t_win *win);
void	ft_print_data(t_win *win);
void	print_hint(t_win *win, int i, int j);
void	put_hints(t_win *win, int i, int j);

void	ft_draw_minimap(int i, int j, t_win *win);
void	ft_draw_mini(int i, int j, t_win *win);

void	get_d(t_win *win, int i, int j, int d);
int		get_trgb(int t, int r, int g, int b);
int		get_c_by_d(int d, int num, int c, int c_count);

int		ft_close_p(t_win *win);
int		terminate(char *s, int n);

#endif
