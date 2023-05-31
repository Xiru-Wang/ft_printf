#include "ft_printf.h"

int	ft_put_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_put_u(n / 10);
	//this count: save the return value
	count += ft_putchar(n % 10 + '0');//this count: count++
	return (count);
}
