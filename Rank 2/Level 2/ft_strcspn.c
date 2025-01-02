/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:26 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/10 12:22:17 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i = 0;
	int	count = 0;

	while (*s)
	{
		i = 0;
		while (reject[i])
		{
			if (reject[i] == *s)
				return (count);
			i++;
		}
		count++;
		s++;
	}
	return (count);
}
int	main(void)
{
	char s[] = "hello world";
	char accept[] = "eaaaa12";

	printf ("%d\n", ft_strcspn(s, accept));
	printf ("%d\n", strcspn(s, accept));
}

/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/