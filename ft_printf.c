/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:11:50 by xiwang            #+#    #+#             */
/*   Updated: 2023/05/31 16:16:44 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
https://42-cursus.gitbook.io/guide/rank-01/ft_printf/variadic-functions
1. The variadic function must have at least one mandatory argument
2. va_list: a list contains all dynamic arguments.
3. va_start( va_list var, the mandatory argument);
Its purpose is to set the stage and define which elements will be stable and which will vary.
4. va_arg:( va_list var, type_of_the_variable )
access to the arguments of the variadic function. Each time va_arg is called, you move to the next argument.
5.va_end( va_list var ): free the allocated mem

printf returns an int value of how many chars inside of the string

%[flags][width][.precision]specifier
*/

static int	parse_args(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));//va_arg无法直接接收char类型参数
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	//else if (c == 'p')
		//count += ft_put_ptr(va_arg(args, unsigned long int));//??
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_put_hex(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		count += ft_put_hex(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		count += ft_put_char('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				count;//count len of each args, + i, return

	if (s == 0)
		return (0);
	count = 0;
	va_start(args, s);
	while(*s)
	{
		if (*s == '%')
		{
			count += parse_args(args, ++s);//check specifier
			s++;//skip specifier
		}
		else
		{
			write(1, s, 1);
			count++;
		}
		s++;
	}
	va_end(args);
	return (count);
}
