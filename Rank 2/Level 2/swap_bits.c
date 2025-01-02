/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:27:30 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/11 14:44:07 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100*/

#include <unistd.h>

unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
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

int	main(void)
{
	unsigned char p = 42;
	print_bits(p);
	write (1, "\n", 1);
	print_bits(swap_bits(p));
}