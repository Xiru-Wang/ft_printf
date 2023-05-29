/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:11:50 by xiwang            #+#    #+#             */
/*   Updated: 2023/05/29 17:34:27 by xiwang           ###   ########.fr       */
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

printf returns an int value of how many chars in side of the string
*/

static void	parse_args(va_list *args, char c, int *count)
{
	if (c == 's')
		ft_print_str(va_args(*args, char *), count);

	//va_arg(arg, s[i])
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned int	i;
	int				count;//count len of each args, + i, return

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	va_start(args, s);
	while(s[i])
	{
		if (s[i] == '%')
		{
			//i++;
			parse_arg(&args, s[++i], &count);
			i++;
		}
		else
		{
			putchar(s[i]);
		}
		i++;
	}
	va_end(args);
	count += i;
	return (count);
}

// int	main(void)
// {
// 	int n = printf("hello\n");
// 	printf("%d", n);//6
// 	printf("\n");

// 	int m = printf("hello %d\n", 42);
// 	printf("%d", m);//9
// 	printf("\n");

// 	int k = printf("");
// 	printf("%d", k);//0
// 	printf("\n");

// 	char *s = NULL;
// 	int f = printf(s);
// 	printf("%d", f);//cannot compile
// 	printf("\n");

// 	return (0);
// }
