/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:41:34 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/03 15:10:30 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_nbr(int nb)
{
	char	s[10] = "0123456789";

	if (nb > 9)
		ft_print_nbr(nb /10);
	write (1, &s[nb % 10], 1);
}

int	main(void)
{
	int	i = 1;

	while (i < 101)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else if (i % 3 == 0 )
			write (1, "fizz", 4);
		else
			ft_print_nbr(i);
		write (1, "\n", 1);
		i++;
	}
}