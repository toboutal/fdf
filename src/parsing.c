/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:40:05 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 17:40:11 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_tab_len(char **tmp)
{
	int		x;

	x = 0;
	while (tmp[x])
		x++;
	return (x);
}

int			ft_parse_tab(t_data_map *d_m)
{
	char	**tmp;
	char	*line;

	ft_init_map(d_m);
	while (get_next_line(d_m->fd, &line))
	{
		tmp = ft_strsplit(line, 32);
		d_m->x = ft_tab_len(tmp);
		if (d_m->y == 0)
			d_m->x_max = d_m->x;
		if (d_m->y > 0 && d_m->x != d_m->x_max)
		{
			ft_putstr("error parsing x value\n");
			return (-1);
		}
		d_m->y++;
		free(line);
		ft_free_tmp(tmp);
	}
	d_m->y_max = d_m->y;
	close(d_m->fd);
	return (0);
}
