/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:41:39 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:42:47 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*snew;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	snew = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (snew == NULL)
		return (NULL);
	while (s[i])
	{
		snew[i] = f(s[i]);
		i++;
	}
	snew[i] = 0;
	return (snew);
}
