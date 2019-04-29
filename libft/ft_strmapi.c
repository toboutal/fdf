/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:41:41 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:42:47 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*snew;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	snew = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (snew == NULL)
		return (NULL);
	while (s[i])
	{
		snew[i] = f(i, s[i]);
		i++;
	}
	snew[i] = 0;
	return (snew);
}
