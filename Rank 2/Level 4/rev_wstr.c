/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:39:56 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/19 11:18:49 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>*/

#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	c = 0;
	int	count;
	int	word_end;
	
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		i--;
		while (av[1][i] == ' ' && av[1][i] == '\t')
				i--;
		while (i >= 0)
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i--;
			word_end = i;
			while (av[1][i] >= 33 && av[1][i] <= 126)
				i--;
			count = i + 1;
			while (i <= word_end)
			{
				if (av[1][i] != ' ' && av[1][i] != '\t')
					write(1, &av[1][i], 1);
				i++;
			}
			if (count == 0 || i == 0)
				break ;
			i = count;
			write (1, " ", 1);
			i--;
		}
	}
	write (1, "\n", 1);
}