/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:01 by xiwang            #+#    #+#             */
/*   Updated: 2023/05/31 16:22:17 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
//# include <stdio.h>
//# include <stdlib.h>
# include <unistd.h>

int ft_printf(const char *s, ...);
int ft_putchar(char c);
int	ft_putstr(char *);
int ft_putnbr(int n);
int ft_put_u(unsigned int n);
int ft_put_hex(unsigned int n, char x);
int ft_putptr(unsigned long int);//data type!

#endif
