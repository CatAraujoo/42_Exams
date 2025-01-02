/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:25:04 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/19 14:47:18 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <stdlib.h>
#include <stdio.h>

int nlen(int nbr)
{
	int	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

long ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_itoa(int nbr)
{
	int	dig = nlen(nbr);
	char *s;

	s = (char *)malloc(sizeof(char) * (dig + 1));
	if (!s)
		return (NULL);
	if (nbr == 0)
		s[0] = '0';
	if (nbr < 0)
		s[0] = '-';
	s[dig] = '\0';
	dig--;
	while (nbr)
	{
		s[dig] = ft_abs(nbr % 10) + '0';
		nbr = nbr / 10;
		dig--;
	}
	return (s);
}
int main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}