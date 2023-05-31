#include <unistd.h>
#include <stdio.h>

void my_put_nbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "214748364", 9);
			write(1, "8", 1);
		}
		n = -n;
	}
	if ( n > 9)
		my_put_nbr(n / 10);
	putchar(n % 10 + 48);
}

int main(void)
{
	my_put_nbr(42);

	return 0;
}
