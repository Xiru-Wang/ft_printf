/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:42:11 by xiwang            #+#    #+#             */
/*   Updated: 2023/05/31 19:54:40 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_put_u(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
// 1ST count: save the return value
// 2ND count: count++
