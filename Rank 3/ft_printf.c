/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:11:31 by catarina          #+#    #+#             */
/*   Updated: 2025/03/13 23:51:23 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *str)
{
	int len = 0;
	
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_putnbr(long nbr, int base)
{
	char *hex = "0123456789abcdef";
	int len = 0;
	unsigned int temp = 0;
	if (nbr < 0 && base == 10)
	{
		len += write(1, "-", 1);
		temp = -nbr;
	}
	else
		temp = (unsigned int)nbr;
	if (temp >= (unsigned int)base)
		len += ft_putnbr((temp / base), base);
	len += write(1, &hex[temp % base], 1);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if ((*fmt == '%') && (*(fmt + 1) != '\0'))
		{
			fmt++;
			if (*fmt == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (*fmt == 'd')
				len += ft_putnbr(va_arg(args, int), 10);
			else if (*fmt == 'x')
				len += ft_putnbr(va_arg(args, int), 16);
			else if (*fmt == '%')
				len += write(1, "%", 1);
		}
		else
			len += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int mycount = 0;
	int origcount = 0;

	mycount = ft_printf("%s\n", "toto");
	origcount = printf("%s\n", "toto");
	ft_printf("mycount: %d\n", mycount);
	printf("origcount: %d\n", origcount);
	mycount = ft_printf("Magic %s is %d\n", "number", 42);
	origcount = printf("Magic %s is %d\n", "number", 42);
	ft_printf("mycount: %d\n", mycount);
	printf("origcount: %d\n", origcount);
	mycount = ft_printf("Hexadecimal for %d is %x\n", 42, -42);
	origcount = printf("Hexadecimal for %d is %x\n", 42, -42);
	ft_printf("mycount: %d\n", mycount);
	printf("origcount: %d\n", origcount);
	mycount = ft_printf("Hexadecimal for negative %d is %x\n", -42, -42);
	origcount = printf("Hexadecimal for negative %d is %x\n", -42, -42);
	ft_printf("mycount: %d\n", mycount);
	printf("origcount: %d\n", origcount);
	
	return (0);
}*/
