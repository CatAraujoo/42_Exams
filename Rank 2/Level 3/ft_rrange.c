/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:01:39 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/18 09:39:26 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.*/

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int	i = 0;
	int	count = 0;
	int *list;

	if (start <= end)
	{
		i = start;
		while (i <= end)
		{
			i++;
			count++;
		}
		list = (int *)malloc(sizeof(int) * count);
		if (!list)
			return (NULL);
		count = 0;
		while (end >= start)
		{
			list[count] = end;
			count++;
			end--;
		}
	}
	else if (start > end)
	{
		i = start;
		while (i >= end)
		{
			i--;
			count++;
		}
		list = (int *)malloc(sizeof(int) * count);
		if (!list)
			return (NULL);
		count = 0;
		while (start >= end)
		{
			list[count] = start;
			count++;
			start--;
		}
	}
	return (list);
}

int	main(void)
{
	int i = 0;
	int	start = 1;
	int	end = 3;
	int *result = ft_rrange(start, end);
	if (start < end)
	{
		while(start <= end)
		{
			printf("%d\n", result[i]);
			i++;
			start++;
		}
	}
	else
	{
		while(start >= end)
		{
			printf("%d\n", result[i]);
			i++;
			start--;
		}
	}
}