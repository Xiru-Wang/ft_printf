/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:11:50 by xiwang            #+#    #+#             */
/*   Updated: 2023/06/04 17:48:54 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
https://42-cursus.gitbook.io/guide/rank-01/ft_printf/variadic-functions
1. The variadic function must have at least one mandatory argument
2. va_list: a list contains all dynamic arguments.
3. va_start( va_list var, the mandatory argument);
set the stage and define which elements will be stable and which will vary.
4. va_arg:( va_list var, type_of_the_variable )
access to the arguments of the variadic function.
Each time va_arg is called, you move to the next argument.
5.va_end( va_list var ): free the allocated mem

printf returns an int value of how many chars inside of the string

%[flags][width][.precision]specifier
va_arg does not take char!
*/

static int	parse_args(va_list args, const char *s)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*s == 'p')
		count += ft_putptr(va_arg(args, unsigned long int));
	else if (*s == 'd' || *s == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*s == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	else if (*s == 'x')
		count += ft_put_hex(va_arg(args, unsigned int), 'x');
	else if (*s == 'X')
		count += ft_put_hex(va_arg(args, unsigned int), 'X');
	else if (*s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				count;

	if (s == 0)
		return (0);
	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			count += parse_args(args, ++s);
			s++;
		}
		else
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}

// int	main()
// {
// 	int n = ft_printf(" %c ", '0');
// 	printf("|%d", n);
// 	return 0;
// }
