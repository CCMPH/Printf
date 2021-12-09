/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 15:16:45 by chartema      #+#    #+#                 */
/*   Updated: 2021/12/07 13:28:53 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> //nodig voor va_start
#include "ft_printf.h"

int	check_conversion(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		len = ft_pointer(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		len = ft_unsignedputnbr(va_arg(args, unsigned int));
	if (c == 'x')
		len = ft_hexa(va_arg(args, unsigned int), 'x');
	if (c == 'X')
		len = ft_hexa(va_arg(args, unsigned int), 'X');
	if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len = len + check_conversion(args, format[i + 1]);
			i = i + 2;
		}
		else
		{
			ft_putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
