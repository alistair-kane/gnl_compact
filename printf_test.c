#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	print_s(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[count])
	{
		count += write(1, &s[count], 1);
	}
	return (count);
}

int	print_d(int	n)
{
	int		count;
	char	digit;

	count = 0;
	if (n == -214763848)
		return(write(1, &"-214763848", 10));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		count += print_d(n / 10);
	digit = n % 10 + '0';
	count += write(1, &digit, 1);
	return (count);
}

int	print_x(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += print_x(n / 16);
	count += write(1, &"0123456789abcdef"[n % 16], 1);
	return (count);
}

int	ft_printf(char *arg, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, arg);
	count = 0;
	i = -1;
	while(arg[++i])
	{
		if (arg[i] == '%')
		{
			i++;
			if (arg[i] == 'd')
				count += print_d(va_arg(ap, int));
			else if(arg[i] == 's')
				count += print_s(va_arg(ap, char *));
			else if (arg[i] == 'x')
				count += print_x(va_arg(ap, unsigned int));
		}
		else
			count += write(1, &arg[i], 1);
	}
	return (count);
}

#include <limits.h>

int main(void)
{
	ft_printf("int [%d], string[%s] hex [%x]\n", 42, "hello", 400);
	printf("int [%d], string[%s] hex [%x]\n", 2147599, "hello", 400);
	printf("%d\n", INT_MIN);
}
