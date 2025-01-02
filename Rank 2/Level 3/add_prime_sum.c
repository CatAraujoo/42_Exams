/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:43:03 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/17 10:54:39 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>

int	ft_atoi(char *s);
int	is_prime(int num);
void ft_putnbr(int n);

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int nb = ft_atoi(av[1]);
		int	sum = 0;

		while (nb > 0)
		{
			if (is_prime(nb))
				sum += nb;
			nb--;
		}
	}
	if (ac != 2)
		ft_putnbr(0);
	write (1, "\n", 1);
	return (0);
}

int	ft_atoi(char *s)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if (s[i] == '-')
		return (0);
	while (s[i] != '\0')
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			return (0);
		nbr = nbr * 10;
		nbr = nbr + (s[i] - 48);
		i++;
	}
	return (nbr);
}
int	is_prime(int num)
{
	int	i = 2;

	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}
void	ft_putnbr(int n)
{
	char c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}