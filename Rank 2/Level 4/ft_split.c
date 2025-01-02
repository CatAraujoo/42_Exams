/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:38:29 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/19 12:32:09 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/

#include <stdlib.h>
#include <stdio.h>

int	count_words(const char *str, char sep)
{
	int	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
			count++;
		while (*str && *str != sep)
			str++;
	}
	return (count);
}

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	char sep = ' ';
	char **new_array;
	int	words = count_words(str, sep);
	int	end = 0;
	int start = 0;
	int n = 0;
		
	if (!str)
		return (NULL);
	new_array = malloc (sizeof(char *) * (words + 1));
	if (!new_array)
		return (NULL);
	while (str[end])
	{
		while (str[end] && str[end] == sep)
			end++;
		start = end;
		while (str[end] && str[end] != sep)
			end++;
		if (end > start)
		{
			new_array[n] = malloc(sizeof(char) * ((end - start) + 1));
			ft_strncpy(new_array[n++], &str[start], end - start);
		}	
	}
		new_array[n] = '\0';
		return (new_array);
}

int	main(void)
{
	char	*str;
	char	**result;
	int	i;
	
	str = "three words apart";
	result = ft_split(str);
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}