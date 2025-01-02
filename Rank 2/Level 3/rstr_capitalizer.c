/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:45:50 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/12 11:51:27 by cmatos-a         ###   ########.fr       */
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
				if (argv[c][i] >= 'a' && argv[c][i] <= 'z' && argv[c][i + 1] == ' ')
					argv[c][i] -= 32;
				else if (argv[c][i] >= 'a' && argv[c][i] <= 'z' && argv[c][i + 1] == '\t')
					argv[c][i] -= 32;
				else if (argv[c][i] >= 'a' && argv[c][i] <= 'z' && argv[c][i + 1] == '\0')
					argv[c][i] -= 32;
				write (1, &argv[c][i], 1);
				i++;
			}
			write (1, "\n", 1);
			c++;
		}
	}
	else
		write (1, "\n", 1);
}

/*Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>*/
