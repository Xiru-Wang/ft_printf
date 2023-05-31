#include "ft_printf.h"

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
