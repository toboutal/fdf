/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_data.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 17:39:52 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 17:40:11 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			**ft_malloc_tab(int y, int x)
{
	int		i;
	int		**tab;

	i = 0;
	tab = malloc(sizeof(int *) * y);
	if (tab == NULL)
		ft_putstr("error malloc tab");
	while (i < y)
	{
		tab[i] = malloc(sizeof(int) * x);
		if (tab[i] == NULL)
			ft_putstr("malloc error");
		i++;
	}
	return (tab);
}

void		ft_init_map(t_data_map *d_m)
{
	d_m->x = 0;
	d_m->y = 0;
	d_m->j = 0;
}

void		ft_make_map(t_data_map *d_m)
{
	char	*line;
	char	**tmp;

	ft_init_map(d_m);
	while (get_next_line(d_m->fd, &line))
	{
		tmp = ft_strsplit(line, 32);
		d_m->x = 0;
		while (d_m->x < d_m->x_max)
		{
			d_m->tab[d_m->y][d_m->x] = ft_atoi(tmp[d_m->x]);
			d_m->x++;
		}
		d_m->y++;
		free(line);
		while (tmp[d_m->j])
		{
			free(tmp[d_m->j]);
			d_m->j++;
		}
		d_m->j = 0;
		free(tmp);
	}
}

int			ft_get_map(t_data_map *d_m, char *argv)
{
	d_m->tab = ft_malloc_tab(d_m->y_max, d_m->x_max);
	d_m->fd = open(argv, O_RDONLY);
	ft_make_map(d_m);
	close(d_m->fd);
	return (0);
}

int			**ft_create_map(t_data_map *d_m, char *argv)
{
	d_m->fd = open(argv, O_RDONLY);
	if (ft_parse_tab(d_m) == -1)
		ft_putstr("tab malloc error");
	else
		ft_get_map(d_m, argv);
	return (d_m->tab);
}
