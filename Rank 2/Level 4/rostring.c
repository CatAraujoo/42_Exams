/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:00 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/19 11:21:25 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring | cat -e
$
$>*/

#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	t = 0;
	char *temp;
	if (ac > 1)
	{
		while (av[1][i])
			i++;
		temp = (char *)malloc(sizeof(char) * i + 1);
		i = 0;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i] >= 33 && av[1][i] <= 126)
		{	
			temp[t] = av[1][i];
			t++;
			i++;
		}
		temp[t] = '\0';
		while (av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			while (av[1][i] >= 33 && av[1][i] <= 126)
			{
				write (1, &av[1][i], 1);
				i++;
			}
			write (1, " ", 1);
		}
		t = 0;
		while (temp[t])
		{
			write (1, &temp[t], 1);
			t++;
		}
		free(temp);
	}
	write (1, "\n", 1);
}