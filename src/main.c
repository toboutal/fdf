/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:40:00 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 18:06:04 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				main(int argc, char **argv)
{
	t_data_image	d_i;
	t_data_map		d_m;

	if (argc != 2)
		ft_putstr("Input missing.\nUsage: ./fdf your_map");
	else
	{
		d_m.tab = ft_create_map(&d_i.d_m, argv[1]);
		ft_init_n(&d_i, &d_i.d_i2w);
		mlx_hook(d_i.win_ptr, 2, 3, ft_key_hook, &d_i);
		mlx_loop_hook(d_i.mlx_ptr, ft_draw, &d_i);
		mlx_loop(d_i.mlx_ptr);
	}
	return (0);
}
