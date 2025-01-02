/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:35:07 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/10 14:03:47 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i = 0;
	
	if (!s1|| !s2)
		return (0);
	while (s1)
	{
		i = 0;
		while (s2[i])
		{
		if (s2[i] == *s1)
			return ((char *) s1);
		i++;
		}
		s1++;
	}
	return (NULL);
}
int	main(void)
{
	char s1[] = "Hello";
	char s2[] = "aaoa";

	printf ("%s\n", ft_strpbrk(s1, s2));
}

/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/