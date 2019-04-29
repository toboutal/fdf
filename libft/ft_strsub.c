/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:42:20 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:42:47 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*snew;

	i = 0;
	if (s == NULL)
		return (NULL);
	snew = malloc(sizeof(char) * (len + 1));
	if (snew == NULL)
		return (NULL);
	while (i < len)
	{
		snew[i] = s[start];
		i++;
		start++;
	}
	snew[i] = 0;
	return (snew);
}
