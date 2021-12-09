/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 09:36:53 by chartema      #+#    #+#                 */
/*   Updated: 2021/12/07 13:22:57 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_unsignedputnbr(unsigned int n);
int	ft_hexa(unsigned long n, char c);
int	ft_pointer(void *pointer);
int	ft_printf(const char *format, ...);

#endif