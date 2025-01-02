/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:43:21 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/17 15:04:04 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int i = 0;
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
		list = (int *)malloc(sizeof(int) * (count));
		if (!list)
			return (NULL);
		count = 0;
		while (start <= end)
		{
			list[count] = start;
			count++;
			start++;
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
		list = (int *)malloc(sizeof(int) * (count));
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
	int	start = 10;
	int	end = 2;
	int *result = ft_range(start, end);
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