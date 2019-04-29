/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:39:57 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 17:40:11 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_spacing(int index)
{
	int		spacing;

	spacing = 0;
	spacing += (SPACE * index);
	return (spacing);
}

void		ft_crea_pts_h(t_data_image *d_i, t_data_i2w *d_i2w, int i, int j)
{
	if (j + 1 < d_i->d_m.x_max)
	{
		if (d_i->hooks.grad == 1)
			ft_clr_grad_h(d_i, i, j);
		d_i2w->x0 = ((WIDTH / 2) - d_i->d_m.x_max / 2 * SPACE) \
				+ (ft_spacing(j) * d_i->hooks.zoom) + (d_i->hooks.mv_h * SPACE)
				- (d_i->d_m.tab[i][j] * d_i->hooks.prof);
		d_i2w->y0 = ((HEIGHT / 2) - d_i->d_m.y_max / 2 * SPACE) \
		+ (ft_spacing(i) * d_i->hooks.zoom) + (d_i->hooks.mv_v * SPACE)
		- (d_i->d_m.tab[i][j] * d_i->hooks.prof);
		d_i2w->x1 = ((WIDTH / 2) - d_i->d_m.x_max / 2 * SPACE) \
		+ (ft_spacing(j + 1) * d_i->hooks.zoom) + (d_i->hooks.mv_h * SPACE)
		- (d_i->d_m.tab[i][j + 1] * d_i->hooks.prof);
		d_i2w->y1 = ((HEIGHT / 2) - d_i->d_m.y_max / 2 * SPACE) \
		+ (ft_spacing(i) * d_i->hooks.zoom) + (d_i->hooks.mv_v * SPACE)
		- (d_i->d_m.tab[i][j + 1] * d_i->hooks.prof);
		ft_draw_line(d_i2w);
	}
}

void		ft_crea_pts_v(t_data_image *d_i, t_data_i2w *d_i2w, int i, int j)
{
	if (i + 1 < d_i->d_m.y_max)
	{
		if (d_i->hooks.grad == 1)
			ft_clr_grad_v(d_i, i, j);
		d_i2w->x0 = ((WIDTH / 2) - d_i->d_m.x_max / 2 * SPACE)
			+ (ft_spacing(j) * d_i->hooks.zoom) + (d_i->hooks.mv_h * SPACE)
			- (d_i->d_m.tab[i][j] * d_i->hooks.prof);
		d_i2w->y0 = ((HEIGHT / 2) - d_i->d_m.y_max / 2 * SPACE)
			+ (ft_spacing(i) * d_i->hooks.zoom) + (d_i->hooks.mv_v * SPACE)
			- (d_i->d_m.tab[i][j] * d_i->hooks.prof);
		d_i2w->x1 = ((WIDTH / 2) - d_i->d_m.x_max / 2 * SPACE)
			+ (ft_spacing(j) * d_i->hooks.zoom) + (d_i->hooks.mv_h * SPACE)
			- (d_i->d_m.tab[i + 1][j] * d_i->hooks.prof);
		d_i2w->y1 = ((HEIGHT / 2) - d_i->d_m.y_max / 2 * SPACE)
			+ (ft_spacing(i + 1) * d_i->hooks.zoom) + (d_i->hooks.mv_v * SPACE)
			- (d_i->d_m.tab[i + 1][j] * d_i->hooks.prof);
		ft_draw_line(d_i2w);
	}
}

int			ft_pixels(t_data_image *d_i, t_data_map *d_m, t_data_i2w *d_i2w)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < d_m->y_max)
	{
		while (j < d_m->x_max)
		{
			ft_crea_pts_h(d_i, d_i2w, i, j);
			ft_crea_pts_v(d_i, d_i2w, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void		ft_init_n(t_data_image *d_i, t_data_i2w *d_i2w)
{
	ft_default_clr(d_i);
	d_i->title = "FDF by Toboutal";
	d_i->mlx_ptr = mlx_init();
	d_i->win_ptr = mlx_new_window(d_i->mlx_ptr, WIDTH, HEIGHT, d_i->title);
	d_i->img_ptr = mlx_new_image(d_i->mlx_ptr, WIDTH, HEIGHT);
	d_i2w->data_addr =
	mlx_get_data_addr(d_i->img_ptr, &d_i2w->bpp, &d_i2w->bpl, &d_i2w->endian);
	d_i->d_i2w.ex = 0;
	d_i->d_i2w.ey = 0;
	d_i->hooks.prof = 1;
	d_i->hooks.mv_h = 1;
	d_i->hooks.mv_v = -1;
	d_i->hooks.zoom = 1;
	d_i->hooks.grad = 0;
	d_i2w->colors.incr_grad = 0;
	d_i->hooks.clr_incr = 0;
}
