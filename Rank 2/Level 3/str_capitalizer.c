/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:05:09 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/12 11:41:30 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	c = 1;
	int	i = 0;
	if (argc >= 2)
	{
		while (c < argc)
		{
			i = 0;
			while (argv[c][i] != '\0')
			{
				if (argv[c][i] >= 'A' && argv[c][i] <= 'Z')
					argv[c][i] += 32;
				i++;
			}
			c++;
		}
		c = 1;
		i = 0;
		while (c < argc)
		{
			i = 0;
			while (argv[c][i] != '\0')
			{
				if (argv[c][i] >= 'a' && argv[c][i] <= 'z' && argv[c][i - 1] >= 91 && argv[c][i - 1] <= 96 && argv[c][i - 1] >= 123 && argv[c][i - 1] <= 126)
					argv[c][i] -= 32;
				else if (argv[c][i] >= 'a' && argv[c][i] <= 'z' && argv[c][i - 1] >= ' ' && argv[c][i - 1] <= '@')
					argv[c][i] -= 32;
				write (1, &argv[c][i], 1);
				i++;
			}
			write (1, "\n", 1);
			c++;
		}
	}
	write (1, "\n", 1);
}

/*Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>*/