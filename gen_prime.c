#include <unistd.h>
#include <stdio.h>

int ftatoi(char *str)
{
    int result;
    int i;
    int neg;

    i = 0;
    neg = 1;
    result = 0;
    if (str[i] == '-')
    {
        neg = -1;
        i++;
    }
    while (str[i])
    {
        result = (result * 10) + (str[i] - 48);
        i++;
    }
    return (result * neg); 
}

void putnbr(int nbr)
{
    char c;

    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr *= -1;
    }
    if (nbr >= 10)
    {
        putnbr(nbr / 10);
        nbr = nbr % 10;
    }
    if (nbr < 10)
    {
        c = (char)(nbr + 48);
        write(1, &c, 1);
    }
}

int isprime(int nb)
{
    int i;

    i = 2;
    if (nb <= 1)
        return (0);
    while (i < nb)
    {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}


int main(int argc, char **argv)
{
    int nb;
    int total;

    if (argc == 2)
    {
        nb = ftatoi(argv[1]);
        if (nb < 2)
            return (0);
        total = 0;
        while (nb > 0)
        {
            if (isprime(nb--))
                total += (nb + 1);
        }
        putnbr(total);
        printf("pf: %d", total);
        return (total);
    }
    return (0);
}