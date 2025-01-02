/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:48:38 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/03 13:53:31 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
int	main(void)
{
	int	a = 'a';
	int	b = 'b';
	
	printf ("a: %c; b: %c\n", a, b);
	ft_swap(&a, &b);
	printf ("a: %c; b: %c\n", a, b);
}