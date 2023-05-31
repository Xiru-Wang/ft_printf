#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6); //? system?
		return (6);
	}
	i = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	// while (s[i])
	// 	i++;
	// write(1, s, i);
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putdigits(int n)
{
	int count;

	count = 0;
	if (n > 9)
		count += ft_putdigits(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		if (n == -2147483648)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		count += ft_putdigits(-n);
	}
	else
		count += ft_putdigits(n);

	return (count);
}

int main()
{
	int n = ft_putnbr(-42);
	printf("\n");
	printf("%d", n);
	return 0;
}
