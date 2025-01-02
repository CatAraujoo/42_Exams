/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:56:35 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/10 10:29:28 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int	i = 0;
	int	max = tab[i];
	if (len == 0)
		return (0);
	i++;
	while (i < len)
	{
		if (max > tab[i])
		{
			i++;
		}
		else
		{
			max = tab[i];
			i++;	
		}
	}
	return (max);
}
int	main (void)
{
	unsigned int len = 6;
	int tab[] = {1, 2, 3, 8, 5, 20};
	
	printf ("%d", max(tab, len));
}

/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/