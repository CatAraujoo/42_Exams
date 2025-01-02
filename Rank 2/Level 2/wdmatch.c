/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:28:54 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/11 11:57:34 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	a = 0;
	int	b = 0;
	int	c = 0;
	int	len = 0;
	char s[256] = {0};

	while (argv[1][len] != '\0')
		len++;
	while (argv[1][a] != '\0')
	{
		while (argv[2][b] != '\0')
		{
			if (argv[1][a] == argv[2][b])
			{	
				s[c] = argv[1][a];
				c++;
				b++;
				break ;
			}
			b++;
		}
		a++;
	}
	if (len == c)
	{
		c = 0;
		while (s[c] != '\0')
		{
			write (1, &s[c], 1);
			c++;
		}
	}
	write (1, "\n", 1);
}

/*Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat -e
forty two$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$*/