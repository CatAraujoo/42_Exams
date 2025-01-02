/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:36:05 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/11 14:43:47 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010*/
 
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char bit;

	while (i >= 0)
	{
		bit = (octet >> i & 1) + '0';//octet na posicao i e = a 1 + '0'(converte para char)
		write(1, &bit, 1);
		i--;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int	main(void)
{
	unsigned char p = 42;
	print_bits(p);
	write (1, "\n", 1);
	print_bits(reverse_bits(42));
}

