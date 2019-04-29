/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:39:56 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:42:47 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int		len;

	len = 0;
	n = n < 0 ? -n : n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	long	i;
	char	*str;
	long	tmp;

	tmp = n;
	i = tmp <= 0 ? ft_count(tmp) + 1 : ft_count(tmp);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	str[0] = tmp < 0 ? '-' : '0';
	i--;
	tmp = tmp < 0 ? -tmp : tmp;
	while (tmp)
	{
		str[i] = tmp % 10 + 48;
		tmp /= 10;
		i--;
	}
	return (str);
}
