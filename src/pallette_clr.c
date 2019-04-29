/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pallette_clr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:40:03 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 17:40:11 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_default_clr(t_data_image *d_i)
{
	d_i->d_i2w.r = 77;
	d_i->d_i2w.g = 184;
	d_i->d_i2w.b = 255;
}

void		ft_white(t_data_image *d_i)
{
	d_i->d_i2w.r = 255;
	d_i->d_i2w.g = 255;
	d_i->d_i2w.b = 255;
}

void		ft_dark_blue(t_data_image *d_i)
{
	d_i->d_i2w.b = 255;
	d_i->d_i2w.g = 120;
	d_i->d_i2w.r = 0;
}

void		ft_dark_b_to_w(t_data_image *d_i)
{
	d_i->d_i2w.colors.r_incr = 14;
	d_i->d_i2w.colors.g_incr = 26;
	if (d_i->d_i2w.r + d_i->d_i2w.colors.r_incr > 255)
		d_i->d_i2w.r = 255;
	if (d_i->d_i2w.g + d_i->d_i2w.colors.g_incr > 255)
		d_i->d_i2w.g = 255;
	else
	{
		d_i->d_i2w.r += d_i->d_i2w.colors.r_incr;
		d_i->d_i2w.g += d_i->d_i2w.colors.g_incr;
	}
}

void		ft_sel_clr(t_data_image *d_i, int keycode)
{
	if (keycode == GREEN)
	{
		d_i->d_i2w.b = 4;
		d_i->d_i2w.g = 250;
		d_i->d_i2w.r = 47;
	}
	if (keycode == RED)
	{
		d_i->d_i2w.b = 4;
		d_i->d_i2w.g = 47;
		d_i->d_i2w.r = 250;
	}
	if (keycode == YELLOW)
	{
		d_i->d_i2w.b = 4;
		d_i->d_i2w.g = 230;
		d_i->d_i2w.r = 250;
	}
}
