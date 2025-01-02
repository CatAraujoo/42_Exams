/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:34:08 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/12/18 11:30:29 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);*/

int	ft_atoi_base(const char *str, int str_base)
{
	int	n = 0;
	int	i = 0;;
	int sign = 1;
	int	digit;

	if (str_base < 2 || str_base > 16)
		return (0);
	while (str[i] == 32 || str[i] >= '\t' && str[i] <= '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	digit = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit == str[i] - '0';
		if (str[i] >= 'a' && str[i] <= 'f')
			digit == str[i] - 'a' + 10;
		if (str[i] >= 'A' && str[i] <= 'F')
			digit == str[i] - 'A' + 10;
		else
			break ;
		if (digit >= str_base)
			break ;
		n = n * str_base + digit; 
		i++; 
	}
	return (n * sign);
}