/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:32:23 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/10 11:53:16 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i = 0;
	int	count = 0;

	while (*s)
	{
		while (accept[i] && *s != accept[i])
			i++;
		if (accept[i] == '\0')
			return (count);
		count++;
		s++;
	}
	return (count);
}
int	main(void)
{
	char s[] = "hello world";
	char accept[] = "hello w";

	printf ("%d\n", ft_strspn(s, accept));
}

/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/