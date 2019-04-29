/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:40:47 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 18:05:23 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define HEIGHT 1400
# define WIDTH 2575
# define SPACE 50
# define ESC 53
# define H_UP 24
# define H_DOWN 27
# define RIGHT 124
# define LEFT 123
# define UP 125
# define DOWN 126
# define GREEN 5
# define RED 15
# define YELLOW 16
# define ZOOM_IN 7
# define ZOOM_OUT 6
# define GRADIENT 17

typedef struct	s_hooks
{
	int			prof;
	int			mv_h;
	int			mv_v;
	float		zoom;
	int			grad;
	int			clr_incr;
}				t_hooks;

typedef struct	s_colors
{
	int			incr_grad;
	int			r_incr;
	int			g_incr;
	int			b_incr;
}				t_colors;

typedef struct	s_data_i2w
{
	t_hooks		hooks;
	t_colors	colors;
	char		*data_addr;
	int			bpp;
	int			bpl;
	int			endian;
	int			b;
	int			g;
	int			r;

	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			x2;
	int			y2;

	int			ex;
	int			ey;
	int			dx;
	int			dy;
	int			dix;
	int			diy;

	int			**tab;
}				t_data_i2w;

typedef struct	s_data_map
{
	int			**tab;
	int			x_max;
	int			y_max;
	int			fd;
	int			x;
	int			y;
	int			j;
}				t_data_map;

typedef struct	s_data_image
{
	t_hooks		hooks;
	t_data_map	d_m;
	t_data_i2w	d_i2w;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*title;
	int			img_to_win;
	int			space;
	int			clr;
}				t_data_image;

int				ft_parse_tab(t_data_map *d_m);
int				**ft_create_map(t_data_map *d_m, char *argv);
int				**ft_malloc(int y, int x);
int				ft_get_map(t_data_map *d_m, char *argv);
void			ft_get_make_map(t_data_map *d_m);
void			ft_init_map(t_data_map *d_m);
int				ft_manager(int **tab);
void			ft_init_n(t_data_image *d_i, t_data_i2w *d_i2w);
int				ft_pixels(t_data_image *d_i, t_data_map *d_m,
				t_data_i2w *d_i2w);
int				ft_spacing(int index);
void			ft_put_pixels(t_data_image *d_i, t_data_i2w *d_i2w, int *i_ptr,
				int *j_ptr);
void			ft_copy_coord(t_data_i2w *d_i, t_data_i2w *d_i2w);
int				ft_verify_pt(int x, int y);
void			ft_put_pixel_to_img(t_data_i2w *d_i2w, int x, int y);
void			ft_draw_line1(t_data_i2w *d_i, t_data_i2w *d_i2w, int xi,
				int yi);
void			ft_draw_line2(t_data_i2w *d_i, t_data_i2w *d_i2w, int xi,
				int yi);
int				ft_abs(int x0, int x1);
void			ft_draw_line(t_data_i2w *d_i);
int				ft_key_hook(int keycode, t_data_image *d_i);
void			ft_zoom(t_data_image *d_i, int keycode);
void			ft_crea_pts_h(t_data_image *d_i, t_data_i2w *d_i2w, int i,
				int j);
void			ft_crea_pts_v(t_data_image *d_i, t_data_i2w *d_i2w, int i,
				int j);
int				ft_tab_len(char **tmp);
void			ft_clr_grad_h(t_data_image *d_i, int i, int j);
void			ft_clr_grad_v(t_data_image *d_i, int i, int j);
void			ft_default_clr(t_data_image *d_i);
void			ft_white(t_data_image *d_i);
void			ft_dark_blue(t_data_image *d_i);
void			ft_dark_b_to_w(t_data_image *d_i);
void			ft_sel_clr(t_data_image *d_i, int keycode);
int				ft_grad_size(int index);
int				ft_draw(t_data_image *d_i);
void			ft_check_next(t_data_image *d_i, int i, int j);
void			ft_dark_b_to_w(t_data_image *d_i);
void			ft_dark_blue(t_data_image *d_i);
void			ft_commands(t_data_image *d_i);
void			ft_free_tab(t_data_image *d_i);
void			ft_free_tmp(char **tmp);
void			ft_gradient(t_data_i2w *d_i);

#endif
