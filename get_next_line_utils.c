/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:07:25 by alkane            #+#    #+#             */
/*   Updated: 2022/02/22 07:39:07 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*s;
	int		total;

	total = nmemb * size;
	p = malloc(total);
	if (!p)
		return (0);
	s = p;
	while (total--)
		*s++ = '\0';
	return (p);
}

void	ft_memset(char *s,	size_t n)
{
	while (n--)
		*s++ = '\0';
}

void	ft_memmove(char *dest, char *src, size_t n)
{
	while (n--)
		*dest++ = *src++;
}

size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

int	ft_strchr(const char *s)
{
	unsigned int	i;

	i = 0;
	while (i <= (ft_strlen(s)))
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}