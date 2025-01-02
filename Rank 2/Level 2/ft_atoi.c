/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:30:10 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/05 14:54:42 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *s)
{
	int	i = 0;
	int	sign = 1;
	int	nbr = 0;
	
	while (s[i] != '\0' && s[i] >= '\a' && s[i] <= '\r' && s[i] != ' ')
		i++;
	if (s[i] != '\0')
	{
		if (s[i] != '\0' && s[i] == '-' || s[i] == '+')
		{
			if (s[i] ==  '-')
			{
				write (1, '-', 1);
				sign = -1;
			}	
		}
	}
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10 + s[i] - '0';
		i++;
	}
	return (sign * nbr);
}

/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/