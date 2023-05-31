/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:44:19 by xiwang            #+#    #+#             */
/*   Updated: 2023/05/31 19:55:55 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
4 bytes or 8 bytes depends on the system
unsigned long int occupies 8 bytes (64 bits) of memory.
*/

// int	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// int	ft_putstr(char *s)
// {
// 	int	i;

// 	if (s == NULL)
// 	{
// 		write(1, "(null)", 6);
// 		return (6);
// 	}
// 	i = 0;
// 	while (*s)
// 	{
// 		write(1, s, 1);
// 		s++;
// 		i++;
// 	}
// 	return (i);
// }

static int	ft_put_adr(unsigned long int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_adr(n / 16);
	if (n < 10)
		count += ft_putchar((n % 16) + '0');
	else
		count += ft_putchar((n % 16 - 10) + 'a');
	return (count);
}

int	ft_putptr(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_put_adr(n);
	return (count);
}
// "0x" prefix: the value following is in hex format

// int main()
// {
//     //int n = ft_put_adr(255);
// 	int n = ft_putptr(255);
//     printf("| digits: %d", n);

//     return 0;
// }
