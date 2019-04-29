/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:42:41 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:42:47 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define TAB_SIZE 5000
# include "libft.h"

int		ft_fucking_fuck(char **line, char **stk, char **recup);
int		ft_get_last_line(char **recup, char **line, char **stk);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_center(int fd, char **recup, char **line, char **stk);
int		get_next_line(const int fd, char **line);

#endif
