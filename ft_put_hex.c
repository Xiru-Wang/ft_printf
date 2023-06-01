/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:41:58 by xiwang            #+#    #+#             */
/*   Updated: 2023/06/01 14:36:57 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
%lx: unsigned long
%llx: unsigned long long
*/

/*int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}*/

int	ft_put_hex(unsigned int n, char x)
{
	int		count;

	count = 0;
	if (n > 15)
		count += ft_put_hex(n / 16, x);
	n = n % 16;
	if (n >= 10 && n <= 15)
	{
		if (x == 'x')
			count += ft_putchar(n - 10 + 'a');
		if (x == 'X')
			count += ft_putchar(n - 10 + 'A');
	}
	if (n <= 9)
		count += ft_putchar(n + 48);
	return (count);
}

/*static void	put_low_hex(int n)
{
	if (n == 10)
		ft_putchar('a');
	if (n == 11)
		ft_putchar('b');
	if (n == 12)
		ft_putchar('c');
	if (n == 13)
		ft_putchar('d');
	if (n == 14)
		ft_putchar('e');
	if (n == 15)
		ft_putchar('f');
}

static void	put_up_hex(int n)
{
	if (n == 10)
		ft_putchar('A');
	if (n == 11)
		ft_putchar('B');
	if (n == 12)
		ft_putchar('C');
	if (n == 13)
		ft_putchar('D');
	if (n == 14)
		ft_putchar('E');
	if (n == 15)
		ft_putchar('F');
}

int	ft_put_hex(unsigned int n, char x)
{
	int		count;

	count = 0;
	if (n > 15)
		count += ft_put_hex(n / 16, x);
	n = n % 16;
	if (n >= 10 && n <= 15)
	{
		if (x == 'x')
			put_low_hex(n);
		if (x == 'X')
			put_up_hex(n);
		count++;
	}
	if (n <= 9)
		count += ft_putchar(n + 48);
	return (count);
}

int main(void)
{
    int n =  ft_put_hex(42, 'X');
    printf("| %d", n);

    return 0;
}*/
