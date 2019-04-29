/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:42:37 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:42:47 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_fucking_fuck(char **line, char **stk, char **recup)
{
	if (*stk)
		free(*stk);
	*stk = ft_strdup(ft_strchr(*recup, 10) + 1);
	*line = ft_strndup(*recup, ft_strlen(*recup) - ft_strlen(*stk) - 1);
	return (1);
}

int				ft_get_last_line(char **recup, char **line, char **stk)
{
	*line = ft_strdup(*recup);
	*stk = NULL;
	return (1);
}

char			*ft_strjoin_free(char *s1, char *s2)
{
	char		*new;

	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

int				ft_center(int fd, char **recup, char **line, char **stk)
{
	int			red;
	char		buf[BUFF_SIZE + 1];

	red = 0;
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[red] = 0;
		*recup = ft_strjoin_free(*recup, buf);
		if (ft_strchr(*recup, 10))
			return (ft_fucking_fuck(line, stk, recup));
	}
	if (red < 0)
		return (-1);
	if (red == 0 && red < BUFF_SIZE && ft_strlen(*recup) > 0)
		return (ft_get_last_line(recup, line, stk));
	*line = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stk[TAB_SIZE];
	char		*recup;
	int			ret;

	if (fd < 0 || !line || fd > TAB_SIZE)
		return (-1);
	recup = stk[fd] ? ft_strdup(stk[fd]) : ft_strnew(0);
	if (ft_strchr(recup, 10))
		ret = ft_fucking_fuck(line, &stk[fd], &recup);
	else
		ret = ft_center(fd, &recup, line, &stk[fd]);
	if (recup)
		free(recup);
	return (ret);
}
