#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// void	ft_print_str(char *s, int *count)
// {
// 	if (s == NULL)
// 		return ;
// 	while (*s)
// 	{
// 		write(1, s, 1);
// 		(*count)++;
// 		s++;
// 	}
// }

// static void	parse_args(va_list *args, char c, int *count)
// {
// 	if (c == 'c')
// 		ft_print_char(va_arg(*args, int), count);
// 	else if (c == 's')
// 		ft_print_str(va_arg(*args, char *), count);
// }

// int	ft_printf(const char *s, ...)
// {
// 	va_list			args;
// 	unsigned int	i;//to count chars without %d/%c%s%%.....
// 	int				ret;//count len of each args, + i, return

// 	i = 0;
// 	ret = 0;
// 	if (s == 0)
// 		return (0);
// 	va_start(args, s);
// 	while(*s)
// 	{
// 		if (*s == '%')
// 		{
// 			parse_args(&args, *(++s), &ret);
// 			s++;
// 		}
// 		else
// 		{
// 			write(1, s, 1);
// 			i++;
// 		}
// 		s++;
// 	}
// 	va_end(args);
// 	ret += i;
// 	return (ret);
// }

int	main(void)
{
	//char str[] = "hiii";
	// int n = ft_printf("\\n");//handled
	// printf("%d", n);
	// int n = printf("hello\n");
	// printf("%d", n);//6
	// printf("\n");

	// int m = printf("hello %d\n", 42);
	// printf("%d", m);//9
	// printf("\n");

	// int k = printf("");
	// printf("%d", k);//0
	// printf("\n");

	// int f = printf("%%.");//%.
	// printf("%d", f);//2
	// printf("\n");

	// char str[] = "";
	// printf("%s", str);//nothing
	// printf("\n");

	int n = printf("%p", NULL);//(nil)
	printf("\n");

	return (0);
}
