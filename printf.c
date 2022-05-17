#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printx(unsigned int n)
{
	int	rez;
	int	digit;

	rez = 0;
	digit = 0;
	if (n >= 16)
		rez += ft_printx(n / 16);
	digit = n % 16;
	rez += write(1, &"0123456789abcdef"[digit], 1);
	return (rez);
}

int	ft_printstr(char *s)
{
	int	i;
	int	rez;

	i = 0;
	rez = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		rez += write(1, &s[i], 1);
		i++;
	}
	return (rez);
}

int	ft_printdi(int n)
{
	int		rez;
	char	digit;

	rez = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			rez += write(1, "-", 1);
			n = n * -1;
		}
		if (n > 9)
			rez += ft_printdi(n / 10);
		digit = n % 10 + '0';
		rez += write(1, &digit, 1);
	}
	return (rez);
}

int	conversion(const char *s, int i, va_list args)
{
	int	rez;

	rez = 0;
	if (s[i] == 's')
		rez += ft_printstr(va_arg(args, char *));
	else if (s[i] == 'd')
		rez += ft_printdi(va_arg(args, int));
	else if (s[i] == 'x')
		rez += ft_printx(va_arg(args, unsigned int));
	return (rez);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		rez;
	va_list	args;

	i = 0;
	rez = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			rez += conversion(s, i, args);
		}
		else
			rez += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (rez);
}

int main()
{
    ft_printf("%s, %d, %x\n", "Hello", 42, 400);
    printf("%s, %d, %x\n", "Hello", 42, 400);
}
