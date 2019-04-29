/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:39:42 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 17:40:11 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_verify_pt(int x, int y)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
		return (1);
	else
		return (0);
}

void		ft_clr_grad_h(t_data_image *d_i, int i, int j)
{
	d_i->d_i2w.colors.incr_grad = 0;
	if (d_i->d_m.tab[i][j] == 0)
	{
		if (d_i->d_m.tab[i][j + 1] == 0)
			ft_dark_blue(d_i);
		else
		{
			d_i->d_i2w.colors.incr_grad = 1;
			ft_dark_blue(d_i);
		}
	}
	else
	{
		if (d_i->d_m.tab[i][j + 1] == 0)
		{
			d_i->d_i2w.colors.incr_grad = 2;
			ft_white(d_i);
		}
		else
			ft_white(d_i);
	}
}

void		ft_clr_grad_v(t_data_image *d_i, int i, int j)
{
	d_i->d_i2w.colors.incr_grad = 0;
	if (d_i->d_m.tab[i][j] == 0)
	{
		if (d_i->d_m.tab[i + 1][j] == 0)
			ft_dark_blue(d_i);
		else
		{
			d_i->d_i2w.colors.incr_grad = 1;
			ft_dark_blue(d_i);
		}
	}
	else
	{
		if (d_i->d_m.tab[i + 1][j] == 0)
		{
			d_i->d_i2w.colors.incr_grad = 2;
			ft_white(d_i);
		}
		else
			ft_white(d_i);
	}
}

void		ft_put_pixel_to_img(t_data_i2w *d_i2w, int x, int y)
{
	if (ft_verify_pt(x, y) == 1)
	{
		d_i2w->data_addr[(y * d_i2w->bpl + x * d_i2w->bpp / 8)] = d_i2w->b;
		d_i2w->data_addr[(y * d_i2w->bpl + x * d_i2w->bpp / 8) + 1] = d_i2w->g;
		d_i2w->data_addr[(y * d_i2w->bpl + x * d_i2w->bpp / 8) + 2] = d_i2w->r;
	}
}
