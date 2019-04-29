/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcasestr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:41:01 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:42:47 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*haycpy;
	char	*needcpy;

	i = 0;
	j = 0;
	haycpy = ft_strtolower((char *)haystack);
	needcpy = ft_strtolower((char *)needle);
	while (haystack[i])
	{
		j = 0;
		while (haycpy[i] == needcpy[j])
		{
			i++;
			j++;
			if (needcpy[j] == 0)
				return (((char *)haycpy) + (i - j));
		}
		i = (i - j);
		i++;
	}
	return (NULL);
}
