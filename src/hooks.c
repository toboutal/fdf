/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:39:54 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 18:07:34 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_zoom(t_data_image *d_i, int keycode)
{
	if (keycode == ZOOM_IN)
		d_i->hooks.zoom *= 1.1;
	else
		d_i->hooks.zoom *= 0.9;
}

int		ft_key_hook(int keycode, t_data_image *d_i)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(d_i->mlx_ptr, d_i->img_ptr);
		ft_free_tab(d_i);
		exit(0);
	}
	if (keycode == H_UP || keycode == H_DOWN)
		keycode == H_UP ? d_i->hooks.prof++ : d_i->hooks.prof--;
	if (keycode == RIGHT || keycode == LEFT)
		keycode == RIGHT ? d_i->hooks.mv_h++ : d_i->hooks.mv_h--;
	if (keycode == UP || keycode == DOWN)
		keycode == UP ? d_i->hooks.mv_v++ : d_i->hooks.mv_v--;
	if (keycode == RED || keycode == GREEN || keycode == YELLOW)
		ft_sel_clr(d_i, keycode);
	if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		ft_zoom(d_i, keycode);
	if (keycode == GRADIENT)
		d_i->hooks.grad = d_i->hooks.grad == 1 ? 0 : 1;
	return (-1);
}

void	ft_commands(t_data_image *d_i)
{
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 50, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 70, 0xFFFFFF,
			"Move = ^ v < >");
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 90, 0xFFFFFF,
			"Zoom = x (up) z (down)");
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 110, 0xFFFFFF,
			"Depth = + (up) - (down)");
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 130, 0xFFFFFF, "Colors:");
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 150, 0xFFFFFF, "Red = R");
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 170, 0xFFFFFF, "Green = G");
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 190, 0xFFFFFF,
			"Yellow = Y");
	mlx_string_put(d_i->mlx_ptr, d_i->win_ptr, 50, 210, 0xFFFFFF,
			"Gradient = T (switches gradient to mono colors)");
}

int		ft_draw(t_data_image *d_i)
{
	ft_bzero(d_i->d_i2w.data_addr, (WIDTH * HEIGHT * 4));
	ft_pixels(d_i, &d_i->d_m, &d_i->d_i2w);
	mlx_put_image_to_window(d_i->mlx_ptr, d_i->win_ptr, d_i->img_ptr, 0, 0);
	ft_commands(d_i);
	return (0);
}
