/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:42:13 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:42:47 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			w++;
		}
		else
			i++;
	}
	return (w);
}

static char	**pegasus(char **tab, char const *s, char c)
{
	int			i;
	int			start;
	int			l;
	int			j;

	j = 0;
	i = 0;
	l = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			l = 0;
			while (s[i] != c && s[i])
			{
				l++;
				i++;
			}
			tab[j++] = ft_strsub(s, start, l);
		}
		else
			i++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;

	if (s == NULL)
		return (NULL);
	i = ft_word_count(s, c);
	tab = malloc(sizeof(char *) * (i + 1));
	if (tab == NULL)
		return (NULL);
	tab[i] = 0;
	tab = pegasus(tab, s, c);
	return (tab);
}
