/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:39:47 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 18:08:24 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_copy_coord(t_data_i2w *d_i, t_data_i2w *d_i2w)
{
	d_i2w->x0 = d_i->x0;
	d_i2w->y0 = d_i->y0;
	d_i2w->x1 = d_i->x1;
	d_i2w->y1 = d_i->y1;
}

void			ft_gradient(t_data_i2w *d_i)
{
	if (d_i->colors.incr_grad == 1)
	{
		d_i->r += 25;
		d_i->g += 13;
	}
	else
	{
		d_i->r -= 25;
		d_i->g -= 13;
	}
}

void			ft_draw_line1(t_data_i2w *d_i, t_data_i2w *d_i2w, int xi,
				int yi)
{
	int			i;
	int			hue;

	i = 0;
	hue = d_i2w->dix / 10;
	while (i <= d_i2w->dix)
	{
		if (i == hue && d_i->colors.incr_grad > 0)
		{
			hue += d_i2w->dix / 10;
			ft_gradient(d_i);
		}
		ft_put_pixel_to_img(d_i, d_i2w->x0, d_i2w->y0);
		i++;
		d_i2w->x0 += xi;
		d_i2w->ex -= d_i2w->dy;
		if (d_i2w->ex < 0)
		{
			d_i2w->y0 += yi;
			d_i2w->ex += d_i2w->dx;
		}
	}
}

void			ft_draw_line2(t_data_i2w *d_i, t_data_i2w *d_i2w, int xi,
				int yi)
{
	int			i;
	int			hue;

	i = 0;
	hue = d_i2w->diy / 10;
	while (i <= d_i2w->diy)
	{
		if (i == hue && d_i->colors.incr_grad > 0)
		{
			hue += d_i2w->diy / 10;
			ft_gradient(d_i);
		}
		ft_put_pixel_to_img(d_i, d_i2w->x0, d_i2w->y0);
		i++;
		d_i2w->y0 += yi;
		d_i2w->ey -= d_i2w->dx;
		if (d_i2w->ey < 0)
		{
			d_i2w->x0 += xi;
			d_i2w->ey += d_i2w->dy;
		}
	}
}

void			ft_draw_line(t_data_i2w *d_i)
{
	int			xi;
	int			yi;
	t_data_i2w	d_i2w;

	ft_copy_coord(d_i, &d_i2w);
	if (d_i2w.x0 > d_i2w.x1)
		xi = -1;
	else
		xi = 1;
	if (d_i2w.y0 > d_i2w.y1)
		yi = -1;
	else
		yi = 1;
	d_i2w.ex = abs(d_i2w.x1 - d_i2w.x0);
	d_i2w.ey = abs(d_i2w.y1 - d_i2w.y0);
	d_i2w.dx = 2 * d_i2w.ex;
	d_i2w.dy = 2 * d_i2w.ey;
	d_i2w.dix = d_i2w.ex;
	d_i2w.diy = d_i2w.ey;
	if (d_i2w.dix > d_i2w.diy)
		ft_draw_line1(d_i, &d_i2w, xi, yi);
	else
		ft_draw_line2(d_i, &d_i2w, xi, yi);
}
