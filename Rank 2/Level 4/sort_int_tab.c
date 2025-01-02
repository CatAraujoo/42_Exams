/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:38:45 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/19 13:43:38 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.*/

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j;
	int temp;

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	arr[10] = {1, 7, 2, 15, 5};
	unsigned int	i = 0;
	unsigned int	size = 5;
	
	sort_int_tab(arr, size);
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}