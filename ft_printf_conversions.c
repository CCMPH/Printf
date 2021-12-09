/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_conversions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 09:47:39 by chartema      #+#    #+#                 */
/*   Updated: 2021/12/07 13:23:20 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	number;
	int		count;

	number = n;
	count = 0;
	if (number < 0)
	{
		count = count + ft_putchar('-');
		number = number * -1;
	}
	if (number > 9)
	{
		count = count + ft_putnbr(number / 10);
		count = count + ft_putchar(number % 10 + '0');
	}
	else
	{
		count = count + ft_putchar(number + '0');
	}
	return (count);
}

int	ft_unsignedputnbr(unsigned int n)
{
	unsigned long	number;
	int				count;

	number = n;
	count = 0;
	if (number > 9)
	{
		count = count + ft_unsignedputnbr(number / 10);
		count = count + ft_putchar(number % 10 + '0');
	}
	else
	{
		count = count + ft_putchar(number + '0');
	}
	return (count);
}

int	ft_hexa(unsigned long n, char c)
{
	int				count;
	char			*line;
	char			k;

	count = 0;
	if (n >= 16)
	{
		count = count + ft_hexa((n / 16), c);
		count = count + ft_hexa((n % 16), c);
	}
	else
	{
		if (c == 'x')
			line = "0123456789abcdef";
		else
			line = "0123456789ABCDEF";
		k = line[n];
		count = count + write(1, &k, 1);
	}
	return (count);
}

int	ft_pointer(void *pointer)
{
	write(1, "0x", 2);
	return (2 + ft_hexa((unsigned long)pointer, 'x'));
}
